#pragma once

namespace geometry::primitive
{
    struct triangle
    {
        uint32_t a;
        uint32_t b;
        uint32_t c;

        static constexpr auto size { 3 };

        auto operator+(const uint32_t offset) const noexcept
        {
            return triangle // TODO maybe use simd here with vec4?
            {
                a + offset,
                b + offset,
                c + offset
            };
        }
    };
}