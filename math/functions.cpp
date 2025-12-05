#include "functions.hpp"

namespace math
{
    auto sqrt(const float value) -> float
    {
         return std::sqrt(value);
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