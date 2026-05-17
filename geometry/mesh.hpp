#pragma once

#include "vertex/basic.hpp"
#include "vertex/sprite.hpp"
#include "vertex/model.hpp"

namespace geometry
{
    template <typename vertex = vertex::basic, typename element = uint32_t>
    struct mesh
    {
        std::vector<vertex>  vertices;
        std::vector<element> elements;

        auto append(const mesh& other) noexcept
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

        auto reserve(const size_t vertices_size, const size_t elements_size) noexcept
        {
            vertices.reserve(vertices_size);
            elements.reserve(elements_size);
        }
    };
}