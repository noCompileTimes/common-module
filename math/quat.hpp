#pragma once

namespace math
{
    struct quat
    {
        auto         matrix() const noexcept -> mat4;
        auto      normalize()       noexcept -> void;

        auto         length() const noexcept -> float;
        auto squared_length() const noexcept -> float;

        auto rotation(const vec3& axis, float radians) noexcept -> void;

        float w;
        float x;
        float y;
        float z;
    };
}