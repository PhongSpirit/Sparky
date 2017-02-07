#pragma once

#include <deque>
#include "staticdrawable.h"
#include "../../maths/maths.h"

namespace cphong { namespace shapes {

    class Light
    {
    private:
        double m_xPos, m_yPos;

        std::deque<const StaticDrawable*> m_drawableQueue;
    public:
        void push(const StaticDrawable* drawable);
        void setLightPos(double x, double y);
        void light();
    };

} }