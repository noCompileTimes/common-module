#pragma once

namespace core
{
    class File
    {
    public:
        File() = delete;

        static auto read(const std::filesystem::path& path, int32_t mode = 0) -> std::vector<char>;
    };
}