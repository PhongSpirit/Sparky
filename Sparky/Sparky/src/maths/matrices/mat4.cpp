#include "mat4.h"

namespace cphong { namespace maths {

    mat4::mat4()
    {
        for (int i = 0; i < 4 * 4; ++i)
        {
            elements[i] = 0.0f;
        }
    }

    mat4::mat4(float diagonal)
    {
        for (int i = 0; i < 4 * 4; ++i)
        {
            elements[i] = 0.0f;
        }

        elements[0 + 0 * 4] = diagonal;
        elements[1 + 1 * 4] = diagonal;
        elements[2 + 2 * 4] = diagonal;
        elements[3 + 3 * 4] = diagonal;
    }

    mat4 mat4::identity()
    {
        return mat4(1.0f);
    }

    mat4 mat4::translate(const vec3& translation)
    {
        mat4 result(1.0f);
        result.elements[0 + 3 * 4] = translation.x;
        result.elements[1 + 3 * 4] = translation.y;
        result.elements[2 + 3 * 4] = translation.z;
        return result;
    }

    mat4 mat4::rotate(float angleDegree, const vec3& axis)
    {
        float r = (float)(angleDegree * M_PI / 180.f);
        float s = (float)sin(r);
        float c = (float)cos(r);
        float omc = 1.0f - c;

        float x = axis.x;
        float y = axis.y;
        float z = axis.z;

        mat4 result;
        result.elements[0 + 0 * 4] = x * x * omc + c;
        result.elements[1 + 0 * 4] = x * y * omc + z * s;
        result.elements[2 + 0 * 4] = x * z * omc - y * s;
        result.elements[0 + 1 * 4] = x * y * omc - z * s;
        result.elements[1 + 1 * 4] = y * y * omc + c;
        result.elements[2 + 1 * 4] = y * z * omc + x * s;
        result.elements[0 + 2 * 4] = x * z * omc + y * s;
        result.elements[1 + 2 * 4] = y * z * omc - x * s;
        result.elements[2 + 2 * 4] = z * z * omc + c;
        result.elements[3 + 3 * 4] = 1.0f;
        return result;
    }

    mat4 mat4::scaling(const vec3& scale)
    {
        mat4 result;
        result.elements[0 + 0 * 4] = scale.x;
        result.elements[1 + 1 * 4] = scale.y;
        result.elements[2 + 2 * 4] = scale.z;
        result.elements[3 + 3 * 4] = 1.0f;
        return result;
    }

    mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far)
    {
        mat4 result;
        result.elements[0 + 0 * 4] = 2.0f / (right - left);
        result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
        result.elements[2 + 2 * 4] = 2.0f / (near - far);
        result.elements[0 + 3 * 4] = (left + right) / (left - right);
        result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
        result.elements[2 + 3 * 4] = (near + far) / (near - far);
        result.elements[3 + 3 * 4] = 1.0f;
        return result;
    }

    mat4 operator * (const mat4& left, const mat4& right)
    {
        mat4 result;
        for (int x = 0; x < 4; ++x)
        {
            for (int y = 0; y < 4; ++y)
            {
                for (int e = 0; e < 4; ++e)
                {
                    result.elements[x + y * 4] += left.elements[x + e * 4] * right.elements[e + y * 4];
                }
            }
        }
        return result;
    }

} }