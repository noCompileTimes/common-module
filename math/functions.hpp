#pragma once

#include "constants.hpp"

#include <algorithm> // TODO this in a precompiled header?

#include <cmath>

namespace math
{
    [[nodiscard]] constexpr float sin(const float angle)
    {
        return std::sin(angle);
    }

    [[nodiscard]] constexpr float cos(const float angle)
    {
        return std::cos(angle);
    }

    [[nodiscard]] constexpr float tan(const float angle)
    {
        return std::tan(angle);
    }

    [[nodiscard]] constexpr float abs(const float value)
    {
        return std::abs(value);
    }

    [[nodiscard]] constexpr float sqrt(const float value)
    {
        return std::sqrt(value);
    }

    [[nodiscard]] constexpr float min(const float a, const float b)
    {
        return std::min(a, b);
    }

    [[nodiscard]] constexpr float max(const float a, const float b)
    {
        return std::max(a, b);
    }

    [[nodiscard]] constexpr float radians(const float degrees)
    {
        return degrees * (pi / 180.0f);
    }

    [[nodiscard]] constexpr float degrees(const float radians)
    {
        return radians * (180.0f / pi);
    }
}