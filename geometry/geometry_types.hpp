#pragma once

#include "geometry.hpp"

#include "vertex/basic.hpp"
#include "vertex/model.hpp"
#include "vertex/sprite.hpp"

#include "primitive/line.hpp"
#include "primitive/triangle.hpp"

namespace geometry
{
    using  model = geometry<vertex::model,  uint32_t>; // TODO use triangle here
    using sprite = geometry<vertex::sprite, primitive::triangle>;
}