#pragma once

namespace math
{
    struct quat
    {
        float w;
        float x;
        float y;
        float z;

        [[nodiscard]] auto squared_length() const noexcept
        {
            return w * w + x * x + y * y + z * z;
        }

        [[nodiscard]] auto length() const noexcept
        {
            return sqrt(squared_length());
        }

        [[nodiscard]] auto normalize() noexcept
        {
            if (const auto magnitude = this->length(); magnitude > epsilon)
            {
                const auto inverse = 1.0f / magnitude;

                w *= inverse;
                x *= inverse;
                y *= inverse;
                z *= inverse;
            }
        }

        [[nodiscard]] auto operator*(const quat& other) const noexcept
        {
            return quat
            {
                w * other.w - x * other.x - y * other.y - z * other.z, // TODO use simd here?
                w * other.x + x * other.w + y * other.z - z * other.y,
                w * other.y - x * other.z + y * other.w + z * other.x,
                w * other.z + x * other.y - y * other.x + z * other.w
            };
        }

        auto rotation(const vec3& axis, const float radians) noexcept
        {
            const auto angle = radians * 0.5f;
            const auto value = sin(angle);

            x = axis.x * value;
            y = axis.y * value;
            z = axis.z * value;

            w = cos(angle);
        }

        auto operator*=(const quat& other) noexcept -> quat&
        {
            return *this =
                   *this * other;
        }

        [[nodiscard]] explicit operator mat4() const noexcept
        {
            mat4 matrix;

            const auto wx = w * x;
            const auto wy = w * y;
            const auto wz = w * z;

            const auto xx = x * x;
            const auto xy = x * y;
            const auto xz = x * z;

            const auto yy = y * y;
            const auto yz = y * z;

            const auto zz = z * z;

            matrix[0].x = 1.0f - 2.0f * (yy + zz); // TODO it seems that many values are the same as the identity matrix, maybe use the mat4 { 1.0f }?
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
    };
}