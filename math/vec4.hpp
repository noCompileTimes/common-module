#pragma once

#include "vec3.hpp"

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

        [[nodiscard]] constexpr auto operator+(const vec4& other) const noexcept
        {
            return vec4
            {
                _mm_add_ps(data, other.data)
            };
        }

        [[nodiscard]] constexpr auto operator-(const vec4& other) const noexcept
        {
            return vec4
            {
                _mm_sub_ps(data, other.data)
            };
        }

        [[nodiscard]] constexpr auto operator*(const vec4& other) const noexcept
        {
            return vec4
            {
                _mm_mul_ps(data, other.data)
            };
        }

        [[nodiscard]] constexpr auto operator*(const float value) const noexcept
        {
            return vec4
            {
                _mm_mul_ps(data, _mm_set1_ps(value))
            };
        }

        [[nodiscard]] constexpr auto operator/(const float value) const noexcept
        {
            return vec4
            {
                _mm_div_ps(data, _mm_set1_ps(value))
            };
        }

        constexpr auto& operator+=(const vec4& other) noexcept // TODO change everywhere with self? and auto&
        {
            data = _mm_add_ps(data, other.data);

            return *this;
        }

        constexpr auto& operator-=(const vec4& other) noexcept
        {
            data = _mm_sub_ps(data, other.data);

            return *this;
        }

        constexpr auto& operator*=(const vec4& other) noexcept
        {
            data = _mm_mul_ps(data, other.data);

            return *this;
        }

        constexpr auto& operator*=(const float value) noexcept
        {
            data = _mm_mul_ps(data, _mm_set1_ps(value));

            return *this;
        }

        constexpr auto& operator/=(const float value) noexcept
        {
            data = _mm_div_ps(data, _mm_set1_ps(value));

            return *this;
        }

        [[nodiscard]] constexpr explicit operator vec3() const noexcept
        {
            return
            {
                x, y, z
            };
        }
    };
}