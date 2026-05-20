#pragma once

#include "math/plane.hpp"
#include "math/vec3.hpp" // TODO remove redundant include

#include "geometry/mesh.hpp"
#include "geometry/primitive/line.hpp"

namespace geometry
{
    class Primitives
    {
    public:
        static auto create_circle(const uint32_t segments, const float radius, const math::plane::orientation plane, const math::vec3& color) noexcept
        {
            mesh<vertex::basic, primitive::line> mesh; mesh.reserve(segments, segments * 2);

            const auto t = 2.0f * math::pi / static_cast<float>(segments);

            for (auto i = 0; i < segments; ++i)
            {
                const auto a = static_cast<float>(i) * t;

                const auto c = radius * math::cos(a);
                const auto s = radius * math::sin(a);

                switch (plane)
                {
                    case math::plane::orientation::xy:
                    {
                        mesh.vertices.emplace_back(math::vec3 { c, s, 0.0f }, color);
                        break;
                    }
                    case math::plane::orientation::xz:
                    {
                        mesh.vertices.emplace_back(math::vec3 { c, 0.0f, s }, color);
                        break;
                    }
                    case math::plane::orientation::yz:
                    {
                        mesh.vertices.emplace_back(math::vec3 { 0.0f, c, s }, color);
                        break;
                    }
                    default:
                        return mesh;
                }
            }

            for (auto i = 0; i < segments; ++i)
            {
                mesh.elements.emplace_back(i, (i + 1) % segments);
            }

            return mesh;
        }

        static auto create_bounding_sphere(const uint32_t segments, const float radius, const math::vec3& color) noexcept // TODO move to gizmos
        {
            mesh<vertex::basic, primitive::line> mesh;

            mesh.append(create_circle(segments, radius, math::plane::orientation::xy, color));
            mesh.append(create_circle(segments, radius, math::plane::orientation::xz, color));
            mesh.append(create_circle(segments, radius, math::plane::orientation::yz, color));

            return mesh;
        }

        static auto create_bounding_box(const math::vec3& scale, const math::vec3& color) noexcept // TODO move to gizmos - and rename it without bounding
        {                                                                                          // TODO use here a static geometry because we know all the vertices = no allocation
            constexpr auto value = 0.5f;

            const auto hx = scale.x * value;
            const auto hy = scale.y * value;
            const auto hz = scale.z * value;

            return mesh
            {
                {
                    { { -hx, -hy, -hz }, color },
                    { {  hx, -hy, -hz }, color },
                    { {  hx,  hy, -hz }, color },
                    { { -hx,  hy, -hz }, color },
                    { { -hx, -hy,  hz }, color },
                    { {  hx, -hy,  hz }, color },
                    { {  hx,  hy,  hz }, color },
                    { { -hx,  hy,  hz }, color }
                },
                {
                    0, 1,  1, 2,  2, 3,  3, 0,
                    4, 5,  5, 6,  6, 7,  7, 4,
                    0, 4,  1, 5,  2, 6,  3, 7
                }
            };
        }

        static auto create_axis(const math::vec3& scale) noexcept // TODO maybe move axis in some other file/struct?
        {                                                         // TODO use here a static geometry because we know all the vertices = no allocation
            constexpr auto value = 0.5f;                          // TODO move to gizmos

            const auto hx = scale.x * value; constexpr math::vec3 r { 1.0f, 0.0f, 0.0f };
            const auto hy = scale.y * value; constexpr math::vec3 g { 0.0f, 1.0f, 0.0f };
            const auto hz = scale.z * value; constexpr math::vec3 b { 0.0f, 0.0f, 1.0f };

            return mesh<vertex::basic, primitive::line>
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

        Primitives() = delete;
    };
}