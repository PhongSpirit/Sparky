#pragma once

namespace cphong { namespace shapes {

    class Drawable
    {
    public:
        virtual void enable() const = 0;
        virtual void disable() const = 0;
        virtual void draw() const = 0;
    private:
        virtual void init() = 0;
    };

} }