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
    std::string strKey = "";
    for(size_t i = 0, len = line.find("="); i < len; ++i)
        if (line[i] != ' ')
            strKey += line[i];
    return strKey;
}

std::string Config::getStrValue(const std::string& line)
{
    size_t valueStart = line.find("=") + 1;
    size_t valueEnd   = line.length() - 1;
    
    for(; line[valueEnd] == ' ' && valueStart < valueEnd; --valueEnd);
    for(; line[valueStart] == ' ' && valueStart < valueEnd; ++valueStart);
    
    return line.substr(valueStart, valueEnd - valueStart + 1);
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

void Config::setValue(ConfigKeys key, const std::string& value)
{
    std::stringstream ssvalue(value);
    switch (key)
    {
        case ConfigKeys::STARTPOS:
            ssvalue >> this->startPosition;
            return;
            
        default:
            throw std::invalid_argument("Config::setValue: Invalid key");
    }
}

void Config::setDefaultValue(ConfigKeys key)
{
    switch (key)
    {
        case ConfigKeys::STARTPOS:
            this->startPosition = {0, 0, 0};
            return;
            
        default:
            throw std::invalid_argument("Config::setDefaultValue: Invalid key");
    }
}

void Config::load()
{
    if (!FS::exists(this->configFilePath))
    {
        this->save();
        return;
    }
    
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

void Config::save() const
{
    if (!FS::exists(this->configFilePath.parent_path()))
        FS::create_directories(this->configFilePath.parent_path());        
    std::ofstream configFile(this->configFilePath.string());
    
    configFile << Config::pairToStr(ConfigKeys::STARTPOS, &(this->startPosition)) << std::endl;
    
    configFile.close();
}
