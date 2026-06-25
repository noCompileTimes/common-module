#pragma once

namespace mesh::primitive
{
    struct line // TODO make a generic element for line and triangle / point? seems more than ok
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