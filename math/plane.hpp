#pragma once

#include "vec3.hpp"

namespace math
{
    struct plane
    {
        vec3  normal;
        float distance;
    };
}