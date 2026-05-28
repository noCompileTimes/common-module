#pragma once

#include <span>

namespace core
{
      template <typename type>
                requires std::is_trivially_copyable_v<type>
    static auto as_bytes(const std::vector<type>& data) noexcept // TODO add some version for std::array
    {
        return std::as_bytes(std::span { data });
    }

      template <typename type>
                requires std::is_class_v<type>
    static auto as_bytes(const type& object) noexcept
    {
        return std::as_bytes(std::span<const type> { &object, 1 });
    }

      template <typename type>
                requires std::is_enum_v<type>
    static auto as_base(const type value) noexcept
    {
         return std::to_underlying(value);
    }
}