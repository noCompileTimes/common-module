#pragma once

namespace core::vertex
{                    // TODO add the binding somewhere around here
    struct attribute // TODO move this back to graphics in opengl folder? it makes sense to be there?
    {
        uint32_t index;
        uint32_t start;
        uint32_t  size;
        uint32_t  type;
    };
}