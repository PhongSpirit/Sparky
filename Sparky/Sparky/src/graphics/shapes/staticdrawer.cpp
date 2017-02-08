#include "staticdrawer.h"

namespace cphong { namespace graphics {

    StaticDrawer::StaticDrawer(const Drawable* drawable) : m_drawable(drawable)
    {
        init();
    }

    StaticDrawer::~StaticDrawer()
    {
        delete m_shader;
        delete m_vertexArray;
        delete m_indexBuffer;
        delete m_vertexBuffer;
    }

    const Shader* StaticDrawer::getShader() const
    {
        return m_shader;
    }

    void StaticDrawer::enable() const
    {
        m_vertexArray->bind();
        m_indexBuffer->bind();
        m_shader->use();
    }

    void StaticDrawer::disable() const
    {
        m_shader->unuse();
        m_indexBuffer->unbind();
        m_vertexArray->unbind();
    }

    void StaticDrawer::draw() const
    {
        glDrawElements(GL_TRIANGLES, m_indexBuffer->getCount(), GL_UNSIGNED_SHORT, (const void*)0);
    }

    void StaticDrawer::initBuffers()
    {
        std::vector<GLfloat> vertices = m_drawable->vertices();
        m_vertexBuffer = new VertexBuffer(vertices.size() * sizeof(GLfloat), vertices.data());

        std::vector<GLushort> indices = m_drawable->indices();
        m_indexBuffer = new IndexBuffer(indices.size(), indices.data());

        m_vertexArray = new VertexArray();
        m_vertexArray->setVertexAttribPointer(m_vertexBuffer, 0, 3, 7 * sizeof(GLfloat), (void*)0);
        m_vertexArray->setVertexAttribPointer(m_vertexBuffer, 1, 4, 7 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    }

    void StaticDrawer::initShader()
    {
            maths::mat4 model = maths::mat4::translate(m_drawable->position());
            maths::mat4 view = maths::mat4::identity();
            maths::mat4 projection = maths::mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 10.0f);

            m_shader = new graphics::Shader("resource/shaders/square.vert", "resource/shaders/square.frag");

            m_shader->use();
            m_shader->passingUniform("model", model);
            m_shader->passingUniform("view", view);
            m_shader->passingUniform("projection", projection);
            m_shader->unuse();
    }

    void StaticDrawer::init()
    {
        initBuffers();
        initShader();
    }

} }