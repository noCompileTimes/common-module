#pragma once

namespace math
{
    struct vec3
    {
        float x;
        float y;
        float z;

        auto normalize() noexcept -> void
        {
            if (const auto len = length();
                           len > epsilon)
            {
                const auto i = 1.0f / len;

                x *= i;
                y *= i;
                z *= i;
            }
        }

        [[nodiscard]] auto length() const noexcept -> float
        {
            return sqrt(squared_length());
        }

        [[nodiscard]] auto squared_length() const noexcept -> float
        {
            return x * x + y * y + z * z;
        }

        [[nodiscard]] static auto cross(const vec3& a, const vec3& b) noexcept -> vec3
        {
            return
            {
                a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x
            };
        }

        static auto dot(const vec3& a, const vec3& b) noexcept -> float
        {
            return a.x * b.x +
                   a.y * b.y +
                   a.z * b.z;
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

        [[nodiscard]] auto operator+(const vec3& other) const noexcept -> vec3
        {
            return
            {
                x + other.x,
                y + other.y,
                z + other.z
            };
        }

        [[nodiscard]] auto operator-(const vec3& other) const noexcept -> vec3
        {
            return
            {
                x - other.x,
                y - other.y,
                z - other.z
            };
        }

        [[nodiscard]] auto operator*(const float value) const noexcept -> vec3
        {
            return
            {
                x * value,
                y * value,
                z * value
            };
        }
    };
}