#pragma once

#include "functions.hpp"

namespace math
{
    struct vec3
    {
        float x;
        float y;
        float z;

        [[nodiscard]] constexpr auto length_squared() const noexcept
        {
            return x * x + y * y + z * z;
        }

        [[nodiscard]] constexpr auto length() const noexcept
        {
            return sqrt(length_squared());
        }

        [[nodiscard]] constexpr auto operator+(const vec3& other) const noexcept
        {
            return vec3
            {
                x + other.x,
                y + other.y,
                z + other.z
            };
        }

        [[nodiscard]] constexpr auto operator-(const vec3& other) const noexcept
        {
            return vec3
            {
                x - other.x,
                y - other.y,
                z - other.z
            };
        }

        [[nodiscard]] constexpr auto operator*(const vec3& other) const noexcept
        {
            return vec3
            {
                x * other.x,
                y * other.y,
                z * other.z
            };
        }

        [[nodiscard]] constexpr auto operator*(const float value) const noexcept
        {
            return vec3
            {
                x * value,
                y * value,
                z * value
            };
        }

        [[nodiscard, maybe_unused]] static constexpr auto dot(const vec3& a, const vec3& b) noexcept
        {
            return a.x * b.x + a.y * b.y + a.z * b.z;
        }

        [[nodiscard, maybe_unused]] static constexpr auto cross(const vec3& a, const vec3& b) noexcept
        {
            return vec3
            {
                a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x
            };
        }

        constexpr auto& operator+=(const vec3& other) noexcept
        {
            x += other.x;
            y += other.y;
            z += other.z;

            return *this;
        }

        constexpr auto& operator-=(const vec3& other) noexcept
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;

            return *this;
        }

        constexpr auto& operator*=(const float value) noexcept
        {
            x *= value;
            y *= value;
            z *= value;

            return *this;
        }

        [[maybe_unused]] constexpr auto normalize() noexcept
        {
            if (const auto magnitude = length(); magnitude > tolerance)
            {
                const auto inverse = 1.0f / magnitude;

                x *= inverse;
                y *= inverse;
                z *= inverse;
            }
        }
    };
}