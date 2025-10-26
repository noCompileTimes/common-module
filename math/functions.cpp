#include "functions.hpp"

namespace math
{
    auto radians(const float degrees) -> float
    {
        return degrees * 0.017453292519943295769f;
    }

    auto tan(const float radians) -> float
    {
        return  std::tan(radians);
    }
}