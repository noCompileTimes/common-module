#pragma once

namespace core::data
{
    struct buffer
    {
        const void*  ptr  { };
        const size_t size { };
    };

    template <typename type>
              requires std::is_integral_v<type> || std::is_class_v<type>
    static auto make_buffer(const std::vector<type>& elements) noexcept -> buffer
    {
        return
        {
            elements.data(),
            elements.size() * sizeof(type)
        };
    }

    template <typename type>
              requires std::is_class_v<type>
    static auto make_buffer(const type* object) noexcept -> buffer
    {
        assert(object != nullptr);

        return
        {
            object,
            sizeof(type)
        };
    }
}