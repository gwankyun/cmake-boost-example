#pragma once
#ifdef __cpp_lib_filesystem
#include <filesystem>
namespace filesystem = std::filesystem;
#else
#include <boost/filesystem.hpp>
namespace filesystem = boost::filesystem;
#endif // __cpp_lib_filesystem

class OptionBase
{
public:
    OptionBase()
    {
    }

    virtual ~OptionBase()
    {
    }

    virtual void parse(int argc, char* argv[], const filesystem::path& path) = 0;

private:

};
