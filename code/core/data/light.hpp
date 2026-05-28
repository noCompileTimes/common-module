#pragma once

#include "math/rgb.hpp"

namespace core::data
{
    struct light
    {
        math::rgb  color;
        float    ambient;
        math::vec3 extra;
    };
}