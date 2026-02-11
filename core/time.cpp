#include "time.hpp"

namespace core
{
    auto Time::start() noexcept -> void
    {
        _initial_time_point =
        _current_time_point = current_time_point();
    }

    auto Time::tick() noexcept -> void
    {
         const auto current = current_time_point();

        _delta_time = duration(_current_time_point, current).count();
        _total_time = duration(_initial_time_point, current).count();

        _current_time_point = current;

        if (_delta_time > max_delta_time)
        {
            _delta_time = max_delta_time;
        }
    }

    auto Time::delta_time() noexcept -> float
    {
        return _delta_time;
    }

    auto Time::total_time() noexcept -> float
    {
        return _total_time;
    }

    auto Time::duration(const time_point start_time_point, const time_point end_time_point) noexcept -> time_seconds
    {
        return end_time_point - start_time_point;
    }

    auto Time::current_time_point() noexcept -> time_point
    {
        return time_clock::now();
    }
}