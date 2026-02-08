#pragma once

#include "math/vec2.hpp"
#include "math/vec3.hpp"

namespace core::vertex::type
{
    struct model
    {
        math::vec3 position;
        math::vec2 texcoord;
        math::vec3 normal;
    };
}