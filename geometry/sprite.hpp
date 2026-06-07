#pragma once

#include "types.hpp"

#include "math/rect.hpp"

namespace geometry
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

        // TODO rework this - not final
        static auto create(const float width, const float height, const math::vec2& offset) noexcept // TODO use this just when you develop to get the rect
        {
            return create({ { -width * 0.5f + offset.x, -height * 0.5f + offset.y },
                            {  width * 0.5f + offset.x,  height * 0.5f + offset.y } });
        }

        // TODO rework this - not final
        static auto create(const float width, const float height, const math::vec2& pivot, const math::vec2& offset) noexcept
        {
            const auto left   = -width  * pivot.x + offset.x;
            const auto top    = -height * pivot.y + offset.y;
            const auto right  = left + width; // TODO reverse members
            const auto bottom = top + height; // TODO reverse members

            return create({ { left, top }, { right, bottom } });
        }

        Sprite() = delete;
    };
}