#pragma once

namespace core::geometry::element
{
    struct line
    {
        uint32_t a;
        uint32_t b;

        auto operator+(const uint32_t offset) const noexcept
        {
            return line
            {
                a + offset,
                b + offset
            };
        }

        static constexpr auto size { 2 };
    };
}