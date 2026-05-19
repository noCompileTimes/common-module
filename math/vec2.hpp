#pragma once

namespace math
{
    struct vec2
    {
        float x;
        float y;

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

        [[nodiscard]] auto operator+(const vec2& other) const noexcept
        {
            return vec2
            {
                x + other.x,
                y + other.y
            };
        }

        [[nodiscard]] auto operator-(const vec2& other) const noexcept
        {
            return vec2
            {
                x - other.x,
                y - other.y
            };
        }

        [[nodiscard]] auto operator*(const float value) const noexcept
        {
            return vec2
            {
                x * value,
                y * value
            };
        }

        static auto midpoint(const vec2& a, const vec2& b) noexcept
        {
            return (a + b) * 0.5f;
        }
    };
}