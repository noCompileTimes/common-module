#include "functions.hpp"

namespace math
{
    auto radians(const float degrees) -> float
    {
        return degrees * 0.017453292519943295769f;
    }

    auto sin(const float radians) -> float
    {
         return std::sin(radians);
    }

    auto cos(const float radians) -> float
    {
         return std::cos(radians);
    }

    auto tan(const float radians) -> float
    {
         return std::tan(radians);
    }
}