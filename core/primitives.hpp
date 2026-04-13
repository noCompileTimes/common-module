#pragma once

#include "axis.hpp"

namespace core
{
    class Primitives
    {
    public:
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