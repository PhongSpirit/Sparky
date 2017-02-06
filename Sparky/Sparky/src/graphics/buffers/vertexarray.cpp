#include "vertexarray.h"

namespace cphong { namespace graphics {

    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &m_id);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &m_id);
    }

    void VertexArray::bind() const
    {
        glBindVertexArray(m_id);
    }

    void VertexArray::unbind() const
    {
        glBindVertexArray(0);
    }

    void VertexArray::setVertexAttribPointer(VertexBuffer* buffer, GLuint index, GLint size, GLsizei stride, const void* pointer)
    {
        bind();
        buffer->bind();

        glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, pointer);
        glEnableVertexAttribArray(index);

        buffer->unbind();
        unbind();
    }

} }