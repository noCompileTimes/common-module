#pragma once

#include "axis.hpp"

namespace core
{
    class Primitives
    {
    public:
        static auto create_circle(const uint32_t segments, const float radius, const Axis::mode mode, const math::vec3& color) noexcept -> geometry<vertex::type::editor>
        {
            geometry<vertex::type::editor> geometry;
            geometry.reserve(segments,
                             segments * 2);

            const auto step = 2.0f * math::pi / static_cast<float>(segments);

            for (auto i = 0; i < segments; ++i)
            {
                const auto a = static_cast<float>(i) * step;

                const auto c = radius * math::cos(a);
                const auto s = radius * math::sin(a);

                switch (mode)
                {
                    case Axis::mode::xy:
                    {
                        geometry.vertices.emplace_back(math::vec3 { c, s, 0.0f }, color);
                        break;
                    }
                    case Axis::mode::xz:
                    {
                        geometry.vertices.emplace_back(math::vec3 { c, 0.0f, s }, color);
                        break;
                    }
                    case Axis::mode::yz:
                    {
                        geometry.vertices.emplace_back(math::vec3 { 0.0f, c, s }, color);
                        break;
                    }
                    default:
                        return { };
                }
            }

            for (auto i = 0; i < segments; ++i)
            {
                geometry.elements.emplace_back(i);
                geometry.elements.emplace_back((i + 1) % segments);
            }

            return geometry;
        }

        static auto create_bounding_sphere(const uint32_t segments, const float radius, const math::vec3& color) noexcept -> geometry<vertex::type::editor>
        {
            geometry<vertex::type::editor> geometry;

            geometry.merge(create_circle(segments, radius, Axis::mode::xy, color));
            geometry.merge(create_circle(segments, radius, Axis::mode::xz, color));
            geometry.merge(create_circle(segments, radius, Axis::mode::yz, color));

            return geometry;
        }

        static auto create_bounding_box(const math::vec3& scale, const math::vec3& color) noexcept -> geometry<vertex::type::editor>
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

    private:
        Primitives() = delete;
    };
}