#include "square.h"

namespace cphong { namespace shapes {

    Square::Square(const maths::vec2& size, const maths::vec3& position, const maths::vec4& color)
        : m_size(size), m_position(position), m_color(color)
    {
        prepare();
    }

    void Square::prepare()
    {
        const GLfloat vertices[] =
        {
            //vertex                    color
            0.0f,     0.0f,     0.0f,   m_color.x, m_color.y, m_color.z, m_color.w,
            m_size.x, 0.0f,     0.0f,   m_color.x, m_color.y, m_color.z, m_color.w,
            m_size.x, m_size.y, 0.0f,   m_color.x, m_color.y, m_color.z, m_color.w,
            0.0f,     m_size.y, 0.0f,   m_color.x, m_color.y, m_color.z, m_color.w
        };

        const GLushort indices[] =
        {
            0, 1, 2,
            2, 3, 0
        };

        m_vertexBuffer = new graphics::VertexBuffer(sizeof(vertices), vertices);
        
        m_vertexArray = new graphics::VertexArray();
        m_vertexArray->setVertexAttribPointer(m_vertexBuffer, 0, 3, 7 * sizeof(GLfloat), (void*)0);
        m_vertexArray->setVertexAttribPointer(m_vertexBuffer, 1, 4, 7 * sizeof(GLfloat), (void*)(4 * sizeof(GLfloat)));
        
        m_indexBuffer = new graphics::IndexBuffer(6, indices);
        
        m_shader = new graphics::Shader("resource/shaders/square.vert", "resource/shaders/square.frag");
        m_shader->use();
        maths::mat4 model = maths::mat4::translate(m_position);
        maths::mat4 view = maths::mat4::identity();
        maths::mat4 projection = maths::mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 10.0f);
        m_shader->passingUniform("model", model);
        m_shader->passingUniform("view", view);
        m_shader->passingUniform("projection", projection);
        m_shader->unuse();
    }

} }