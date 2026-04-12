#pragma once

namespace core::vertex::type
{
    struct editor
    {
        math::vec3 position;
        math::vec3 extra; // can be either color or normal
    };
}