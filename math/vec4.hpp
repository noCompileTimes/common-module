#pragma once

#include <intrin.h>

namespace math
{
    struct alignas(16) vec4
    {
        union
        {
            struct
            {
                float x;
                float y;
                float z;
                float w;
            };

            __m128 data;
        };

        auto operator+=(const vec4& other) noexcept -> vec4&
        {
            data = _mm_add_ps(data, other.data);

            return *this;
        }

        auto operator*=(const float value) noexcept -> vec4&
        {
            data = _mm_mul_ps(data, _mm_set1_ps(value));

            return *this;
        }

        [[nodiscard]] auto operator+(const vec4& other) const noexcept
        {
            return vec4
            {
                .data = _mm_add_ps(data, other.data)
            };
        }

        [[nodiscard]] auto operator-(const vec4& other) const noexcept
        {
            return vec4
            {
                .data = _mm_sub_ps(data, other.data)
            };
        }

        [[nodiscard]] auto operator*(const vec4& other) const noexcept
        {
            return vec4
            {
                .data = _mm_mul_ps(data, other.data)
            };
        }

        [[nodiscard]] auto operator*(const float value) const noexcept
        {
            return vec4
            {
                .data = _mm_mul_ps(data, _mm_set1_ps(value))
            };
        }
    };
}