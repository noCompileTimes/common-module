#pragma once

#ifdef near // TODO remove at some point after we remove common_module from graphics
#undef near
#endif

#ifdef far // TODO remove at some point after we remove common_module from graphics
#undef far
#endif

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
            _columns[1].y =  2.0f / (top   - bottom);
            _columns[2].z = -2.0f / (far   - near);

            _columns[3].x = -(right + left)   / (right - left);
            _columns[3].y = -(top   + bottom) / (top   - bottom);
            _columns[3].z = -(far   + near)   / (far   - near);
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
            const auto tan_fov = tan(fov * 0.5f);
            const auto   range = far - near;

            _columns[0].x = 1.0f / (tan_fov * aspect);
            _columns[1].y = 1.0f /  tan_fov;

            _columns[2].z = -(far + near) / range;
            _columns[2].w = -1.0f;

            _columns[3].z = -(2.0f * far + near) / range;
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
                    *this =
                    *this * other;
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

        [[nodiscard]] auto inverse() const noexcept -> mat4
        {
            const auto m00 = _columns[0].x;
            const auto m01 = _columns[1].x;
            const auto m02 = _columns[2].x;
            const auto m03 = _columns[3].x;

            const auto m10 = _columns[0].y;
            const auto m11 = _columns[1].y;
            const auto m12 = _columns[2].y;
            const auto m13 = _columns[3].y;

            const auto m20 = _columns[0].z;
            const auto m21 = _columns[1].z;
            const auto m22 = _columns[2].z;
            const auto m23 = _columns[3].z;

            const auto m30 = _columns[0].w;
            const auto m31 = _columns[1].w;
            const auto m32 = _columns[2].w;
            const auto m33 = _columns[3].w;

            const auto coef00 = m22 * m33 - m32 * m23;
            const auto coef02 = m12 * m33 - m32 * m13;
            const auto coef03 = m12 * m23 - m22 * m13;

            const auto coef04 = m21 * m33 - m31 * m23;
            const auto coef06 = m11 * m33 - m31 * m13;
            const auto coef07 = m11 * m23 - m21 * m13;

            const auto coef08 = m21 * m32 - m31 * m22;
            const auto coef10 = m11 * m32 - m31 * m12;
            const auto coef11 = m11 * m22 - m21 * m12;

            const auto coef12 = m20 * m33 - m30 * m23;
            const auto coef14 = m10 * m33 - m30 * m13;
            const auto coef15 = m10 * m23 - m20 * m13;

            const auto coef16 = m20 * m32 - m30 * m22;
            const auto coef18 = m10 * m32 - m30 * m12;
            const auto coef19 = m10 * m22 - m20 * m12;

            const auto coef20 = m20 * m31 - m30 * m21;
            const auto coef22 = m10 * m31 - m30 * m11;
            const auto coef23 = m10 * m21 - m20 * m11;

            const vec4 fac0 { coef00, coef00, coef02, coef03 };
            const vec4 fac1 { coef04, coef04, coef06, coef07 };
            const vec4 fac2 { coef08, coef08, coef10, coef11 };
            const vec4 fac3 { coef12, coef12, coef14, coef15 };
            const vec4 fac4 { coef16, coef16, coef18, coef19 };
            const vec4 fac5 { coef20, coef20, coef22, coef23 };

            const vec4 vec0 { m10, m00, m00, m00 };
            const vec4 vec1 { m11, m01, m01, m01 };
            const vec4 vec2 { m12, m02, m02, m02 };
            const vec4 vec3 { m13, m03, m03, m03 };

            const vec4 inv0 = vec1 * fac0 - vec2 * fac1 + vec3 * fac2;
            const vec4 inv1 = vec0 * fac0 - vec2 * fac3 + vec3 * fac4;
            const vec4 inv2 = vec0 * fac1 - vec1 * fac3 + vec3 * fac5;
            const vec4 inv3 = vec0 * fac2 - vec1 * fac4 + vec2 * fac5;

            constexpr vec4 sign_a {  1.0f, -1.0f,  1.0f, -1.0f };
            constexpr vec4 sign_b { -1.0f,  1.0f, -1.0f,  1.0f };

            mat4 result;
            result[0] = inv0 * sign_a;
            result[1] = inv1 * sign_b;
            result[2] = inv2 * sign_a;
            result[3] = inv3 * sign_b;

            const vec4 row0
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

            if (determinant == 0.0f)
            {
                return mat4 { 1.0f };
            }

            const float inverse_determinant = 1.0f / determinant;

            result[0] *= inverse_determinant;
            result[1] *= inverse_determinant;
            result[2] *= inverse_determinant;
            result[3] *= inverse_determinant;

            return result;
        }

        [[nodiscard]] auto inverse_affine() const noexcept -> mat4
        {
            const auto a00 = _columns[0].x;
            const auto a01 = _columns[1].x;
            const auto a02 = _columns[2].x;

            const auto a10 = _columns[0].y;
            const auto a11 = _columns[1].y;
            const auto a12 = _columns[2].y;

            const auto a20 = _columns[0].z;
            const auto a21 = _columns[1].z;
            const auto a22 = _columns[2].z;

            const auto c00 = a11 * a22 - a12 * a21;
            const auto c01 = a02 * a21 - a01 * a22;
            const auto c02 = a01 * a12 - a02 * a11;

            const auto c10 = a12 * a20 - a10 * a22;
            const auto c11 = a00 * a22 - a02 * a20;
            const auto c12 = a02 * a10 - a00 * a12;

            const auto c20 = a10 * a21 - a11 * a20;
            const auto c21 = a01 * a20 - a00 * a21;
            const auto c22 = a00 * a11 - a01 * a10;

            const auto determinant = a00 * c00 + a01 * c10 + a02 * c20;

            if (determinant == 0.0f)
            {
                return mat4 { 1.0f };
            }

            const auto inv_det = 1.0f / determinant;

            mat4 result { 1.0f };

            result[0].x = c00 * inv_det;
            result[0].y = c10 * inv_det;
            result[0].z = c20 * inv_det;

            result[1].x = c01 * inv_det;
            result[1].y = c11 * inv_det;
            result[1].z = c21 * inv_det;

            result[2].x = c02 * inv_det;
            result[2].y = c12 * inv_det;
            result[2].z = c22 * inv_det;

            const auto tx = _columns[3].x;
            const auto ty = _columns[3].y;
            const auto tz = _columns[3].z;

            result[3].x = -(result[0].x * tx + result[1].x * ty + result[2].x * tz);
            result[3].y = -(result[0].y * tx + result[1].y * ty + result[2].y * tz);
            result[3].z = -(result[0].z * tx + result[1].z * ty + result[2].z * tz);

            return result;
        }

        [[nodiscard]] auto inverse_rigid() const noexcept -> mat4
        {
            mat4 result { 1.0f };

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
        //auto inv_proj  = projection.inverse();

    private:
        vec4 _columns[4]; // TODO use std::array? yes
    };
}