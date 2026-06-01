#pragma once

#include "rect.hpp"

#include "geometry_types.hpp"

namespace core::geometry
{
    class Sprite
    {
    public:
        static auto create(const math::rect& position) noexcept
        {
            return sprite
            {
                {
                    {   position.min,                     { 0.0f, 1.0f } },
                    { { position.max.x, position.min.y }, { 1.0f, 1.0f } },
                    {   position.max,                     { 1.0f, 0.0f } },
                    { { position.min.x, position.max.y }, { } }
                },
                {
                    { 0, 2, 1 },
                    { 0, 3, 2 }
                }
            };
        }

        static auto create(const uint32_t width, const uint32_t height) noexcept
        {
            return create({ { }, static_cast<float>(width), static_cast<float>(height) });
        }

        // TODO some version to accept a pivot version? seems usefull to not do the * 0.5f outside the function
        // TODO some version to accept an offset version? seems usefull to not do add the offset each time in the rendering part

        Sprite() = delete;
    };
}