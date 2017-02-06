#include "vec3.h"

namespace cphong { namespace maths {

    vec3::vec3() : x(0.0f), y(0.0f), z(0.0f) { }

    vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) { }

    double vec3::length() const
    {
        return sqrt((double)(x * x + y * y + z * z));
    }

    vec3 vec3::normalize() const
    {
        float len = (float)length();
        return vec3(x / len, y / len, z / len);
    }

    double vec3::dot(const vec3& other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }

    vec3 vec3::cross(const vec3& other) const
    {
        return vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }

    vec3 operator + (const vec3& left, const vec3& right)
    {
        return vec3(left.x + right.x, left.y + right.y, left.z + right.z);
    }

    vec3 operator + (const vec3& vector, float number)
    {
        return vec3(vector.x + number, vector.y + number, vector.z + number);
    }

    vec3 operator + (float number, const vec3& vector)
    {
        return vec3(vector.x + number, vector.y + number, vector.z + number);
    }

    vec3 operator - (const vec3& left, const vec3& right)
    {
        return vec3(left.x - right.x, left.y - right.y, left.z - right.z);
    }

    vec3 operator - (const vec3& vector, float number)
    {
        return vec3(vector.x - number, vector.y - number, vector.z - number);
    }

    vec3 operator * (const vec3& left, const vec3& right)
    {
        return vec3(left.x * right.x, left.y * right.y, left.z * right.z);
    }

    vec3 operator * (const vec3& vector, float number)
    {
        return vec3(vector.x * number, vector.y * number, vector.z * number);
    }

    vec3 operator * (float number, const vec3& vector)
    {
        return vec3(vector.x * number, vector.y * number, vector.z * number);
    }

    vec3 operator / (const vec3& left, const vec3& right)
    {
        return vec3(left.x / right.x, left.y / right.y, left.z / right.z);
    }

    vec3 operator / (const vec3& vector, float number)
    {
        return vec3(vector.x / number, vector.y / number, vector.z / number);
    }

} }