#pragma once

#include "vec2.hpp"
#include "vec3.hpp"

namespace core::geometry::vertex
{
    struct model
    {
        math::vec3 position;
        math::vec3 normal;
        math::vec2 texcoord;
    };
}