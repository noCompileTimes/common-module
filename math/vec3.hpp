#pragma once

#include "functions.hpp"

namespace math
{
    struct vec3
    {
        float x;
        float y;
        float z;

        [[nodiscard]] constexpr float length() const noexcept
        {
            return sqrt(length_squared());
        }

        [[nodiscard]] constexpr float length_squared() const noexcept
        {
            return x * x + y * y + z * z;
        }

        [[nodiscard]] constexpr vec3 operator+(const vec3& other) const noexcept
        {
            return
            {
                x + other.x,
                y + other.y,
                z + other.z
            };
        }

        [[nodiscard]] constexpr vec3 operator-(const vec3& other) const noexcept
        {
            return
            {
                x - other.x,
                y - other.y,
                z - other.z
            };
        }

        [[nodiscard]] constexpr vec3 operator*(const vec3& other) const noexcept
        {
            return
            {
                x * other.x,
                y * other.y,
                z * other.z
            };
        }

        [[nodiscard]] constexpr vec3 operator*(const float value) const noexcept
        {
            return
            {
                x * value,
                y * value,
                z * value
            };
        }

        [[nodiscard]] constexpr static float dot(const vec3& a, const vec3& b) noexcept
        {
            return a.x * b.x + a.y * b.y + a.z * b.z;
        }

        [[nodiscard]] constexpr static vec3 cross(const vec3& a, const vec3& b) noexcept
        {
            return
            {
                a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x
            };
        }

        constexpr vec3& operator+=(const vec3& other) noexcept
        {
            x += other.x;
            y += other.y;
            z += other.z;

            return *this;
        }

        constexpr vec3& operator-=(const vec3& other) noexcept
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;

            return *this;
        }

        constexpr vec3& operator*=(const float value) noexcept
        {
            x *= value;
            y *= value;
            z *= value;

            return *this;
        }

        constexpr void normalize() noexcept
        {
            if (const auto magnitude = length(); magnitude > epsilon)
            {
                const auto inverse = 1.0f / magnitude;

                x *= inverse;
                y *= inverse;
                z *= inverse;
            }
        }
    };
}