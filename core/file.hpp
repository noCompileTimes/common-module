#pragma once

namespace core
{
    class File
    {
    public:
        File() = delete;

        [[nodiscard]] static auto read(const std::filesystem::path& path, const int32_t mode = 0) -> std::vector<char>
        {
            assert(is_regular_file(path));

            std::ifstream stream(path, std::ios::ate | mode);
            assert(stream.is_open());

            const auto size = stream.tellg();
            assert(size > 0);

            std::vector<char> content(size);

            stream.seekg(0, std::ios::beg);
            stream.read(content.data(), size);

            return content;
        }
    };
}