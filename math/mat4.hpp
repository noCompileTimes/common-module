#pragma once

#include "vec4.hpp"

namespace math
{
    struct mat4
    {
        constexpr mat4() noexcept = default;

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

        [[maybe_unused]] auto ortho(const float left, const float right, const float bottom, const float top, const float near, const float far) noexcept
        {
            _columns[0].x =  2.0f / (right - left);
            _columns[1].y =  2.0f / (top - bottom);
            _columns[2].z = -2.0f / (far - near);

            _columns[3].x = -(right + left) / (right - left);
            _columns[3].y = -(top + bottom) / (top - bottom);
            _columns[3].z = -(far + near)   / (far - near);
        }

        [[maybe_unused]] auto ortho(const float left, const float right, const float bottom, const float top) noexcept
        {
            _columns[0].x =  2.0f / (right - left);
            _columns[1].y =  2.0f / (top - bottom);
            _columns[2].z = -1.0f;

            _columns[3].x = -(right + left) / (right - left);
            _columns[3].y = -(top + bottom) / (top - bottom);
        }

        [[maybe_unused]] auto perspective(const float fov, const float aspect, const float near, const float far) noexcept
        {
            const auto value = std::tan(fov * 0.5f);
            const auto range = far - near;

            _columns[0].x = 1.0f / (value * aspect);
            _columns[1].y = 1.0f /  value;

            _columns[2].z = -(far + near) / range;
            _columns[2].w = -1.0f;

            _columns[3].z = -(2.0f * far * near) / range;
            _columns[3].w =   0.0f;
        }

        auto translation(const vec3& vec) noexcept
        {
            _columns[3].x = vec.x;
            _columns[3].y = vec.y;
            _columns[3].z = vec.z;
        }

        auto translate(const vec3& vec) noexcept
        {
            _columns[3] += _columns[0] * vec.x +
                           _columns[1] * vec.y +
                           _columns[2] * vec.z;
        }

        auto scale(const vec3& vec) noexcept
        {
            _columns[0] *= vec.x;
            _columns[1] *= vec.y;
            _columns[2] *= vec.z;
        }

