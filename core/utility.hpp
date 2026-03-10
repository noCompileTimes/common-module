#pragma once

namespace core
{
    template <typename type>
              requires std::is_trivially_copyable_v<type>
    static auto as_bytes(const std::vector<type>& data) noexcept -> std::span<const std::byte>
    {
        return std::as_bytes(std::span { data });
    }

    template <typename type>
              requires std::is_class_v<type>
    static auto as_bytes(const type& object) noexcept -> std::span<const std::byte>
    {
        return std::as_bytes(std::span<const type> { &object, 1 });
    }
}