#pragma once

namespace core::data
{
    struct camera
    {
        math::mat4 view       { 1.0f };
        math::mat4 projection { 1.0f };
    };
}