#pragma once

namespace math
{
    struct column
    {
        auto operator+=(const column& other) noexcept -> column&
        {
            data = _mm_add_ps(data, other.data);

            return *this;
        }

        auto operator*=(const float value) noexcept -> column&
        {
            data = _mm_mul_ps(data, _mm_set1_ps(value));

            return *this;
        }

        [[nodiscard]] auto operator+(const column& other) const noexcept -> column
        {
            return
            {
                .data = _mm_add_ps(data, other.data)
            };
        }

        [[nodiscard]] auto operator*(const float value) const noexcept -> column
        {
            return
            {
                .data = _mm_mul_ps(data, _mm_set1_ps(value))
            };
        }

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
    };
}