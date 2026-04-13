#pragma once

#include "geometry.hpp"

namespace core
{
    class Axis
    {
    public:
        static auto create(const math::vec3& scale) noexcept -> geometry<vertex::type::editor>
        {
            const auto hx = scale.x * 0.5f;
            const auto hy = scale.y * 0.5f;
            const auto hz = scale.z * 0.5f;

            return
            {
                {
                    { { -hx,    0.0f,  0.0f }, { 1.0f, 0.0f, 0.0f } }, // 0
                    { {  hx,    0.0f,  0.0f }, { 1.0f, 0.0f, 0.0f } }, // 1
                    { {  0.0f,  hy,    0.0f }, { 0.0f, 1.0f, 0.0f } }, // 2
                    { {  0.0f, -hy,    0.0f }, { 0.0f, 1.0f, 0.0f } }, // 3
                    { {  0.0f,  0.0f,  hz   }, { 0.0f, 0.0f, 1.0f } }, // 4
                    { {  0.0f,  0.0f, -hz   }, { 0.0f, 0.0f, 1.0f } }  // 5
                },
                {
                    0, 1, // x
                    2, 3, // y
                    4, 5  // z
                }
            };
        }

    private:
        Axis() = delete;
    };
}