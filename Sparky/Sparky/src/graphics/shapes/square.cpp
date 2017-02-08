#include "square.h"

namespace cphong { namespace graphics {

    Square::Square(float width, float height, float x, float y, const maths::vec4& color)
        : m_width(width), m_height(height), m_x(x), m_y(y), m_color(color)
    {
    }

    maths::vec2 Square::getSize() const
    {
        return maths::vec2(m_width, m_height);
    }

    maths::vec4 Square::getColor() const
    {
        return m_color;
    }

    maths::vec3 Square::position() const
    {
        return maths::vec3(m_x, m_y, 0.0f);
    }

    std::vector<GLfloat> Square::vertices() const
    {
        std::vector<GLfloat> result =
        {
            //vertex                    color
            0.0f,    0.0f,     0.0f,   m_color.x, m_color.y, m_color.z, m_color.w,
            m_width, 0.0f,     0.0f,   m_color.x, m_color.y, m_color.z, m_color.w,
            m_width, m_height, 0.0f,   m_color.x, m_color.y, m_color.z, m_color.w,
            0.0f,    m_height, 0.0f,   m_color.x, m_color.y, m_color.z, m_color.w
        };
        return result;
    }

    std::vector<GLushort> Square::indices() const
    {
        std::vector<GLushort> result =
        {
            0, 1, 2,
            2, 3, 0
        };
        return result;
    }

} }