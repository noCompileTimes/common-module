#pragma once

namespace math
{
    struct vec2
    {
        float x;
        float y;

        [[nodiscard]] constexpr auto operator+(const vec2& other) const noexcept
        {
            return vec2
            {
                x + other.x,
                y + other.y
            };
        }

        [[nodiscard]] constexpr auto operator-(const vec2& other) const noexcept
        {
            return vec2
            {
                x - other.x,
                y - other.y
            };
        }

        [[nodiscard]] constexpr auto operator*(const float value) const noexcept
        {
            return vec2
            {
                x * value,
                y * value
            };
        }

        [[nodiscard]] constexpr auto operator/(const float value) const noexcept
        {
            return vec2
            {
                x / value,
                y / value
            };
        }

        [[nodiscard]] static constexpr auto midpoint(const vec2& a, const vec2& b) noexcept
        {
            return (a + b) * 0.5f;
        }

        constexpr auto operator+=(const vec2& other) noexcept -> vec2&
        {
            x += other.x;
            y += other.y;

            return *this;
        }

        constexpr auto operator-=(const vec2& other) noexcept -> vec2&
        {
            x -= other.x;
            y -= other.y;

            return *this;
        }
    };
}