#pragma once

#include "geometry.hpp"

#include "vertex/model.hpp"
#include "vertex/sprite.hpp"

#include "primitive/triangle.hpp"

namespace geometry
{
    using  model = geometry<vertex::model>;
    using sprite = geometry<vertex::sprite, primitive::triangle>;
}