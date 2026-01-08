#pragma once

#include "column.hpp"

namespace math
{
    struct mat4
    {
                 constexpr mat4()                  noexcept = default;
        explicit constexpr mat4(const float scale) noexcept
            : columns  {
                column { scale },
                column { 0.0f, scale },
                column { 0.0f, 0.0f, scale },
                column { 0.0f, 0.0f, 0.0f, 1.0f }
            }
        {
        }

        explicit constexpr mat4(const vec3& scale) noexcept
            : columns  {
                column { scale.x },
                column { 0.0f, scale.y },
                column { 0.0f, 0.0f, scale.z },
                column { 0.0f, 0.0f, 0.0f, 1.0f }
            }
        {
        }

        auto ortho(float left, float right, float bottom, float top, float near_z, float far_z) noexcept -> void;
        auto ortho(float left, float right, float bottom, float top)                            noexcept -> void;

        auto perspective(float fov, float aspect, float near_z, float far_z) noexcept -> void;

        auto translation(const vec3& vec) noexcept -> void;
        auto   translate(const vec3& vec) noexcept -> void;
        auto       scale(const vec3& vec) noexcept -> void;

                      auto operator*=(const mat4& other)       noexcept -> mat4&;
        [[nodiscard]] auto operator* (const mat4& other) const noexcept -> mat4;

        std::array<column, 4> columns;
    };
}