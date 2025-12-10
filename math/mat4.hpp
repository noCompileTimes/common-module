#pragma once

#include "column.hpp"

namespace math
{
    struct mat4
    {
        constexpr mat4() noexcept
            :  columns
            {
                { 1.0f, 0.0f, 0.0f, 0.0f },
                { 0.0f, 1.0f, 0.0f, 0.0f },
                { 0.0f, 0.0f, 1.0f, 0.0f },
                { 0.0f, 0.0f, 0.0f, 1.0f }
            }
        {
        }

        auto ortho(float left, float right, float bottom, float top, float near, float far) noexcept -> void;
        auto ortho(float left, float right, float bottom, float top)                        noexcept -> void;

        auto perspective(float fov, float aspect, float near, float far) noexcept -> void;

        auto   translate(const vec3& vec) noexcept -> void;
        auto       scale(const vec3& vec) noexcept -> void;

        column columns[4];
    };
}