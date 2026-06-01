#pragma once

#include "vec2.hpp"

namespace math
{
    [[nodiscard]] static auto midpoint(const vec2& a, const vec2& b) noexcept
    {
        return (a + b) * 0.5f;
    }
}