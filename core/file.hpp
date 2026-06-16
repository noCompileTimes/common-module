#pragma once

#include <fstream>

namespace core
{
    class File
    {
    public:
        template <typename T = std::byte>
        [[nodiscard]] static auto read(const std::filesystem::path& path, const std::ios::openmode mode = std::ios::binary)
        {
            static_assert(sizeof(T) == 1, "file read requires byte-sized types");

            std::ifstream stream(path, std::ios::in | mode);

            if (!stream)
            {
                throw std::runtime_error("failed to open file: " + path.string());
            }

            const auto size = file_size(path);

            if (size == 0)
            {
                throw std::runtime_error("file is empty: " + path.string());
            }

            std::vector<T> content(size);

            stream.read(reinterpret_cast<char*>(content.data()),
                                   static_cast<std::streamsize>(size));
            if (stream.gcount() != static_cast<std::streamsize>(size))
            {
                throw std::runtime_error("failed to read full file: " + path.string());
            }

            return content;
        }

        File() = delete;
    };
}