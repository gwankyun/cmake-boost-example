#pragma once
#include <filesystem>

class OptionBase
{
public:
    OptionBase()
    {
    }

    virtual ~OptionBase()
    {
    }

    virtual void parse(int argc, char* argv[], const std::filesystem::path& path) = 0;

private:

};
