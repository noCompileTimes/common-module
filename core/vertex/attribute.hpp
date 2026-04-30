#pragma once

namespace core::vertex
{
    struct attribute // TODO move this back to graphics? it makes sense to be there???
    {
        uint32_t index;
        uint32_t start;
        uint32_t  size;
        uint32_t  type;
    };
}