#pragma once

#include "math/vec3.hpp"

namespace core::vertex::type
{
    struct editor
    {
        math::vec3 position;
        math::vec3 extra; // INFO can be either color or normal
    };
}