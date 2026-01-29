#pragma once

namespace core::data
{
    template <typename vertex>
              requires std::is_class_v<vertex>
    struct geometry
    {
        std::vector<vertex>   vertices;
        std::vector<uint32_t> elements;
    };
}