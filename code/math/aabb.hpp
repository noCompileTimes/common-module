#pragma once

#include "vec3.hpp"

namespace math
{
    struct aabb
    {
        vec3 min;
        vec3 max;
    };
}