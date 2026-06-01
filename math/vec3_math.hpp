#pragma once

#include "vec3.hpp"

namespace math
{
    [[nodiscard]] static auto cross(const vec3& a, const vec3& b) noexcept
    {
        return vec3
        {
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        };
    }

    [[nodiscard]] static auto dot(const vec3& a, const vec3& b) noexcept
    {
        return a.x * b.x +
               a.y * b.y +
               a.z * b.z;
    }
}