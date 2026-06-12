#pragma once

#include "mat4.hpp"

namespace math
{
    struct quat
    {
        float w;
        float x;
        float y;
        float z;

        [[nodiscard]] constexpr float length() const noexcept
        {
            return sqrt(length_squared());
        }

        [[nodiscard]] constexpr float length_squared() const noexcept
        {
            return w * w + x * x + y * y + z * z;
        }

        [[nodiscard]] constexpr explicit operator mat4() const noexcept
        {
            const auto wx = w * x;
            const auto wy = w * y;
            const auto wz = w * z;

            const auto xx = x * x;
            const auto xy = x * y;
            const auto xz = x * z;

            const auto yy = y * y;
            const auto yz = y * z;

            const auto zz = z * z;

            mat4 matrix;

            matrix[0].x = 1.0f - 2.0f * (yy + zz);
            matrix[0].y =        2.0f * (xy + wz);
            matrix[0].z =        2.0f * (xz - wy);
            matrix[0].w =        0.0f;

            matrix[1].x =        2.0f * (xy - wz);
            matrix[1].y = 1.0f - 2.0f * (xx + zz);
            matrix[1].z =        2.0f * (yz + wx);
            matrix[1].w =        0.0f;

            matrix[2].x =        2.0f * (xz + wy);
            matrix[2].y =        2.0f * (yz - wx);
            matrix[2].z = 1.0f - 2.0f * (xx + yy);
            matrix[2].w =        0.0f;

            matrix[3].x =        0.0f;
            matrix[3].y =        0.0f;
            matrix[3].z =        0.0f;
            matrix[3].w =        1.0f;

            return matrix;
        }

        [[nodiscard]] constexpr quat operator*(const quat& other) const noexcept
        {
            return
            {
                w * other.w - x * other.x - y * other.y - z * other.z, // TODO use simd here?
                w * other.x + x * other.w + y * other.z - z * other.y,
                w * other.y - x * other.z + y * other.w + z * other.x,
                w * other.z + x * other.y - y * other.x + z * other.w
            };
        }

        static constexpr quat rotation(const vec3& axis, const float radians) noexcept
        {
            const auto angle = radians * 0.5f;
            const auto value = sin(angle);

            return
            {
                cos(angle),
                axis.x * value,
                axis.y * value,
                axis.z * value
            };
        }

        constexpr quat& operator*=(const quat& other) noexcept
        {
            return *this =
                   *this * other;
        }

        constexpr void normalize() noexcept
        {
            if (const auto magnitude = length(); magnitude > tolerance)
            {
                const auto inverse = 1.0f / magnitude;

                w *= inverse;
                x *= inverse;
                y *= inverse;
                z *= inverse;
            }
        }
    };
}