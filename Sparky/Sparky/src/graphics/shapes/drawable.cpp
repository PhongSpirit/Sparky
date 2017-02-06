#include "drawable.h"

namespace cphong { namespace shapes {

    Drawable::~Drawable()
    {
        delete m_shader;
        delete m_indexBuffer;
        delete m_vertexBuffer;
        delete m_vertexArray;
    }

    const graphics::Shader* Drawable::getShader() const
    {
        return m_shader;
    }

    void Drawable::enable() const
    {
        m_vertexArray->bind();
        m_vertexBuffer->bind();
        m_indexBuffer->bind();
        m_shader->use();
    }

    void Drawable::disable() const
    {
        m_shader->unuse();
        m_indexBuffer->unbind();
        m_vertexBuffer->unbind();
        m_vertexArray->unbind();
    }

    void Drawable::draw() const
    {
        glDrawElements(GL_TRIANGLES, m_indexBuffer->getCount(), GL_UNSIGNED_SHORT, (const void*)0);
    }

} }