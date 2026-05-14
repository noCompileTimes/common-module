#pragma once

#include "math/plane.hpp"
#include "math/vec3.hpp"

#include "vertex/geometry.hpp"

namespace core
{
    class Primitives
    {
    public:
        static auto create_circle(const uint32_t segments, const float radius, const math::plane::orientation plane, const math::vec3& color) noexcept -> auto
        {
            vertex::geometry geometry;
                    geometry.reserve(segments, segments * 2);

            const auto step = 2.0f * math::pi / static_cast<float>(segments);

            for (auto i = 0; i < segments; ++i)
            {
                const auto a = static_cast<float>(i) * step;

                const auto c = radius * math::cos(a);
                const auto s = radius * math::sin(a);

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
                geometry.elements.emplace_back(i);
                geometry.elements.emplace_back((i + 1) % segments);
            }

            return geometry;
        }

        static auto create_bounding_sphere(const uint32_t segments, const float radius, const math::vec3& color) noexcept -> auto
        {
            vertex::geometry geometry;

            geometry.append(create_circle(segments, radius, math::plane::orientation::xy, color));
            geometry.append(create_circle(segments, radius, math::plane::orientation::xz, color));
            geometry.append(create_circle(segments, radius, math::plane::orientation::yz, color));

            return geometry;
        }

        static auto create_bounding_box(const math::vec3& scale, const math::vec3& color) noexcept -> vertex::geometry<>
        {
            const auto hx = scale.x * 0.5f;
            const auto hy = scale.y * 0.5f;
            const auto hz = scale.z * 0.5f;

            return
            {
                {
                    { { -hx, -hy, -hz }, color }, // 0
                    { {  hx, -hy, -hz }, color }, // 1
                    { {  hx,  hy, -hz }, color }, // 2
                    { { -hx,  hy, -hz }, color }, // 3
                    { { -hx, -hy,  hz }, color }, // 4
                    { {  hx, -hy,  hz }, color }, // 5
                    { {  hx,  hy,  hz }, color }, // 6
                    { { -hx,  hy,  hz }, color }  // 7
                },
                {
                    0, 1,  1, 2,  2, 3,  3, 0,
                    4, 5,  5, 6,  6, 7,  7, 4,
                    0, 4,  1, 5,  2, 6,  3, 7
                }
            };
        }

        static auto create_axis(const math::vec3& scale) noexcept -> vertex::geometry<> // TODO maybe move axis in some other file/struct?
        {
            const auto hx = scale.x * 0.5f;  constexpr math::vec3 r = { 1.0f, 0.0f, 0.0f };
            const auto hy = scale.y * 0.5f;  constexpr math::vec3 g = { 0.0f, 1.0f, 0.0f };
            const auto hz = scale.z * 0.5f;  constexpr math::vec3 b = { 0.0f, 0.0f, 1.0f };

            return
            {
                {
                    { { -hx,    0.0f,  0.0f }, r }, // 0
                    { {  hx,    0.0f,  0.0f }, r }, // 1
                    { {  0.0f, -hy,    0.0f }, g }, // 2
                    { {  0.0f,  hy,    0.0f }, g }, // 3
                    { {  0.0f,  0.0f, -hz   }, b }, // 4
                    { {  0.0f,  0.0f,  hz   }, b }  // 5
                },
                {
                    0, 1, // x
                    2, 3, // y
                    4, 5  // z
                }
            };
        }

        Primitives() = delete;
    };
}