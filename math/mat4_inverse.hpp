#pragma once

namespace math
{
    [[nodiscard]] static auto inverse(const mat4& mat) noexcept
    {
        const auto m00 = mat[0].x;
        const auto m01 = mat[0].y;
        const auto m02 = mat[0].z;
        const auto m03 = mat[0].w;

        const auto m10 = mat[1].x;
        const auto m11 = mat[1].y;
        const auto m12 = mat[1].z;
        const auto m13 = mat[1].w;

        const auto m20 = mat[2].x;
        const auto m21 = mat[2].y;
        const auto m22 = mat[2].z;
        const auto m23 = mat[2].w;

        const auto m30 = mat[3].x;
        const auto m31 = mat[3].y;
        const auto m32 = mat[3].z;
        const auto m33 = mat[3].w;

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

        const auto inv0 = vec1 * fac0 - vec2 * fac1 + vec3 * fac2;
        const auto inv1 = vec0 * fac0 - vec2 * fac3 + vec3 * fac4;
        const auto inv2 = vec0 * fac1 - vec1 * fac3 + vec3 * fac5;
        const auto inv3 = vec0 * fac2 - vec1 * fac4 + vec2 * fac5;

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
            mat[0].x * row0.x +
            mat[0].y * row0.y +
            mat[0].z * row0.z +
            mat[0].w * row0.w;

        if (std::abs(determinant) < epsilon)
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

    [[nodiscard]] static auto inverse_affine(const mat4& mat) noexcept
    {
        const auto a00 = mat[0].x;
        const auto a01 = mat[1].x;
        const auto a02 = mat[2].x;

        const auto a10 = mat[0].y;
        const auto a11 = mat[1].y;
        const auto a12 = mat[2].y;

        const auto a20 = mat[0].z;
        const auto a21 = mat[1].z;
        const auto a22 = mat[2].z;

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

        if (std::abs(determinant) < epsilon)
        {
            return mat4 { 1.0f };
        }

        const auto inv_det = 1.0f / determinant;

        mat4 result { 1.0f }; // TODO use the uninitialized constructor and put the diagonals with 1.0f

        result[0].x = c00 * inv_det;
        result[0].y = c10 * inv_det;
        result[0].z = c20 * inv_det;

        result[1].x = c01 * inv_det;
        result[1].y = c11 * inv_det;
        result[1].z = c21 * inv_det;

        result[2].x = c02 * inv_det;
        result[2].y = c12 * inv_det;
        result[2].z = c22 * inv_det;

        const auto tx = mat[3].x;
        const auto ty = mat[3].y;
        const auto tz = mat[3].z;

        result[3].x = -(result[0].x * tx + result[1].x * ty + result[2].x * tz);
        result[3].y = -(result[0].y * tx + result[1].y * ty + result[2].y * tz);
        result[3].z = -(result[0].z * tx + result[1].z * ty + result[2].z * tz);

        return result;
    }

    [[nodiscard]] static auto inverse_rigid(const mat4& mat) noexcept
    {
        mat4 result { 1.0f }; // TODO use the uninitialized constructor and put the diagonals with 1.0f

        result[0].x = mat[0].x;
        result[0].y = mat[1].x;
        result[0].z = mat[2].x;

        result[1].x = mat[0].y;
        result[1].y = mat[1].y;
        result[1].z = mat[2].y;

        result[2].x = mat[0].z;
        result[2].y = mat[1].z;
        result[2].z = mat[2].z;

        const auto tx = mat[3].x;
        const auto ty = mat[3].y;
        const auto tz = mat[3].z;

        result[3].x = -(result[0].x * tx + result[1].x * ty + result[2].x * tz);
        result[3].y = -(result[0].y * tx + result[1].y * ty + result[2].y * tz);
        result[3].z = -(result[0].z * tx + result[1].z * ty + result[2].z * tz);

        return result;
    }

    //auto inv_model = model.inverse_affine();
    //auto inv_view  = view.inverse_rigid();
    //auto inv_proj  = projection.inverse(); // TODO for ortho use the affine inverse
}