        auto operator*=(const mat4& other) noexcept -> mat4&
        {
            return *this =
                   *this * other;
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

        [[nodiscard]] constexpr auto operator[](const size_t index) const noexcept -> const vec4&
        {
            return _columns[index];
        }

        [[nodiscard]] constexpr auto operator[](const size_t index) noexcept -> vec4&
        {
            return _columns[index];
        }

        [[nodiscard]] auto inverse() const noexcept
        {
            const auto m00 = _columns[0].x;
            const auto m01 = _columns[0].y;
            const auto m02 = _columns[0].z;
            const auto m03 = _columns[0].w;

            const auto m10 = _columns[1].x;
            const auto m11 = _columns[1].y;
            const auto m12 = _columns[1].z;
            const auto m13 = _columns[1].w;

            const auto m20 = _columns[2].x;
            const auto m21 = _columns[2].y;
            const auto m22 = _columns[2].z;
            const auto m23 = _columns[2].w;

            const auto m30 = _columns[3].x;
            const auto m31 = _columns[3].y;
            const auto m32 = _columns[3].z;
            const auto m33 = _columns[3].w;

            const auto c00 = m22 * m33 - m32 * m23;
            const auto c02 = m12 * m33 - m32 * m13;
            const auto c03 = m12 * m23 - m22 * m13;

            const auto c04 = m21 * m33 - m31 * m23;
            const auto c06 = m11 * m33 - m31 * m13;
            const auto c07 = m11 * m23 - m21 * m13;

            const auto c08 = m21 * m32 - m31 * m22;
            const auto c10 = m11 * m32 - m31 * m12;
            const auto c11 = m11 * m22 - m21 * m12;

            const auto c12 = m20 * m33 - m30 * m23;
            const auto c14 = m10 * m33 - m30 * m13;
            const auto c15 = m10 * m23 - m20 * m13;

            const auto c16 = m20 * m32 - m30 * m22;
            const auto c18 = m10 * m32 - m30 * m12;
            const auto c19 = m10 * m22 - m20 * m12;

            const auto c20 = m20 * m31 - m30 * m21;
            const auto c22 = m10 * m31 - m30 * m11;
            const auto c23 = m10 * m21 - m20 * m11;

            const vec4 f0 { c00, c00, c02, c03 };
            const vec4 f1 { c04, c04, c06, c07 };
            const vec4 f2 { c08, c08, c10, c11 };
            const vec4 f3 { c12, c12, c14, c15 };
            const vec4 f4 { c16, c16, c18, c19 };
            const vec4 f5 { c20, c20, c22, c23 };

            const vec4 v0 { m10, m00, m00, m00 };
            const vec4 v1 { m11, m01, m01, m01 };
            const vec4 v2 { m12, m02, m02, m02 };
            const vec4 v3 { m13, m03, m03, m03 };

            const auto inv0 = v1 * f0 - v2 * f1 + v3 * f2;
            const auto inv1 = v0 * f0 - v2 * f3 + v3 * f4;
            const auto inv2 = v0 * f1 - v1 * f3 + v3 * f5;
            const auto inv3 = v0 * f2 - v1 * f4 + v2 * f5;

            constexpr vec4 sign_a {  1.0f, -1.0f,  1.0f, -1.0f };
            constexpr vec4 sign_b { -1.0f,  1.0f, -1.0f,  1.0f };

            mat4 result;
            result[0] = inv0 * sign_a;
            result[1] = inv1 * sign_b;
            result[2] = inv2 * sign_a;
            result[3] = inv3 * sign_b;

            const vec4 row0 // TODO handle this different
            {
                result[0].x,
                result[1].x,
                result[2].x,
                result[3].x
            };

            const auto determinant =
                _columns[0].x * row0.x +
                _columns[0].y * row0.y +
                _columns[0].z * row0.z +
                _columns[0].w * row0.w;

            if (abs(determinant) < epsilon)
            {
                return mat4 { 1.0f };
            }

            const auto inverse_determinant = 1.0f / determinant;

            result[0] *= inverse_determinant;
            result[1] *= inverse_determinant;
            result[2] *= inverse_determinant;
            result[3] *= inverse_determinant;

            return result;
        }

        [[nodiscard]] auto inverse_affine() const noexcept
        {
            const auto m00 = _columns[0].x;
            const auto m01 = _columns[0].y;
            const auto m02 = _columns[0].z;

            const auto m10 = _columns[1].x;
            const auto m11 = _columns[1].y;
            const auto m12 = _columns[1].z;

            const auto m20 = _columns[2].x;
            const auto m21 = _columns[2].y;
            const auto m22 = _columns[2].z;

            const auto c00 = m11 * m22 - m21 * m12;
            const auto c01 = m21 * m02 - m01 * m22;
            const auto c02 = m01 * m12 - m11 * m02;

            const auto c10 = m20 * m12 - m10 * m22;
            const auto c11 = m00 * m22 - m20 * m02;
            const auto c12 = m10 * m02 - m00 * m12;

            const auto c20 = m10 * m21 - m20 * m11;
            const auto c21 = m20 * m01 - m00 * m21;
            const auto c22 = m00 * m11 - m10 * m01;

            const auto determinant = m00 * c00 + m10 * c01 + m20 * c02;

            if (abs(determinant) < epsilon)
            {
                return mat4 { 1.0f }; // TODO use the uninitialized constructor and put the diagonals with 1.0f
            }

            const auto inverse_determinant = 1.0f / determinant;

            mat4 result { 1.0f };

            result[0].x = c00 * inverse_determinant;
            result[0].y = c01 * inverse_determinant;
            result[0].z = c02 * inverse_determinant;

            result[1].x = c10 * inverse_determinant;
            result[1].y = c11 * inverse_determinant;
            result[1].z = c12 * inverse_determinant;

            result[2].x = c20 * inverse_determinant;
            result[2].y = c21 * inverse_determinant;
            result[2].z = c22 * inverse_determinant;

            const auto tx = _columns[3].x;
            const auto ty = _columns[3].y;
            const auto tz = _columns[3].z;

            result[3].x = -(result[0].x * tx + result[1].x * ty + result[2].x * tz);
            result[3].y = -(result[0].y * tx + result[1].y * ty + result[2].y * tz);
            result[3].z = -(result[0].z * tx + result[1].z * ty + result[2].z * tz);

            return result;
        }

        [[nodiscard]] auto inverse_rigid() const noexcept
        {
            mat4 result { 1.0f }; // TODO use the uninitialized constructor and put the diagonals with 1.0f

            result[0].x = _columns[0].x;
            result[0].y = _columns[1].x;
            result[0].z = _columns[2].x;

            result[1].x = _columns[0].y;
            result[1].y = _columns[1].y;
            result[1].z = _columns[2].y;

            result[2].x = _columns[0].z;
            result[2].y = _columns[1].z;
            result[2].z = _columns[2].z;

            const auto tx = _columns[3].x;
            const auto ty = _columns[3].y;
            const auto tz = _columns[3].z;

            result[3].x = -(result[0].x * tx + result[1].x * ty + result[2].x * tz);
            result[3].y = -(result[0].y * tx + result[1].y * ty + result[2].y * tz);
            result[3].z = -(result[0].z * tx + result[1].z * ty + result[2].z * tz);

            return result;
        }

        //auto inv_model = model.inverse_affine();
        //auto inv_view  = view.inverse_rigid();
        //auto inv_proj  = projection.inverse(); // TODO for ortho use the affine inverse

    private:
        vec4 _columns[4]; // TODO use std::array? yes
    };
}