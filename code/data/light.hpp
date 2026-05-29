#pragma once

#include "math/vec3.hpp"

namespace code::data
{
    struct light
    {
        math::vec3 color;
        float    ambient;
        math::vec3 extra;
    };
}