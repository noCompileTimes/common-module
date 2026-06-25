#pragma once

#include "math/vec2.hpp"
#include "math/vec3.hpp"

namespace mesh::vertex
{
    struct model
    {
        math::vec3 position;
        math::vec3 normal;
        math::vec2 texcoord;
    };
}