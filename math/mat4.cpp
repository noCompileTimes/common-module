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

    auto mat4::ortho(const float left, const float right, const float bottom, const float top, const float near, const float far) -> void
    {
        _columns[0].x =  2.0f / (right - left);
        _columns[1].y =  2.0f / (top   - bottom);
        _columns[2].z = -2.0f / (far   - near);

        _columns[3].x = -(right + left)   / (right - left);
        _columns[3].y = -(top   + bottom) / (top   - bottom);
        _columns[3].z = -(far   + near)   / (far   - near);
    }

    auto mat4::ortho(const float left, const float right, const float bottom, const float top) -> void
    {
        _columns[0].x =  2.0f / (right - left);
        _columns[1].y =  2.0f / (top   - bottom);
        _columns[2].z = -1.0f;

        _columns[3].x = -(right + left)   / (right - left);
        _columns[3].y = -(top   + bottom) / (top   - bottom);
    }

    auto mat4::perspective(const float fov, const float aspect, const float near, const float far) -> void
    {
         const auto t =  tan(fov * 0.5f);
         const auto r =  far     - near;

        _columns[0].x =  1.0f / (t * aspect);
        _columns[1].y =  1.0f /  t;

        _columns[2].z = -(far + near) / r;
        _columns[2].w = -1.0f;

        _columns[3].z = -(2.0f * far * near) / r;
        _columns[3].w =   0.0f;
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