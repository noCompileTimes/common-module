#pragma once

#include "math/vec3.hpp" // TODO remove redundant include

#include "geometry_type.hpp"

namespace geometry
{
    class Gizmo
    {
    public:
        static auto axis(const math::vec3& scale) noexcept // TODO use here a static geometry because we know all the vertices = no allocation
        {
            constexpr auto value = 0.5f;

            const auto hx = scale.x * value; constexpr math::vec3 r { 1.0f, 0.0f, 0.0f };
            const auto hy = scale.y * value; constexpr math::vec3 g { 0.0f, 1.0f, 0.0f };
            const auto hz = scale.z * value; constexpr math::vec3 b { 0.0f, 0.0f, 1.0f };

            return gizmo
            {
                {
                    { {  -hx,  0.0f,  0.0f }, r },
                    { {   hx,  0.0f,  0.0f }, r },
                    { { 0.0f,   -hy,  0.0f }, g },
                    { { 0.0f,    hy,  0.0f }, g },
                    { { 0.0f,  0.0f,   -hz }, b },
                    { { 0.0f,  0.0f,    hz }, b }
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