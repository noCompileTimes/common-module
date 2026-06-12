#pragma once

#include "vec3.hpp"

#include <intrin.h>

namespace math
{
    struct alignas(16) vec4
    {
        union
        {
            __m128 data;

            struct
            {
                float x;
                float y;
                float z;
                float w;
            };
        };

        [[nodiscard]] constexpr explicit operator vec3() const noexcept
        {
            return
            {
                x, y, z
            };
        }

        [[nodiscard]] constexpr vec4 operator+(const vec4& other) const noexcept
        {
            return
            {
                _mm_add_ps(data, other.data)
            };
        }

        [[nodiscard]] constexpr vec4 operator-(const vec4& other) const noexcept
        {
            return
            {
                _mm_sub_ps(data, other.data)
            };
        }

        [[nodiscard]] constexpr vec4 operator*(const vec4& other) const noexcept
        {
            return
            {
                _mm_mul_ps(data, other.data)
            };
        }

        [[nodiscard]] constexpr vec4 operator*(const float value) const noexcept
        {
            return
            {
                _mm_mul_ps(data, _mm_set1_ps(value))
            };
        }

        [[nodiscard]] constexpr vec4 operator/(const float value) const noexcept
        {
            return
            {
                _mm_div_ps(data, _mm_set1_ps(value))
            };
        }

        constexpr vec4& operator+=(const vec4& other) noexcept
        {
            data = _mm_add_ps(data, other.data);

            return *this;
        }

        constexpr vec4& operator*=(const float value) noexcept
        {
            data = _mm_mul_ps(data, _mm_set1_ps(value));

            return *this;
        }

        constexpr vec4& operator/=(const float value) noexcept
        {
            data = _mm_div_ps(data, _mm_set1_ps(value));

            return *this;
        }
    };
}