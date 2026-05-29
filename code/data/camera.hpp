#pragma once

#include "math/mat4.hpp"

namespace data
{
    struct camera
    {
        math::mat4 view       { 1.0f };
        math::mat4 projection { 1.0f };
    };
}