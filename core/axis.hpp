#pragma once

#include "geometry.hpp"

namespace core
{
    class Axis
    {
    public:
        static auto create(const math::vec3& scale) noexcept -> geometry<vertex::type::editor>
        {
            const auto hx = scale.x * 0.5f;  constexpr math::vec3 r = { 1.0f, 0.0f, 0.0f };
            const auto hy = scale.y * 0.5f;  constexpr math::vec3 g = { 0.0f, 1.0f, 0.0f };
            const auto hz = scale.z * 0.5f;  constexpr math::vec3 b = { 0.0f, 0.0f, 1.0f };

            return
            {
                {
                    { { -hx,    0.0f,  0.0f }, r }, // 0
                    { {  hx,    0.0f,  0.0f }, r }, // 1
                    { {  0.0f,  hy,    0.0f }, g }, // 2
                    { {  0.0f, -hy,    0.0f }, g }, // 3
                    { {  0.0f,  0.0f,  hz   }, b }, // 4
                    { {  0.0f,  0.0f, -hz   }, b }  // 5
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