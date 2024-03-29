#pragma once

#ifdef __cpp_lib_filesystem
#  include <filesystem>
namespace filesystem = std::filesystem;
#else
#  include <boost/filesystem.hpp>
namespace filesystem = boost::filesystem;
#endif // __cpp_lib_filesystem

#include <boost/optional.hpp>
#include <boost/program_options.hpp>
#include <boost/config.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

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

class Option : public OptionBase
{
public:
    Option()
    {

    }

    ~Option()
    {

    }

    boost::optional<std::string> address;
    boost::optional<uint16_t> port;
    boost::optional<uint32_t> timeout;

    void parse(int argc, char* argv[], const filesystem::path& path) BOOST_OVERRIDE
    {
        boost::program_options::options_description options_description;
        options_description.add_options()
            ("address", boost::program_options::value<std::string>())
            ("port", boost::program_options::value<uint16_t>())
            ("timeout", boost::program_options::value<uint32_t>())
            ;

        boost::program_options::variables_map variables_map;
        boost::program_options::store(
            boost::program_options::parse_command_line(argc, argv, options_description),
            variables_map);

        if (variables_map.count("address"))
        {
            address = boost::make_optional(variables_map["address"].as<std::string>());
        }

        if (variables_map.count("port"))
        {
            port = boost::make_optional(variables_map["port"].as<uint16_t>());
        }

        if (variables_map.count("timeout"))
        {
            timeout = boost::make_optional(variables_map["timeout"].as<uint32_t>());
        }

        if (!port || !address)
        {
            if (filesystem::exists(path))
            {
                boost::property_tree::ptree ptree;
                boost::property_tree::read_xml(path.string(), ptree);
                address = ptree.get_optional<std::string>("option.address");
                port = ptree.get_optional<uint16_t>("option.port");
            }
        }
    }
};
