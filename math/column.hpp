#pragma once

namespace math
{
    struct column
    {
        auto operator+=(const column& other) noexcept -> column&;
        auto operator*=(float         value) noexcept -> column&;

        [[nodiscard]] auto operator+(const column& other) const noexcept -> column;
        [[nodiscard]] auto operator*(float         value) const noexcept -> column;

        float x { };
        float y { };
        float z { };
        float w { };
    };
}