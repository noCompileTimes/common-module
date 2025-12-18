#include "quat.hpp"

namespace math
{
    auto quat::matrix() const noexcept -> mat4
    {
        mat4  matrix;

        const auto wx = w * x;
        const auto wy = w * y;
        const auto wz = w * z;

        const auto xx = x * x;
        const auto xy = x * y;
        const auto xz = x * z;

        const auto yy = y * y;
        const auto yz = y * z;

        const auto zz = z * z;

        matrix.columns[0].x = 1.0f - 2.0f * (yy + zz);
        matrix.columns[0].y =        2.0f * (xy + wz);
        matrix.columns[0].z =        2.0f * (xz - wy);
        matrix.columns[0].w =        0.0f;

        matrix.columns[1].x =        2.0f * (xy - wz);
        matrix.columns[1].y = 1.0f - 2.0f * (xx + zz);
        matrix.columns[1].z =        2.0f * (yz + wx);
        matrix.columns[1].w =        0.0f;

        matrix.columns[2].x =        2.0f * (xz + wy);
        matrix.columns[2].y =        2.0f * (yz - wx);
        matrix.columns[2].z = 1.0f - 2.0f * (xx + yy);
        matrix.columns[2].w =        0.0f;

        matrix.columns[3].x =        0.0f;
        matrix.columns[3].y =        0.0f;
        matrix.columns[3].z =        0.0f;
        matrix.columns[3].w =        1.0f;

        return matrix;
    }

    auto quat::normalize() noexcept -> void
    {
        if (const auto len = length();
                       len > epsilon)
        {
            const auto i = 1.0f / len;

            w *= i;
            x *= i;
            y *= i;
            z *= i;
        }
    }

    auto quat::length() const noexcept -> float
    {
        return sqrt(squared_length());
    }

    auto quat::squared_length() const noexcept -> float
    {
        return  w * w + x * x + y * y + z * z;
    }

    auto quat::rotation(const vec3& axis, const float radians) noexcept -> void
    {
        const auto     half_angle = radians * 0.5f;
        const auto sin_half_angle = sin(half_angle);

        x = axis.x * sin_half_angle;
        y = axis.y * sin_half_angle;
        z = axis.z * sin_half_angle;

        w = cos(half_angle);
    }
}