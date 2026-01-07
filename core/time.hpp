#pragma once

namespace core
{
    using time_clock   = std::chrono::high_resolution_clock;
    using time_point   = std::chrono::high_resolution_clock::time_point;

    using time_seconds = std::chrono::duration<float>;

    class Time
    {
    public:
        auto  start() noexcept -> void;
        auto   tick() noexcept -> void;

        [[nodiscard]] static auto    delta() noexcept -> float;
        [[nodiscard]] static auto  elapsed() noexcept -> float;

        [[nodiscard]] static auto  current()                                     noexcept -> time_point;
        [[nodiscard]] static auto duration(time_point start_t, time_point end_t) noexcept -> time_seconds;

    private:
        static constexpr auto max_delta_t = 1.0f / 30.0f;

            inline static auto   _delta_t = 0.0f;
            inline static auto _elapsed_t = 0.0f;

            time_point   _start_t { };
            time_point _current_t { };
    };
}