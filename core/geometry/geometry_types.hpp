#pragma once

#include "geometry.hpp"

#include "vertex/basic.hpp"
#include "vertex/model.hpp"
#include "vertex/sprite.hpp"

#include "element/line.hpp"
#include "element/triangle.hpp"

namespace core::geometry
{
    using  model = geometry<vertex::model,  uint32_t>; // TODO use triangle here
    using sprite = geometry<vertex::sprite, element::triangle>;

    using  gizmo = geometry<vertex::basic,  element::line>;
}