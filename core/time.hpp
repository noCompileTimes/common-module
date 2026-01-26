#pragma once

namespace core
{
    using time_clock   = std::chrono::high_resolution_clock;
    using time_point   = std::chrono::high_resolution_clock::time_point;

    using time_seconds = std::chrono::duration<float>;

    class Time
    {
    public:
        auto start() noexcept -> void
        {
            _initial_tp =
            _current_tp = current();
        }

        auto tick() noexcept -> void
        {
            const auto current_tp = current();

              _delta_t  = duration(_current_tp, current_tp).count();
              _total_t  = duration(_initial_tp, current_tp).count();
            _current_tp = current_tp;

            if (_delta_t > max_delta_t)
            {
                _delta_t = max_delta_t;
            }
        }

        [[nodiscard]] static auto delta() noexcept -> float
        {
            return _delta_t;
        }

        [[nodiscard]] static auto total() noexcept -> float
        {
            return _total_t;
        }

        [[nodiscard]] static auto duration(const time_point start_tp, const time_point end_tp) noexcept -> time_seconds
        {
            return end_tp - start_tp;
        }

        [[nodiscard]] static auto current() noexcept -> time_point
        {
            return time_clock::now();
        }

    private:
        static constexpr auto max_delta_t = 1.0f / 30.0f;

        inline static auto _delta_t = 0.0f;
        inline static auto _total_t = 0.0f;

        time_point _initial_tp { };
        time_point _current_tp { };
    };
}