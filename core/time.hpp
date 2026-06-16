#pragma once

#include <chrono>

using time_clock = std::chrono::high_resolution_clock;
using time_point = std::chrono::high_resolution_clock::time_point;

namespace core
{
    class Time
    {
    public:
        [[nodiscard]] auto delta_time() const noexcept
        {
            return _delta_time;
        }

        [[nodiscard]] auto total_time() const noexcept
        {
            return _total_time;
        }

        [[nodiscard]] static auto duration(const time_point start_time, const time_point end_time) noexcept // TODO extend this to have a template parameter for duration
        {
            return std::chrono::duration<float>(end_time - start_time).count();
        }

        [[nodiscard]] static auto current_time() noexcept
        {
            return time_clock::now();
        }

        auto start() noexcept
        {
            _initial_time =
            _current_time = current_time();
        }

        auto tick() noexcept
        {
            const auto time = current_time();

                _delta_time = duration(_current_time, time);
                _total_time = duration(_initial_time, time);

              _current_time = time;

            //if (_delta_time > _max_delta_time) { // TODO handle this outside in the engine class
            //    _delta_time = _max_delta_time;
            //}
        }

    private:
        //static constexpr auto _max_delta_time { 1.0f / 30.0f };

        time_point _initial_time { };
        time_point _current_time { };

        float _delta_time { };
        float _total_time { };
    };
}