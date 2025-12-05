#pragma once

namespace math
{
    auto  sqrt(float value)   -> float;

    auto   sin(float radians) -> float;
    auto   cos(float radians) -> float;
    auto   tan(float radians) -> float;

    constexpr auto radians(const float degrees) -> float
    {
        return degrees * (pi / 180.0f);
    }
}