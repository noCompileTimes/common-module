#include "mat4.hpp"

namespace math
{
    mat4::mat4()
        :  _columns
        {
            column { 1.0f, 0.0f, 0.0f, 0.0f },
            column { 0.0f, 1.0f, 0.0f, 0.0f },
            column { 0.0f, 0.0f, 1.0f, 0.0f },
            column { 0.0f, 0.0f, 0.0f, 1.0f }
        }
    {
    }

    auto mat4::translate(const vec3& vec) -> void
    {
        _columns[3] += _columns[0] * vec.x +
                       _columns[1] * vec.y +
                       _columns[2] * vec.z;
    }

    auto mat4::scale(const vec3& vec) -> void
    {
        _columns[0] *= vec.x;
        _columns[1] *= vec.y;
        _columns[2] *= vec.z;
    }
}