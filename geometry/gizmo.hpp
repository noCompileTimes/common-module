#pragma once

#include "geometry_type.hpp"

namespace geometry
{
    class Gizmo
    {
    public:
        static auto axis(const math::vec3& scale) noexcept // TODO use here a static geometry because we know all the vertices = no allocation
        {
            constexpr auto half = 0.5f;

            const auto x = scale.x * half; constexpr math::vec3 r { 1.0f, 0.0f, 0.0f };
            const auto y = scale.y * half; constexpr math::vec3 g { 0.0f, 1.0f, 0.0f };
            const auto z = scale.z * half; constexpr math::vec3 b { 0.0f, 0.0f, 1.0f };

            return gizmo
            {
                {
                    { { -x, 0.0f, 0.0f }, r },
                    { {  x, 0.0f, 0.0f }, r },

                    { { 0.0f, -y, 0.0f }, g },
                    { { 0.0f,  y, 0.0f }, g },

                    { { 0.0f, 0.0f, -z }, b },
                    { { 0.0f, 0.0f,  z }, b }
                },
                {
                    { 0, 1 },
                    { 2, 3 },
                    { 4, 5 }
                }
            };
        }

        // TODO add a grid function to generate a grid to be put in the middle of the scene?

        Gizmo() = delete;
    };
}