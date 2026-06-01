#pragma once

#include "geometry.hpp"

#include "vertex/model.hpp"
#include "vertex/sprite.hpp"

#include "primitive/line.hpp"
#include "primitive/triangle.hpp"

namespace core::geometry
{
    using  model = geometry<vertex::model>;
    using sprite = geometry<vertex::sprite, primitive::triangle>;

    using  gizmo = geometry<vertex::basic, primitive::line>;
}