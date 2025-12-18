#pragma once

namespace math
{
    struct vec2
    {
        auto operator+=(const vec2& other) noexcept -> vec2&;

        [[nodiscard]] auto operator+(const vec2& other) const noexcept -> vec2;

        // TODO minus operator

        float x;
        float y;
    };
}