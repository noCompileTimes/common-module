#include "vec2.hpp"

namespace math
{
    auto vec2::operator+=(const vec2& other) noexcept -> vec2&
    {
        x += other.x;
        y += other.y;

        return *this;
    }

    auto vec2::operator-=(const vec2& other) noexcept -> vec2&
    {
        x -= other.x;
        y -= other.y;

        return *this;
    }

    auto vec2::operator+(const vec2& other) const noexcept -> vec2
    {
        return
        {
            x + other.x,
            y + other.y
        };
    }

    auto vec2::operator-(const vec2& other) const noexcept -> vec2
    {
        return
        {
            x - other.x,
            y - other.y
        };
    }
}