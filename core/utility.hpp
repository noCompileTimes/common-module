#pragma once

#include <span>

namespace core // TODO rename the file with a better name
{
    template <typename T>
    [[nodiscard]] static auto as_bytes(const std::vector<T>& data) noexcept
    {
        return std::as_bytes(std::span { data });
    }

    template <typename T, size_t N>
    [[nodiscard]] static auto as_bytes(const std::array<T, N>& data) noexcept
    {
        return std::as_bytes(std::span { data });
    }

    template <typename T, size_t N = 1>
    [[nodiscard]] static auto as_bytes(const T& object) noexcept
    {
        return std::as_bytes(std::span<const T> { &object, N });
    }

    template <typename T>
    [[nodiscard]] static auto as_base(const T value) noexcept
    {
        return std::to_underlying(value);
    }
}