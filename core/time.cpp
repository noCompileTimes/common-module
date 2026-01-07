#include "time.hpp"

namespace core
{
    auto Time::start() noexcept -> void
    {
          _start_t =
        _current_t = current();
    }

    auto Time::tick() noexcept -> void
    {
            const auto current_t = current();

            _delta_t = duration(_current_t, current_t).count();
          _elapsed_t = duration(  _start_t, current_t).count();
          _current_t = current_t;

        if (_delta_t > max_delta_t)
        {
            _delta_t = max_delta_t;
        }
    }

    auto Time::delta() noexcept -> float
    {
        return _delta_t;
    }

    auto Time::elapsed() noexcept -> float
    {
        return _elapsed_t;
    }

    auto Time::current() noexcept -> time_point
    {
        return time_clock::now();
    }

    auto Time::duration(const time_point start_t, const time_point end_t) noexcept -> time_seconds
    {
        return end_t - start_t;
    }
}