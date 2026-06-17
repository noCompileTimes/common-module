#pragma once

#include "aabb.hpp"

#include "ray.hpp"

namespace math
{
    [[nodiscard]] static auto intersects(const ray& ray, const aabb& aabb) noexcept
    {
        const vec3 inverse_direction
        {
            1.0f / ray.direction.x,
            1.0f / ray.direction.y,
            1.0f / ray.direction.z
        };

        const auto [x0, y0, z0] = (aabb.min - ray.origin) * inverse_direction;
        const auto [x1, y1, z1] = (aabb.max - ray.origin) * inverse_direction;

        const vec3 tmin
        {
            min(x0, x1),
            min(y0, y1),
            min(z0, z1)
        };

        const vec3 tmax
        {
            max(x0, x1),
            max(y0, y1),
            max(z0, z1)
        };

        const auto near = max(max(tmin.x, tmin.y), tmin.z); // TODO rename this?
        const auto far  = min(min(tmax.x, tmax.y), tmax.z); // TODO rename this?

        return far >= max(near, 0.0f);
    }
}