#pragma once

#include <deque>

#include "renderable2d.h"

namespace cphong { namespace graphics {

    class Renderer2D : public Renderable2D
    {
    private:
        std::deque<const shapes::Drawable*> m_renderQueue;
    public:
        void submit(const shapes::Drawable* drawable) override;
        void flush() override;
    };

} }