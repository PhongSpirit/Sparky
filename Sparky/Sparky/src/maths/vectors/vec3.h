#pragma once

#include <math.h>

namespace cphong { namespace maths {

    struct vec3
    {
        float x, y, z;

        vec3();
        explicit vec3(float x, float y, float z);

        double length() const;
        vec3 normalize() const;

        double dot(const vec3& other) const;
        vec3 cross(const vec3& other) const;

        friend vec3 operator + (const vec3& left, const vec3& right);
        friend vec3 operator + (const vec3& vector, float number);
        friend vec3 operator + (float number, const vec3& vector);

        friend vec3 operator - (const vec3& left, const vec3& right);
        friend vec3 operator - (const vec3& vector, float number);

        friend vec3 operator * (const vec3& left, const vec3& right);
        friend vec3 operator * (const vec3& vector, float number);
        friend vec3 operator * (float number, const vec3& vector);

        friend vec3 operator / (const vec3& left, const vec3& right);
        friend vec3 operator / (const vec3& vector, float number);
    };

} }