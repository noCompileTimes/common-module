#pragma once

#include "vec3.hpp"

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
            return  w * w + x * x + y * y + z * z;
        }

        [[nodiscard]] auto length() const noexcept
        {
            return std::sqrt(squared_length());
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
                w * other.w - x * other.x - y * other.y - z * other.z,
                w * other.x + x * other.w + y * other.z - z * other.y,
                w * other.y - x * other.z + y * other.w + z * other.x,
                w * other.z + x * other.y - y * other.x + z * other.w
            };
        }

        auto operator*=(const quat& other) noexcept -> quat&
        {
            return *this =
                   *this * other;
        }

        auto rotation(const vec3& axis, const float radians) noexcept
        {
            const auto angle = radians * 0.5f;
            const auto value = std::sin(angle);

            x = axis.x * value;
            y = axis.y * value;
            z = axis.z * value;

            w = std::cos(angle);
        }
    };
}