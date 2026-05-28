#pragma once

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

        auto operator/=(const float value) noexcept -> vec4&
        {
            data = _mm_div_ps(data, _mm_set1_ps(value));

            return *this;
        }

        // TODO check more if this is a solution, how it looks in glm?
        /*auto operator/=(const float value) noexcept -> vec4&
        {
            return *this *= 1.0f / value;
        }*/

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

        [[nodiscard]] auto operator/(const float value) const noexcept
        {
            return vec4
            {
                .data = _mm_div_ps(data, _mm_set1_ps(value))
            };
        }

        // TODO check more if this is a solution, how it looks in glm?
        /*[[nodiscard]] auto operator/(const float value) const noexcept
        {
            return *this * (1.0f / value);
        }*/

        [[nodiscard]] explicit operator vec3() const noexcept
        {
            return vec3
            {
                x, y, z
            };
        }
    };
}