#pragma once

namespace math
{
    struct plane
    {
        vec3  normal;
        float distance;

        enum class orientation
        {
            xy, // normal along z axis
            xz, // normal along y axis
            yz  // normal along x axis
        };
    };
}