#include "light.h"

namespace cphong { namespace shapes {

    void Light::push(const Drawable* drawable)
    {
        m_drawableQueue.push_back(drawable);
    }

    void Light::setLightPos(double x, double y)
    {
        m_xPos = x;
        m_yPos = y;
    }

    void Light::light()
    {
        for (const Drawable* i : m_drawableQueue)
        {
            const graphics::Shader* shader = i->getShader();
            shader->use();
            shader->passingUniform("lightPos", maths::vec2((float)m_xPos, (float)m_yPos));
            shader->unuse();
        }
    }

} }