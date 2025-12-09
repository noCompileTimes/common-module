#include "column.hpp"

namespace math
{
    auto column::operator+(const column& other) const noexcept -> column
    {
        return
        {
            x + other.x, // TODO improve this with simd
            y + other.y,
            z + other.z,
            w + other.w
        };
    }

    auto column::operator*(const float value) const noexcept -> column
    {
        return
        {
            x * value, // TODO improve this with simd
            y * value,
            z * value,
            w * value
        };
    }

    auto column::operator+=(const column& other) noexcept -> column&
    {
        x += other.x; // TODO improve this with simd
        y += other.y;
        z += other.z;
        w += other.w;

        return *this;
    }

    auto column::operator*=(const float value) noexcept -> column&
    {
        x *= value; // TODO improve this with simd
        y *= value;
        z *= value;
        w *= value;

        return *this;
    }
}