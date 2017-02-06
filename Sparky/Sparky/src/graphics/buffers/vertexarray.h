#pragma once

#include <GL/glew.h>

#include "vertexbuffer.h"

namespace cphong { namespace graphics {

    class VertexArray
    {
    private:
        GLuint m_id;
    public:
        VertexArray();
        ~VertexArray();

        void bind() const;
        void unbind() const;

        void setVertexAttribPointer(VertexBuffer* buffer, GLuint index, GLint size, GLsizei stride, const void* pointer);
    };

} }