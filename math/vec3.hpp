#pragma once

namespace math
{
    struct vec3
    {
        auto      normalize() noexcept -> void;

        auto         length() const noexcept -> float;
        auto squared_length() const noexcept -> float;

        static auto cross(const vec3& a, const vec3& b) noexcept -> vec3;
        static auto   dot(const vec3& a, const vec3& b) noexcept -> float;

        auto operator+=(const vec3& other) noexcept -> vec3&;
        auto operator-=(const vec3& other) noexcept -> vec3&;
        auto operator*=(float       value) noexcept -> vec3&;

        [[nodiscard]] auto operator+(const vec3& other) const noexcept -> vec3;
        [[nodiscard]] auto operator-(const vec3& other) const noexcept -> vec3;
        [[nodiscard]] auto operator*(float       value) const noexcept -> vec3;

        float x;
        float y;
        float z;
    };
}