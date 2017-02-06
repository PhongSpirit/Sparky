#pragma once

#include <GL/glew.h>

namespace cphong { namespace graphics {

    class VertexBuffer
    {
    private:
        GLuint m_id;
    public:
        VertexBuffer(GLsizeiptr size, const GLfloat* data);
        ~VertexBuffer();

        void bind() const;
        void unbind() const;
    };

} }