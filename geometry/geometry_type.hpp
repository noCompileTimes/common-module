#pragma once

#include "geometry.hpp"

#include "vertex/model.hpp"
#include "vertex/sprite.hpp"

#include "primitive/triangle.hpp"
#include "primitive/line.hpp"

namespace geometry // TODO remove this file?
{
    using  model = geometry<vertex::model>;
    using sprite = geometry<vertex::sprite, primitive::triangle>;

    using  gizmo = geometry<vertex::basic, primitive::line>;
}