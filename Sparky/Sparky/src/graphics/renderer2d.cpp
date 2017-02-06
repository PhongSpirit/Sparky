#include "renderer2d.h"

namespace cphong { namespace graphics {

    void Renderer2D::submit(const shapes::Drawable* drawable)
    {
        m_renderQueue.push_back(drawable);
    }

    void Renderer2D::flush()
    {
        while (!m_renderQueue.empty())
        {
            const shapes::Drawable* drawable = m_renderQueue.front();
            drawable->enable();
            drawable->draw();
            drawable->disable();

            m_renderQueue.pop_front();
        }
    }

} }