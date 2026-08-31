#pragma once

#include "mat4.hpp"
#include "vec2.hpp"

#include "ray.hpp"

namespace math
{
    // TODO make it more generic with the width and height (maybe viewport?)
    [[nodiscard]] static auto ray_to_world(const vec2& point, const int32_t width, const int32_t height, const mat4& view, const mat4& projection) noexcept
    {
        const vec2 ndc
        {
                   2.0f * point.x / static_cast<float>(width) - 1.0f,
            1.0f - 2.0f * point.y / static_cast<float>(height)
        };

        const auto inverse_matrix = inverse(projection * view);

        auto origin  = inverse_matrix * vec4 { ndc.x, ndc.y, -1.0f, 1.0f };
             origin /= origin.w;

        auto finish = inverse_matrix * vec4 { ndc.x, ndc.y,  1.0f, 1.0f };
             finish /= finish.w;

        auto direction = static_cast<vec3>(finish - origin);
             direction.normalize();

        return ray
        {
            static_cast<vec3>(origin), direction
        };
    }
}