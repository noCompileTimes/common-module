#pragma once

#include <algorithm>

#include <cmath>

#include "constants.hpp"

namespace math
{
    [[nodiscard]] constexpr auto sin(const float angle)
    {
        return std::sin(angle);
    }

    [[nodiscard]] constexpr auto cos(const float angle)
    {
        return std::cos(angle);
    }

    [[nodiscard]] constexpr auto sqrt(const float value)
    {
        return std::sqrt(value);
    }

    [[nodiscard]] constexpr auto abs(const float value)
    {
        return std::abs(value);
    }

    [[nodiscard]] constexpr auto min(const float a, const float b)
    {
        return std::min(a, b);
    }

    [[nodiscard]] constexpr auto max(const float a, const float b)
    {
        return std::max(a, b);
    }

    [[nodiscard]] constexpr auto radians(const float degrees)
    {
        return degrees * (pi / 180.0f);
    }

    [[nodiscard]] constexpr auto degrees(const float radians)
    {
        return radians * (180.0f / pi);
    }
}