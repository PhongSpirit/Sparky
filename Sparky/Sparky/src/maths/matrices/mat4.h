#pragma once

#include <math.h>

#include "../vectors/vec3.h"

namespace cphong { namespace maths {

    struct mat4
    {
        float elements[4 * 4];

        mat4();
        mat4(float diagonal);

        static mat4 identity();
        static mat4 translate(const vec3& translation);
        static mat4 rotate(float angleDegree, const vec3& axis);
        static mat4 scaling(const vec3& scale);

        static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);

        friend mat4 operator * (const mat4& left, const mat4& right);
    };

} }