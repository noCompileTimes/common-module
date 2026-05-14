#pragma once

namespace core
{
    template <typename vertex>
              requires std::is_class_v<vertex>
    struct geometry // TODO think of a way to add some static geometry? to avoid the new operator somehow? used maybe for sprites? because we have many
    {
        std::vector<vertex>   vertices;
        std::vector<uint32_t> elements;

        auto append(const geometry& other) noexcept
        {
            const auto offset = static_cast<uint32_t>(vertices.size()); // TODO remove the cast here? it is ok to just use .size()

            reserve(other.vertices.size() + offset,
                    other.elements.size() + elements.size());

            vertices.insert(vertices.end(), other.vertices.begin(),
                                            other.vertices.end());

            for (const auto index : other.elements)
            {
                elements.emplace_back(index + offset);
            }
        }

        // TODO o functie care va da replace la un anumit vertex? sau un set? ar fi utila

        auto reserve(const std::size_t vertices_count,
                     const std::size_t elements_count) noexcept
        {
            vertices.reserve(vertices_count);
            elements.reserve(elements_count);
        }
    };
}