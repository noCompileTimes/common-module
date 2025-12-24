#include "mat4.hpp"

namespace math
{
    auto mat4::ortho(const float left, const float right, const float bottom, const float top, const float near_z, const float far_z) noexcept -> void
    {
        columns[0].x =  2.0f / (right - left);
        columns[1].y =  2.0f / (top   - bottom);
        columns[2].z = -2.0f / (far_z - near_z);

        columns[3].x = -(right + left)   / (right - left);
        columns[3].y = -(top   + bottom) / (top   - bottom);
        columns[3].z = -(far_z + near_z) / (far_z - near_z);
    }

    auto mat4::ortho(const float left, const float right, const float bottom, const float top) noexcept -> void
    {
        columns[0].x =  2.0f / (right - left);
        columns[1].y =  2.0f / (top   - bottom);
        columns[2].z = -1.0f;

        columns[3].x = -(right + left)   / (right - left);
        columns[3].y = -(top   + bottom) / (top   - bottom);
    }

    auto mat4::perspective(const float fov, const float aspect, const float near_z, const float far_z) noexcept -> void
    {
        const auto tan_fov =  tan(fov * 0.5f);
        const auto range   =    far_z - near_z;

        columns[0].x =  1.0f / (tan_fov * aspect);
        columns[1].y =  1.0f /  tan_fov;

        columns[2].z = -(far_z + near_z) / range;
        columns[2].w = -1.0f;

        columns[3].z = -(2.0f  * near_z * far_z) / range;
        columns[3].w =   0.0f;
    }

    auto mat4::translation(const vec3& vec) noexcept -> void
    {
        columns[3].x = vec.x;
        columns[3].y = vec.y;
        columns[3].z = vec.z;
    }

    auto mat4::translate(const vec3& vec) noexcept -> void
    {
        columns[3] += columns[0] * vec.x +
                      columns[1] * vec.y +
                      columns[2] * vec.z;
    }

    auto mat4::scale(const vec3& vec) noexcept -> void
    {
        columns[0] *= vec.x;
        columns[1] *= vec.y;
        columns[2] *= vec.z;
    }

    auto mat4::operator*=(const mat4& other) noexcept -> mat4&
    {
        *this = *this * other;
         return *this;
    }

    auto mat4::operator*(const mat4& other) const noexcept -> mat4
    {
        mat4 matrix;

        for (auto i = 0; i < columns.size(); ++i)
        {
            matrix.columns[i] = columns[0] * other.columns[i].x +
                                columns[1] * other.columns[i].y +
                                columns[2] * other.columns[i].z +
                                columns[3] * other.columns[i].w;
        }

        return matrix;
    }
}