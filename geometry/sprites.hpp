#pragma once

#include "math/rect.hpp"

#include "geometry/mesh.hpp"

#include "primitive/triangle.hpp"

namespace geometry
{
    class Sprites
    {
    public:
        static auto create(const math::rect& position) noexcept
        {
            return mesh<vertex::sprite, primitive::triangle>
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

        Sprites() = delete;
    };
}