#pragma once

namespace math
{
    struct quat
    {
        auto     matrix() const noexcept -> mat4;
        auto  normalize()       noexcept -> void;

        [[nodiscard]] auto         length() const noexcept -> float;
        [[nodiscard]] auto squared_length() const noexcept -> float;

        auto rotation(const vec3& axis, float radians) noexcept -> void;

        float w;
        float x;
        float y;
        float z;
    };
}