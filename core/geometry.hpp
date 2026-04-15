#pragma once

namespace core
{
    template <typename vertex>
              requires std::is_class_v<vertex>
    struct geometry
    {
        std::vector<vertex>   vertices;
        std::vector<uint32_t> elements;

        auto merge(const geometry& other) noexcept
        {
            const auto offset = static_cast<uint32_t>(vertices.size());

            vertices.reserve(other.vertices.size() + offset);
            elements.reserve(other.elements.size() + elements.size());

            vertices.insert(vertices.end(), other.vertices.begin(),
                                            other.vertices.end());

            for (const auto index : other.elements)
            {
                elements.emplace_back(index + offset);
            }
        }
    };
}