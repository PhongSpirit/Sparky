#pragma once

#include <GL/glew.h>

namespace cphong { namespace graphics {

    class IndexBuffer
    {
    private:
        GLuint m_id;

        GLuint m_count;
    public:
        IndexBuffer(GLuint count, const GLushort* data);
        ~IndexBuffer();

        GLuint getCount() const;
        
        void bind() const;
        void unbind() const;
    };

} }