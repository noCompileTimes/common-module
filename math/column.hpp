#pragma once

namespace math
{
    struct column
    {
        auto operator+(const column& other) const -> column;
        auto operator*(float         value) const -> column;

        auto operator+=(const column& other)     -> column&;
        auto operator*=(float         value)     -> column&;

        float x { };
        float y { };
        float z { };
        float w { };
    };
}