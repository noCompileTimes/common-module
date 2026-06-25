#pragma once

namespace mesh::primitive
{
    struct triangle
    {
        uint32_t a;
        uint32_t b;
        uint32_t c;

        auto operator+(const uint32_t offset) const noexcept
        {
            return triangle
            {
                a + offset,
                b + offset,
                c + offset
            };
        }

        static constexpr auto size { 3 };
    };
}