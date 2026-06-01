#pragma once

#include "vec3.hpp"

namespace core::data
{
    struct light
    {
        math::vec3 color;
        float    ambient;
        math::vec3 extra;
    };
}