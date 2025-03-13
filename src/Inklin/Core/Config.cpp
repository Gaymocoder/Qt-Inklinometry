#include "Inklin/Core/Config.h"

#include <fstream>
#include <stdexcept>

using Inklin::SourceDataType;
using namespace Inklin::Core;

Config::Config(const FS::path& configPath) : configFilePath(configPath)
{
    this->setDefaultValue(ConfigKeys::STARTPOS);
    
    this->load();
}

std::string Config::getStrKey(const std::string& line)
{
    return line.substr(0, line.find("="));
}

std::string Config::getStrValue(const std::string& line)
{
    return line.substr(line.find("=") + 1);
}

ConfigKeys Config::strToKey(const std::string& key)
{
    if (key == "STARTPOS")
        return ConfigKeys::STARTPOS;
    else
        throw std::invalid_argument("Config::strToKey: Invalid key");
}

std::string Config::pairToStr(ConfigKeys key, const void* value_ptr)
{
    std::stringstream sspair;
    switch (key)
    {
        case ConfigKeys::STARTPOS:
            sspair << "STARTPOS=" << *((DataSet*) value_ptr);
            return sspair.str();
            
        default:
            throw std::invalid_argument("Config::pairToStr: Invalid key");
    }
    
    return sspair.str();
}

void Config::load()
{
    std::string lineBuf;
    std::ifstream configFile(this->configFilePath.string());
    while (std::getline(configFile, lineBuf))
    {
        std::string key = Config::getStrKey(lineBuf);
        std::string value = Config::getStrValue(lineBuf);
        this->setValue(key, value);
    }
    configFile.close();
}

