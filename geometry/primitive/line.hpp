#pragma once

namespace geometry::primitive
{
    struct line // TODO use this around
    {
        static constexpr auto elements { 2 };

        uint32_t a;
        uint32_t b;
    };
}