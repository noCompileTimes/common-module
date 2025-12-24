#pragma once

namespace core::vertex
{
    struct attribute
    {
        uint32_t  index { };
        uint32_t   size { };
        uint32_t   type { };
        uint32_t offset { };
    };
}