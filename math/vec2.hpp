#pragma once

namespace math
{
    struct vec2
    {
        auto operator+=(const vec2& other) noexcept -> vec2&
        {
            x += other.x;
            y += other.y;

            return *this;
        }

        auto operator-=(const vec2& other) noexcept -> vec2&
        {
            x -= other.x;
            y -= other.y;

            return *this;
        }

        [[nodiscard]] auto operator+(const vec2& other) const noexcept -> vec2
        {
            return
            {
                x + other.x,
                y + other.y
            };
        }

        [[nodiscard]] auto operator-(const vec2& other) const noexcept -> vec2
        {
            return
            {
                x - other.x,
                y - other.y
            };
        }

        union
        {
            struct
            {
                float x;
                float y;
            };

            struct
            {
                float u;
                float v;
            };
        };
    };
}