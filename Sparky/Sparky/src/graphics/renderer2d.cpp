#include "renderer2d.h"

namespace cphong { namespace graphics {

    void Renderer2D::submit(const Drawer* drawer)
    {
        m_renderQueue.push_back(drawer);
    }

    void Renderer2D::flush()
    {
        while (!m_renderQueue.empty())
        {
            const Drawer* drawer = m_renderQueue.front();
            
            drawer->enable();
            drawer->draw();
            drawer->disable();

            m_renderQueue.pop_front();
        }
    }

} }