#pragma once

#include <chrono>

namespace core
{
    using time_clock   = std::chrono::high_resolution_clock;
    using time_point   = std::chrono::high_resolution_clock::time_point;

    using time_seconds = std::chrono::duration<float>;

    class Time
    {
    public:
        auto start() noexcept -> void;
        auto  tick() noexcept -> void;

        [[nodiscard]] static auto delta_time() noexcept -> float;
        [[nodiscard]] static auto total_time() noexcept -> float;

        [[nodiscard]] static auto calculate_duration(time_point start_time_point, time_point end_time_point) noexcept -> time_seconds;

        [[nodiscard]] static auto current_time_point() noexcept -> time_point;

    private:
     constexpr static auto  delta_time_max = 1.0f / 30.0f;

        inline static auto _delta_time = 0.0f;
        inline static auto _total_time = 0.0f;

        time_point _initial_time_point { };
        time_point _current_time_point { };
    };
}