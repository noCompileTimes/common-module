#pragma once

namespace math
{
    struct mat4
    {
              mat4();

        auto ortho(float left, float right, float bottom, float top, float near, float far) -> void;
        auto ortho(float left, float right, float bottom, float top)                        -> void;

        auto perspective(float fov, float aspect, float near, float far)                    -> void;

        auto   translate(const vec3& vec) -> void;
        auto       scale(const vec3& vec) -> void;

    private:
        std::array<column, 4> _columns;
    };
}