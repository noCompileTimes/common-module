#pragma once

#include <filesystem>
#include <fstream>

namespace core
{
    class File
    {
    public:
        template <typename type = std::byte> // TODO which should be the value for mode if you don't want binary?
        [[nodiscard]] static auto read(const std::filesystem::path& path, const std::ios::openmode mode = std::ios::binary)
        {
            static_assert(sizeof(type) == 1, "file read requires byte-sized types"); // TODO check if this is supported with char

            assert(is_regular_file(path));

            std::ifstream stream(path, std::ios::in | std::ios::ate | mode);
                   assert(stream);

            const auto end = stream.tellg();
                assert(end > 0);

            const auto size = static_cast<size_t>(end);
            std::vector<type> content(size);

            stream.seekg(0, std::ios::beg);
            stream.read(reinterpret_cast<char*>(content.data()), static_cast<std::streamsize>(size));

            assert(stream.gcount() == static_cast<std::streamsize>(size));

            return content;
        }

        File() = delete;
    };
}