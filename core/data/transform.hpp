#pragma once

#include "math/mat4.hpp"

namespace core::data
{
    struct transform
    {
        math::mat4 model { 1.0f };
    };
}