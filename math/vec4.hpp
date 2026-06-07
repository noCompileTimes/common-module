#pragma once

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

        [[nodiscard]] auto operator+(const vec4& other) const noexcept
        {
            return vec4
            {
                _mm_add_ps(data, other.data)
            };
        }

        [[nodiscard]] auto operator-(const vec4& other) const noexcept
        {
            return vec4
            {
                _mm_sub_ps(data, other.data)
            };
        }

        [[nodiscard]] auto operator*(const vec4& other) const noexcept
        {
            return vec4
            {
                _mm_mul_ps(data, other.data)
            };
        }

        [[nodiscard]] auto operator*(const float value) const noexcept
        {
            return vec4
            {
                _mm_mul_ps(data, _mm_set1_ps(value))
            };
        }

        [[nodiscard]] auto operator/(const float value) const noexcept
        {
            return vec4
            {
                _mm_div_ps(data, _mm_set1_ps(value))
            };
        }

        // TODO check more if this is a solution
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

        // TODO check more if this is a solution
        /*auto operator/=(const float value) noexcept -> vec4&
        {
            return *this *= 1.0f / value;
        }*/
    };
}