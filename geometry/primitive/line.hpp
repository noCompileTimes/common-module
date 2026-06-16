#pragma once

namespace geometry::primitive
{
    struct line // TODO make a generic element for line and triangle / point? seems more than ok
    {
        static constexpr auto size { 2 };

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
    };
}