#pragma once

#include "geometry.hpp"

#include "vertex/basic.hpp"

#include "primitive/line.hpp"

namespace geometry
{
    class Gizmo
    {
    public:
        static auto axis(const math::vec3& scale) noexcept // TODO use here a static geometry because we know all the vertices = no allocation
        {
            constexpr auto half = 0.5f;

            const auto half_x = half * scale.x; constexpr math::vec3 r { 1.0f, 0.0f, 0.0f };
            const auto half_y = half * scale.y; constexpr math::vec3 g { 0.0f, 1.0f, 0.0f };
            const auto half_z = half * scale.z; constexpr math::vec3 b { 0.0f, 0.0f, 1.0f };

            return geometry<vertex::basic, primitive::line>
            {
                {
                    { -half_x, 0.0f,   0.0f,   r },
                    {  half_x, 0.0f,   0.0f,   r },
                    {  0.0f,  -half_y, 0.0f,   g },
                    {  0.0f,   half_y, 0.0f,   g },
                    {  0.0f,   0.0f,  -half_z, b },
                    {  0.0f,   0.0f,   half_z, b }
                },
                {
                    { 0, 1 }, // x
                    { 2, 3 }, // y
                    { 4, 5 }  // z
                }
            };
        }

        // TODO add a grid function to generate a grid to be put in the middle of the scene?

        Gizmo() = delete;
    };
}