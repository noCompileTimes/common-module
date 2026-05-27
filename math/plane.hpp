#pragma once

namespace math
{
    struct plane
    {
        vec3  normal;
        float distance;

        enum class orientation // TODO do something with this - it come to long with math::plane::orientation
        {
            xy, // normal along z axis
            xz, // normal along y axis
            yz  // normal along x axis
        };
    };
}