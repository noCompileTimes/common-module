#pragma once

#include <chrono>

using time_clock = std::chrono::high_resolution_clock;
using time_point = std::chrono::high_resolution_clock::time_point;

namespace core
{
    class Time
    {
    public:
        auto start() noexcept
        {
            _initial_time_point =
            _current_time_point = current_time_point();
        }

        auto tick() noexcept
        {
            const auto current = current_time_point();

            _delta_time = calculate_duration(_current_time_point, current).count();
            _total_time = calculate_duration(_initial_time_point, current).count();

            _current_time_point = current;

            if (_delta_time > max_delta_time) {
                _delta_time = max_delta_time;
            }
        }

        [[nodiscard]] static auto delta_time() noexcept
        {
            return _delta_time;
        }

        [[nodiscard]] static auto total_time() noexcept
        {
            return _total_time;
        }

        [[nodiscard]] static auto calculate_duration(const time_point start_time_point, const time_point end_time_point) noexcept -> std::chrono::duration<float>
        {
            return end_time_point - start_time_point;
        }

        [[nodiscard]] static auto current_time_point() noexcept -> time_point
        {
            return time_clock::now();
        }

    private:
        static constexpr auto max_delta_time { 1.0f / 30.0f };

        inline static auto _delta_time { 0.0f };
        inline static auto _total_time { 0.0f };

        time_point _initial_time_point { };
        time_point _current_time_point { };
    };
}