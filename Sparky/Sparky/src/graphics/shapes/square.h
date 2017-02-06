#pragma once

#include <GL/glew.h>

#include "drawable.h"
#include "../../maths/maths.h"

namespace cphong { namespace shapes {

    class Square : public Drawable
    {
    private:
        maths::vec2 m_size;
        maths::vec3 m_position;
        maths::vec4 m_color;
    public:
        Square(const maths::vec2& size, const maths::vec3& position, const maths::vec4& color);
    private:
        void prepare() override;
    };

} }