#pragma once

#include <vector>

#include "vertex/basic.hpp"

namespace geometry
{   // TODO restrict the element to be a struct? to accept just line and triangle? it seems to be a good idea
    template <typename vertex = vertex::basic, typename primitive = uint32_t> // TODO put the default for the primitive to be line?
    struct geometry
    {
        std::vector<vertex>    vertices;
        std::vector<primitive> elements;

        auto append(const geometry& other) noexcept
        {
            const auto offset = static_cast<uint32_t>(vertices.size());

            reserve(other.vertices.size() + offset,
                    other.elements.size() + elements.size());

            vertices.insert(vertices.end(), other.vertices.begin(),
                                            other.vertices.end());

            for (const auto& element : other.elements)
            {
                elements.emplace_back(element + offset);
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