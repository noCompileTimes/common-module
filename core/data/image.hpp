#pragma once

namespace core::data
{
    struct image
    {
        int32_t    width { };
        int32_t   height { };
        int32_t channels { };

        std::vector<uint8_t> pixels;
    };
}