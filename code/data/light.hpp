#pragma once

#include "math/vec3.hpp"

namespace data
{
    struct light
    {
        math::vec3 color;
        float    ambient;
        math::vec3 extra;
    };
}