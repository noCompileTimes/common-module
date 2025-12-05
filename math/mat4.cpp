#include "mat4.hpp"

namespace math
{
    constexpr mat4::mat4()
        :  columns
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
        columns[0].x =  2.0f / (right - left);
        columns[1].y =  2.0f / (top   - bottom);
        columns[2].z = -2.0f / (far   - near);

        columns[3].x = -(right + left)   / (right - left);
        columns[3].y = -(top   + bottom) / (top   - bottom);
        columns[3].z = -(far   + near)   / (far   - near);
    }

    auto mat4::ortho(const float left, const float right, const float bottom, const float top) -> void
    {
        columns[0].x =  2.0f / (right - left);
        columns[1].y =  2.0f / (top   - bottom);
        columns[2].z = -1.0f;

        columns[3].x = -(right + left)   / (right - left);
        columns[3].y = -(top   + bottom) / (top   - bottom);
    }

    auto mat4::perspective(const float fov, const float aspect, const float near, const float far) -> void
    {
        const auto t =  tan(radians(fov) * 0.5f);
        const auto r =  far - near;

        columns[0].x =  1.0f / (t * aspect);
        columns[1].y =  1.0f /  t;

        columns[2].z = -(far + near) / r;
        columns[2].w = -1.0f;

        columns[3].z = -(2.0f * far * near) / r;
        columns[3].w =   0.0f;
    }

    auto mat4::translate(const vec3& vec) -> void
    {
        columns[3] += columns[0] * vec.x +
                      columns[1] * vec.y +
                      columns[2] * vec.z;
    }

    auto mat4::scale(const vec3& vec) -> void
    {
        columns[0] *= vec.x;
        columns[1] *= vec.y;
        columns[2] *= vec.z;
    }
}