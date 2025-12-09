#pragma once

namespace math
{
    struct column
    {
        auto operator+ (const column& other) const noexcept -> column;
        auto operator* (float         value) const noexcept -> column;

        auto operator+=(const column& other)       noexcept -> column&;
        auto operator*=(float         value)       noexcept -> column&;

        float x { };
        float y { };
        float z { };
        float w { };
    };
}