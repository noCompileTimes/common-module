#pragma once

#include "math/rgb.hpp"
#include "math/vec3.hpp"

namespace core::data
{
    struct light
    {
        math::rgb  color;
        float    ambient;
        math::vec3 extra;
    };
}