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
                column { 0.0f, 0.0f, 0.0f, scale }
            }
        {
        }

        auto ortho(float left, float right, float bottom, float top, float near, float far) noexcept -> void;
        auto ortho(float left, float right, float bottom, float top)                        noexcept -> void;

        auto perspective(float fov, float aspect, float near, float far) noexcept -> void;

        auto   translate(const vec3& vec) noexcept -> void;
        auto       scale(const vec3& vec) noexcept -> void;

                      auto operator*=(const mat4& other)       noexcept -> mat4&;
        [[nodiscard]] auto operator* (const mat4& other) const noexcept -> mat4;

        std::array<column, 4> columns;
    };
}