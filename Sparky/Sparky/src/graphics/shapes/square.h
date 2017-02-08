#pragma once

#include <GL/glew.h>

#include "drawable.h"
#include "../../maths/maths.h"

namespace cphong { namespace graphics {

    class Square : public Drawable
    {
    private:
        float m_width, m_height, m_x, m_y;
        maths::vec4 m_color;
    public:
        Square(float width, float height, float x, float y, const maths::vec4& color);

        maths::vec2 getSize() const;
        maths::vec4 getColor() const;

        maths::vec3 position() const override;
        std::vector<GLfloat> vertices() const override;
        std::vector<GLushort> indices() const override;
    };

} }