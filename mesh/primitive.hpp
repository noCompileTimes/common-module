#pragma once

#include "axis.hpp"

#include "types.hpp"

#include "math/rect.hpp"

namespace mesh
{
    class Primitive // TODO rename this with lower case
    {
    public:
        [[nodiscard]] static auto circle(const uint32_t segments, const float radius, const axis axis, const math::vec3& color) noexcept // TODO bounding circle?
        {
            gizmo geometry;
                  geometry.reserve(segments, segments * 2);

            const auto t = 2.0f * math::pi / static_cast<float>(segments);

            for (auto i = 0; i < segments; ++i)
            {
                const auto a = static_cast<float>(i) * t;

                const auto c = radius * math::cos(a);
                const auto s = radius * math::sin(a);

                switch (axis)
                {
                    case axis::x:
                    {
                        geometry.vertices.emplace_back(math::vec3 { 0.0f, c, s }, color);
                        break;
                    }
                    case axis::y:
                    {
                        geometry.vertices.emplace_back(math::vec3 { c, 0.0f, s }, color);
                        break;
                    }
                    case axis::z:
                    {
                        geometry.vertices.emplace_back(math::vec3 { c, s, 0.0f }, color);
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

        [[nodiscard]] static auto square(const math::rect& position, const math::vec3& color) noexcept
        {
            return gizmo
            {
                {
                    { position.min.x, position.min.y, 0.0f, color },
                    { position.max.x, position.min.y, 0.0f, color },
                    { position.max.x, position.max.y, 0.0f, color },
                    { position.min.x, position.max.y, 0.0f, color }
                },
                {
                    { 0, 1 },
                    { 1, 2 },
                    { 2, 3 },
                    { 3, 0 }
                }
            };
        }

        [[nodiscard]] static auto bounding_sphere(const uint32_t segments, const float radius, const math::vec3& color) noexcept
        {
            gizmo geometry; // TODO make a reserve here

            geometry.append(circle(segments, radius, axis::x, color));
            geometry.append(circle(segments, radius, axis::y, color));
            geometry.append(circle(segments, radius, axis::z, color));

            return geometry;
        }

        [[nodiscard]] static auto bounding_box(const math::vec3& scale, const math::vec3& color) noexcept
        {
            constexpr auto half = 0.5f;

            const auto x = scale.x * half; // TODO for this use an aabb instead of the scale? it makes more sens if you want to have more control over the bounding box - like in sprites with rect
            const auto y = scale.y * half; // TODO if using the aabb you dont need the half scale anymore?
            const auto z = scale.z * half;

            return gizmo
            {
                {
                    { -x, -y, -z, color },
                    {  x, -y, -z, color },
                    {  x,  y, -z, color },
                    { -x,  y, -z, color },
                    { -x, -y,  z, color },
                    {  x, -y,  z, color },
                    {  x,  y,  z, color },
                    { -x,  y,  z, color }
                },
                {
                    { 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 0 },
                    { 4, 5 }, { 5, 6 }, { 6, 7 }, { 7, 4 },
                    { 0, 4 }, { 1, 5 }, { 2, 6 }, { 3, 7 }
                }
            };
        }

        Primitive() = delete;
    };
}