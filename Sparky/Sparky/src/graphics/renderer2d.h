#pragma once

#include <deque>

#include "shapes/drawer.h"

namespace cphong { namespace graphics {

    class Renderer2D
    {
    private:
        std::deque<const Drawer*> m_renderQueue;
    public:
        void submit(const Drawer* drawer);
        void flush();
    };

} }