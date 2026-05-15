#pragma once

#include "type/basic.hpp"
#include "type/sprite.hpp" // TODO move this into the static version maybe later?
#include "type/model.hpp"

namespace core::vertex
{
    template <typename vertex = type::basic, typename element = uint32_t>
    struct geometry
    {
        std::vector<vertex>  vertices;
        std::vector<element> elements; // TODO add elements as template with uint32_t as default

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

        // TODO o functie care face merge cu o alta geometrie, practic scapa de orice ar fi duplicate

        // TODO o functie care va da replace la un anumit vertex? sau un set? ar fi utila

        auto reserve(const size_t vertices_count,
                     const size_t elements_count) noexcept
        {
            vertices.reserve(vertices_count);
            elements.reserve(elements_count);
        }
    };
}