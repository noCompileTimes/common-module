#pragma once

namespace math
{
    struct plane
    {
        enum class orientation
        {
            xy, // normal along z axis
            xz, // normal along y axis
            yz  // normal along x axis
        };

        vec3  normal;
        float distance;
    };
}