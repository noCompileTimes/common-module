#pragma once

#include "constants.hpp"

namespace math
{
    template <typename T>  [[nodiscard]] constexpr auto min(const T a, const T b) noexcept
    {
        return std::min(a, b);
    }

    template <typename T>  [[nodiscard]] constexpr auto max(const T a, const T b) noexcept
    {
        return std::max(a, b);
    }

    [[nodiscard, maybe_unused]] constexpr auto radians(const float degrees) noexcept
    {
        return degrees * (pi / 180.0f);
    }

    [[nodiscard, maybe_unused]] constexpr auto degrees(const float radians) noexcept
    {
        return radians * (180.0f / pi);
    }

    [[nodiscard]] constexpr auto sqrt(const float value) noexcept
    {
        return std::sqrt(value);
    }

    [[nodiscard]] constexpr auto abs(const float value) noexcept
    {
        return std::abs(value);
    }

    [[nodiscard]] constexpr auto sin(const float angle) noexcept
    {
        return std::sin(angle);
    }

    [[nodiscard]] constexpr auto cos(const float angle) noexcept
    {
        return std::cos(angle);
    }

    [[nodiscard]] constexpr auto tan(const float angle) noexcept
    {
        return std::tan(angle);
    }
}