#pragma once

#include "shapes/drawable.h"

namespace cphong { namespace graphics {

    class Renderable2D
    {
    public:
        virtual void submit(const shapes::Drawable* drawable) = 0;
        virtual void flush() = 0;
    };

} }