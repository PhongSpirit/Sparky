#pragma once

#include <deque>
#include "drawable.h"
#include "../../maths/maths.h"

namespace cphong { namespace shapes {

    class Light
    {
    private:
        double m_xPos, m_yPos;

        std::deque<const Drawable*> m_drawableQueue;
    public:
        void push(const Drawable* drawable);
        void setLightPos(double x, double y);
        void light();
    };

} }