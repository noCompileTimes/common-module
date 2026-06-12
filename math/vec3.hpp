#pragma once

#include "functions.hpp"

namespace math
{
    struct vec3
    {
        float x;
        float y;
        float z;

        [[nodiscard]] auto length_squared() const noexcept
        {
            return x * x + y * y + z * z;
        }

        [[nodiscard]] auto length() const noexcept
        {
            return sqrt(length_squared());
        }

        [[nodiscard]] auto normalize() noexcept
        {
            if (const auto magnitude = length(); magnitude > epsilon)
            {
                const auto inverse = 1.0f / magnitude;

                x *= inverse;
                y *= inverse;
                z *= inverse;
            }
        }

        [[nodiscard]] auto operator+(const vec3& other) const noexcept
        {
            return vec3
            {
                x + other.x,
                y + other.y,
                z + other.z
            };
        }

        [[nodiscard]] auto operator-(const vec3& other) const noexcept
        {
            return vec3
            {
                x - other.x,
                y - other.y,
                z - other.z
            };
        }

        [[nodiscard]] auto operator*(const vec3& other) const noexcept
        {
            return vec3
            {
                x * other.x,
                y * other.y,
                z * other.z
            };
        }

        [[nodiscard]] auto operator*(const float value) const noexcept
        {
            return vec3
            {
                x * value,
                y * value,
                z * value
            };
        }

        auto operator+=(const vec3& other) noexcept -> vec3&
        {
            x += other.x;
            y += other.y;
            z += other.z;

            return *this;
        }

        auto operator-=(const vec3& other) noexcept -> vec3&
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;

            return *this;
        }

        auto operator*=(const float value) noexcept -> vec3&
        {
            x *= value;
            y *= value;
            z *= value;

            return *this;
        }

        [[nodiscard]] static auto cross(const vec3& a, const vec3& b) noexcept
        {
            return vec3
            {
                a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x
            };
        }

        [[nodiscard]] static auto dot(const vec3& a, const vec3& b) noexcept
        {
            return a.x * b.x +
                   a.y * b.y +
                   a.z * b.z;
        }
    };
}