#pragma once

#include "column.hpp"

namespace math
{
    struct mat4
    {
        constexpr mat4()
            :  columns
            {
                { 1.0f, 0.0f, 0.0f, 0.0f },
                { 0.0f, 1.0f, 0.0f, 0.0f },
                { 0.0f, 0.0f, 1.0f, 0.0f },
                { 0.0f, 0.0f, 0.0f, 1.0f }
            }
        {
        }

        auto ortho(float left, float right, float bottom, float top, float near, float far) -> void;
        auto ortho(float left, float right, float bottom, float top)                        -> void;

        auto perspective(float fov, float aspect, float near, float far) -> void;

        auto   translate(const vec3& vec) -> void;
        auto       scale(const vec3& vec) -> void;

        column columns[4];
    };
}