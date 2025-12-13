#include "column.hpp"

namespace math
{
    auto column::operator+=(const column& other) noexcept -> column&
    {
        data = _mm_add_ps(data, other.data);

        return *this;
    }

    auto column::operator*=(const float value) noexcept -> column&
    {
        data = _mm_mul_ps(data, _mm_set1_ps(value));

        return *this;
    }

    auto column::operator+(const column& other) const noexcept -> column
    {
        return
        {
            .data = _mm_add_ps(data, other.data)
        };
    }

    auto column::operator*(const float value) const noexcept -> column
    {
        return
        {
            .data = _mm_mul_ps(data, _mm_set1_ps(value))
        };
    }
}