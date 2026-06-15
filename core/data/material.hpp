#pragma once

#include "math/vec3.hpp"

namespace core::data
{
    struct material
    {
        math::vec3 albedo_color; // TODO just color as name at some point? - applied also in the shaders
    };
}