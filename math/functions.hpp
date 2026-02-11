#pragma once

#include <cmath>

namespace math
{
    inline auto sqrt(const float value) noexcept -> float
    {
        return std::sqrt(value);
    }

    inline auto sin(const float radians) noexcept -> float
    {
        return std::sin(radians);
    }

    inline auto cos(const float radians) noexcept -> float
    {
        return std::cos(radians);
    }

    inline auto tan(const float radians) noexcept -> float
    {
        return std::tan(radians);
    }

    constexpr auto degrees(const float radians) -> float
    {
        return radians * (180.0f / pi);
    }

    constexpr auto radians(const float degrees) -> float
    {
        return degrees * (pi / 180.0f);
    }
}