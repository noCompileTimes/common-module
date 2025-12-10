#include "vec3.hpp"

namespace math
{
    auto vec3::normalize() noexcept -> void
    {
        if (const auto l = length();
                       l > epsilon)
        {
            const auto i = 1.0f / l;

            x *= i;
            y *= i;
            z *= i;
        }
    }

    auto vec3::length() const noexcept -> float
    {
        return std::sqrt(squared_length());
    }

    auto vec3::squared_length() const noexcept -> float
    {
        return x * x + y * y + z * z;
    }

    auto vec3::cross(const vec3& a, const vec3& b) noexcept -> vec3
    {
        return
        {
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        };
    }

    auto vec3::dot(const vec3& a, const vec3& b) noexcept -> float
    {
        return a.x * b.x +
               a.y * b.y +
               a.z * b.z;
    }

    auto vec3::operator+=(const vec3& other) noexcept -> vec3&
    {
        x += other.x;
        y += other.y;
        z += other.z;

        return *this;
    }

    auto vec3::operator*=(const float value) noexcept -> vec3&
    {
        x *= value;
        y *= value;
        z *= value;

        return *this;
    }

    auto vec3::operator+(const vec3& other) const noexcept -> vec3
    {
        return
        {
            x + other.x,
            y + other.y,
            z + other.z
        };
    }

    auto vec3::operator*(const float value) const noexcept -> vec3
    {
        return
        {
            x * value,
            y * value,
            z * value
        };
    }
}