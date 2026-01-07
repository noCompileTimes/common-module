#include "time.hpp"

namespace core
{
    auto Time::start() noexcept -> void
    {
          _start_t =
        _current_t = time_clock::now();
    }

    auto Time::tick() noexcept -> void
    {
            const auto current_t = time_clock::now();

            _delta_t = time_seconds(current_t - _current_t).count();
          _elapsed_t = time_seconds(current_t -   _start_t).count();
          _current_t = current_t;

        if (_delta_t > max_delta_t)
        {
            _delta_t = max_delta_t;
        }
    }

    auto Time::elapsed() noexcept -> float
    {
        return _elapsed_t;
    }

    auto Time::delta() noexcept -> float
    {
        return _delta_t;
    }
}