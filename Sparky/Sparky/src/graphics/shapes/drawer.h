#pragma once

#include "drawable.h"

namespace cphong { namespace graphics {

    class Drawer
    {
    public:
        virtual ~Drawer() = default;

        virtual void enable() const = 0;
        virtual void disable() const = 0;
        virtual void draw() const = 0;
    };

} }