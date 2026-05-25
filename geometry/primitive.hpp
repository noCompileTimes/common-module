#pragma once

#include "math/plane.hpp"
#include "math/vec3.hpp" // TODO remove redundant include

#include "primitive/line.hpp"

#include "geometry_type.hpp"

namespace geometry
{
    class Primitive
    {
    public:
        static auto circle(const uint32_t segments, const float radius, const math::plane::orientation plane, const math::vec3& color) noexcept
        {
            geometry<vertex::basic, primitive::line> geometry; geometry.reserve(segments, segments * 2);

            const auto t = 2.0f * math::pi / static_cast<float>(segments);

            for (auto i = 0; i < segments; ++i)
            {
                const auto a = static_cast<float>(i) * t;

                const auto c = radius * std::cos(a);
                const auto s = radius * std::sin(a);

                switch (plane)
                {
                    case math::plane::orientation::xy:
                    {
                        geometry.vertices.emplace_back(math::vec3 { c, s, 0.0f }, color);
                        break;
                    }
                    case math::plane::orientation::xz:
                    {
                        geometry.vertices.emplace_back(math::vec3 { c, 0.0f, s }, color);
                        break;
                    }
                    case math::plane::orientation::yz:
                    {
                        geometry.vertices.emplace_back(math::vec3 { 0.0f, c, s }, color);
                        break;
                    }
                    default:
                        return geometry;
                }
            }

            for (auto i = 0; i < segments; ++i)
            {
                geometry.elements.emplace_back(i, (i + 1) % segments);
            }

            return geometry;
        }

        static auto bounding_sphere(const uint32_t segments, const float radius, const math::vec3& color) noexcept // TODO move to gizmos
        {
            geometry<vertex::basic, primitive::line> geometry;

            geometry.append(circle(segments, radius, math::plane::orientation::xy, color));
            geometry.append(circle(segments, radius, math::plane::orientation::xz, color));
            geometry.append(circle(segments, radius, math::plane::orientation::yz, color));

            return geometry;
        }

        static auto bounding_box(const math::vec3& scale, const math::vec3& color) noexcept // TODO move to gizmos - and rename it without bounding
        {                                                                                   // TODO use here a static geometry because we know all the vertices = no allocation
            constexpr auto value = 0.5f;

            const auto hx = scale.x * value; // TODO for this use an aabb instead of the scale? it makes more sens if you want to have more control over the bounding box - like in sprites with rect
            const auto hy = scale.y * value;
            const auto hz = scale.z * value;

            return geometry
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

        static auto axis(const math::vec3& scale) noexcept // TODO maybe move axis in some other file/struct?
        {                                                  // TODO use here a static geometry because we know all the vertices = no allocation
            constexpr auto value = 0.5f;                   // TODO move to gizmos

            const auto hx = scale.x * value; constexpr math::vec3 r { 1.0f, 0.0f, 0.0f };
            const auto hy = scale.y * value; constexpr math::vec3 g { 0.0f, 1.0f, 0.0f };
            const auto hz = scale.z * value; constexpr math::vec3 b { 0.0f, 0.0f, 1.0f };

            return geometry<vertex::basic, primitive::line>
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

        Primitive() = delete;
    };
}