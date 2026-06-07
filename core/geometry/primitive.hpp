#pragma once

#include "math/plane.hpp"

#include "geometry_types.hpp"

namespace core::geometry
{
    class Primitive
    {
    public:
        static auto circle(const uint32_t segments, const float radius, const math::plane::orientation plane, const math::vec3& color) noexcept // TODO bounding circle?
        {
            gizmo geometry;
                  geometry.reserve(segments, segments * 2);

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

        static auto bounding_sphere(const uint32_t segments, const float radius, const math::vec3& color) noexcept
        {
            gizmo geometry;

            geometry.append(circle(segments, radius, math::plane::orientation::xy, color));
            geometry.append(circle(segments, radius, math::plane::orientation::xz, color));
            geometry.append(circle(segments, radius, math::plane::orientation::yz, color));

            return geometry;
        }

        static auto bounding_box(const math::vec3& scale, const math::vec3& color) noexcept
        {
            constexpr auto half = 0.5f;

            const auto x = scale.x * half; // TODO for this use an aabb instead of the scale? it makes more sens if you want to have more control over the bounding box - like in sprites with rect
            const auto y = scale.y * half;
            const auto z = scale.z * half;

            return geometry<vertex::basic, uint32_t> // TODO use lines for this
            {
                {
                    { { -x, -y, -z }, color },
                    { {  x, -y, -z }, color },
                    { {  x,  y, -z }, color },
                    { { -x,  y, -z }, color },
                    { { -x, -y,  z }, color },
                    { {  x, -y,  z }, color },
                    { {  x,  y,  z }, color },
                    { { -x,  y,  z }, color }
                },
                {
                    0, 1,  1, 2,  2, 3,  3, 0,
                    4, 5,  5, 6,  6, 7,  7, 4,
                    0, 4,  1, 5,  2, 6,  3, 7
                }
            };
        }

        Primitive() = delete;
    };
}