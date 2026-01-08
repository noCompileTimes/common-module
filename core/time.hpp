#pragma once

namespace core
{
    using time_clock   = std::chrono::high_resolution_clock;
    using time_point   = std::chrono::high_resolution_clock::time_point;

    using time_seconds = std::chrono::duration<float>;

    class Time
    {
    public:
        auto start() noexcept -> void {
              _start_t =
            _current_t = current();
        }
        auto  tick() noexcept -> void {

            const auto current_t = current();

              _delta_t = duration(_current_t, current_t).count();
            _elapsed_t = duration(  _start_t, current_t).count();
            _current_t = current_t;

            if (_delta_t > max_delta_t)
            {
                _delta_t = max_delta_t;
            }
        }

        [[nodiscard]] static auto    delta() noexcept -> float {
            return _delta_t;
        }
        [[nodiscard]] static auto  elapsed() noexcept -> float {
            return _elapsed_t;
        }

        [[nodiscard]] static auto duration(const time_point start_t, const time_point end_t) noexcept -> time_seconds {
            return end_t - start_t;
        }
        [[nodiscard]] static auto  current()                                                 noexcept -> time_point   {
            return time_clock::now();
        }

    private:
        static constexpr auto max_delta_t = 1.0f / 30.0f;

            inline static auto   _delta_t = 0.0f;
            inline static auto _elapsed_t = 0.0f;

            time_point   _start_t { };
            time_point _current_t { };
    };
}