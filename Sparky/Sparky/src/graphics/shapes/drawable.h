#pragma once

#include <vector>
#include <GL/glew.h>
#include "../../maths/maths.h"

namespace cphong { namespace graphics {

    struct VertexData
    {
        maths::vec3 vertex;
        maths::vec4 color;
    };

    class Drawable
    {
    public:
        virtual ~Drawable() = default;

        virtual maths::vec3 position() const = 0;
        virtual std::vector<GLfloat> vertices() const = 0;
        virtual std::vector<GLushort> indices() const = 0;
    };

} }