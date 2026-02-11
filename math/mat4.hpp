#pragma once

namespace math
{
    struct mat4
    {
                 constexpr mat4()                  noexcept = default;
        explicit constexpr mat4(const float scale) noexcept
            : _columns
            {
                { scale },
                { 0.0f, scale },
                { 0.0f, 0.0f, scale },
                { 0.0f, 0.0f, 0.0f, 1.0f }
            }
        {
        }

        explicit constexpr mat4(const vec3& scale) noexcept
            : _columns
            {
                { scale.x },
                { 0.0f, scale.y },
                { 0.0f, 0.0f, scale.z },
                { 0.0f, 0.0f, 0.0f, 1.0f }
            }
        {
        }

        auto ortho(const float left, const float right, const float bottom, const float top, const float near_z, const float far_z) noexcept -> void
        {
            _columns[0].x =  2.0f / (right - left);
            _columns[1].y =  2.0f / (top   - bottom);
            _columns[2].z = -2.0f / (far_z - near_z);

            _columns[3].x = -(right + left)   / (right - left);
            _columns[3].y = -(top   + bottom) / (top   - bottom);
            _columns[3].z = -(far_z + near_z) / (far_z - near_z);
        }

        auto ortho(const float left, const float right, const float bottom, const float top) noexcept -> void
        {
            _columns[0].x =  2.0f / (right - left);
            _columns[1].y =  2.0f / (top   - bottom);
            _columns[2].z = -1.0f;

            _columns[3].x = -(right + left)   / (right - left);
            _columns[3].y = -(top   + bottom) / (top   - bottom);
        }

        auto perspective(const float fov, const float aspect, const float near_z, const float far_z) noexcept -> void
        {
            const auto tan_fov =  tan(fov * 0.5f);
            const auto range   =    far_z - near_z;

            _columns[0].x =  1.0f / (tan_fov * aspect);
            _columns[1].y =  1.0f /  tan_fov;

            _columns[2].z = -(far_z + near_z) / range;
            _columns[2].w = -1.0f;

            _columns[3].z = -(2.0f  * near_z * far_z) / range;
            _columns[3].w =   0.0f;
        }

        auto translation(const vec3& vec) noexcept -> void
        {
            _columns[3].x = vec.x;
            _columns[3].y = vec.y;
            _columns[3].z = vec.z;
        }

        auto translate(const vec3& vec) noexcept -> void
        {
            _columns[3] += _columns[0] * vec.x +
                           _columns[1] * vec.y +
                           _columns[2] * vec.z;
        }

        auto scale(const vec3& vec) noexcept -> void
        {
            _columns[0] *= vec.x;
            _columns[1] *= vec.y;
            _columns[2] *= vec.z;
        }

        auto operator*=(const mat4& other) noexcept -> mat4&
        {
            *this = *this * other;
             return *this;
        }

        [[nodiscard]] auto operator*(const mat4& other) const noexcept -> mat4
        {
            mat4 matrix;

            for (auto i = 0; i < 4; ++i)
            {
                matrix[i] = _columns[0] * other[i].x +
                            _columns[1] * other[i].y +
                            _columns[2] * other[i].z +
                            _columns[3] * other[i].w;
            }

            return matrix;
        }

        [[nodiscard]] constexpr auto operator[](const size_t index) const noexcept -> const vec4&
        {
            return _columns[index];
        }

        [[nodiscard]] constexpr auto operator[](const size_t index) noexcept -> vec4&
        {
            return _columns[index];
        }

    private:
        vec4 _columns[4];
    };
}