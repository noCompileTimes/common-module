#pragma once

namespace core::vertex
{
    struct attribute
    {
        std::uint32_t index;
        std::uint32_t start;
        std::uint32_t  size;
        std::uint32_t  type;
    };
}