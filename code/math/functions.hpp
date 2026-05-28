#pragma once

namespace math
{
    constexpr auto degrees(const float radians) -> float
    {
        return radians * (180.0f / pi);
    }

    constexpr auto radians(const float degrees) -> float
    {
        return degrees * (pi / 180.0f);
    }
}