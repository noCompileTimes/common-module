#pragma once

#include "vec4.hpp"

namespace math
{
    struct mat4
    {
        constexpr mat4() noexcept = default;

        explicit constexpr mat4(const float scale) noexcept
            :   _columns
            {
                { scale },
                { 0.0f, scale },
                { 0.0f, 0.0f, scale },
                { 0.0f, 0.0f, 0.0f, 1.0f }
            }
        {
        }

        explicit constexpr mat4(const vec3& scale) noexcept
            :   _columns
            {
                { scale.x },
                { 0.0f, scale.y },
                { 0.0f, 0.0f, scale.z },
                { 0.0f, 0.0f, 0.0f, 1.0f }
            }
        {
        }

        [[maybe_unused]] auto ortho(const float left, const float right, const float bottom, const float top, const float near, const float far) noexcept // TODO make this static?
        {
            _columns[0].x =  2.0f / (right - left);
            _columns[1].y =  2.0f / (top - bottom);
            _columns[2].z = -2.0f / (far - near);

            _columns[3].x = -(right + left) / (right - left);
            _columns[3].y = -(top + bottom) / (top - bottom);
            _columns[3].z = -(far + near)   / (far - near);
        }

        [[maybe_unused]] auto ortho(const float left, const float right, const float bottom, const float top) noexcept // TODO make this static?
        {
            _columns[0].x =  2.0f / (right - left);
            _columns[1].y =  2.0f / (top - bottom);
            _columns[2].z = -1.0f;

            _columns[3].x = -(right + left) / (right - left);
            _columns[3].y = -(top + bottom) / (top - bottom);
        }

        [[maybe_unused]] auto perspective(const float fov, const float aspect, const float near, const float far) noexcept // TODO make this static?
        {
            const auto value = tan(fov * 0.5f);
            const auto range = far - near;

            _columns[0].x = 1.0f / (value * aspect);
            _columns[1].y = 1.0f /  value;

            _columns[2].z = -(far + near) / range;
            _columns[2].w = -1.0f;

            _columns[3].z = -(2.0f * far * near) / range;
            _columns[3].w =   0.0f;
        }

        [[nodiscard]] auto operator*(const vec4& vec) const noexcept
        {
            return vec4
            {
                _columns[0].x * vec.x + _columns[1].x * vec.y + _columns[2].x * vec.z + _columns[3].x * vec.w,
                _columns[0].y * vec.x + _columns[1].y * vec.y + _columns[2].y * vec.z + _columns[3].y * vec.w,
                _columns[0].z * vec.x + _columns[1].z * vec.y + _columns[2].z * vec.z + _columns[3].z * vec.w,
                _columns[0].w * vec.x + _columns[1].w * vec.y + _columns[2].w * vec.z + _columns[3].w * vec.w
            };
        }

        [[nodiscard]] constexpr auto& operator[](const size_t index) const noexcept
        {
            return _columns[index];
        }

        [[nodiscard]] constexpr auto& operator[](const size_t index) noexcept
        {
            return _columns[index];
        }

        [[nodiscard]] auto operator*(const mat4& other) const noexcept
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

        constexpr auto& operator*=(this mat4& self, const mat4& other) noexcept
        {
            return self = self * other;
        }

        [[maybe_unused]] auto translation(const vec3& vec) noexcept
        {
            _columns[3].x = vec.x;
            _columns[3].y = vec.y;
            _columns[3].z = vec.z;
        }

        [[maybe_unused]] auto translate(const vec3& vec) noexcept
        {
            _columns[3] += _columns[0] * vec.x +
                           _columns[1] * vec.y +
                           _columns[2] * vec.z;
        }

        [[maybe_unused]] auto scale(const vec3& vec) noexcept
        {
            _columns[0] *= vec.x;
            _columns[1] *= vec.y;
            _columns[2] *= vec.z;
        }

    private:
        vec4 _columns[4]; // TODO use std::array? yes
    };
}