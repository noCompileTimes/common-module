#pragma once

namespace math
{
    struct vec2
    {
        float x;
        float y;

        [[nodiscard]] constexpr vec2 operator+(const vec2& other) const noexcept
        {
            return
            {
                x + other.x,
                y + other.y
            };
        }

        [[nodiscard]] constexpr vec2 operator-(const vec2& other) const noexcept
        {
            return
            {
                x - other.x,
                y - other.y
            };
        }

        [[nodiscard]] constexpr vec2 operator*(const float value) const noexcept
        {
            return
            {
                x * value,
                y * value
            };
        }

        [[nodiscard]] constexpr vec2 operator/(const float value) const noexcept
        {
            return
            {
                x / value,
                y / value
            };
        }

        [[nodiscard]] constexpr static vec2 midpoint(const vec2& a, const vec2& b) noexcept
        {
            return (a + b) * 0.5f;
        }

        constexpr vec2& operator+=(const vec2& other) noexcept
        {
            x += other.x;
            y += other.y;

            return *this;
        }

        constexpr vec2& operator-=(const vec2& other) noexcept
        {
            x -= other.x;
            y -= other.y;

            return *this;
        }
    };
}