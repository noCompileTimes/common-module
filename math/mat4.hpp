#pragma once

namespace math
{
    struct mat4
    {
             mat4();

        auto translate(const vec3& vec) -> void;
        auto     scale(const vec3& vec) -> void;

    private:
        std::array<column, 4> _columns;
    };
}