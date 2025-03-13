#include "Inklin/Core/Config.h"
#include "Inklin/Core/Calculator.h"

#include <fstream>
#include <stdexcept>

using Inklin::SourceDataType;
using namespace Inklin::Core;

Config::Config(const FS::path& configPath) : configFilePath(configPath)
{
    this->setDefault();
    this->load();
}

Config::~Config()
{
    for(uint16_t key = 0; key < Inklin::Core::configKeysAmount; ++key)
        this->deleteValue(key);
}

void Config::setDefault()
{
    for(uint16_t key = 0; key < Inklin::Core::configKeysAmount; ++key)
        this->setDefaultValue(key);
}

void Config::deleteValue(uint16_t key)
{
    switch (key)
    {
        case STARTPOS:
            delete (DataSet*) this->config[key];
            break;
            
        default:
            throw std::invalid_argument("Config::deleteValue(uint16_t): the config key does not exist");
    }
    
    this->config[key] = nullptr;
}

void Config::setDefaultValue(uint16_t key)
{
    if (!this->config[key])
        this->deleteValue(key);
        
    switch (key)
    {
        case STARTPOS:
            this->config[key] = new DataSet {0, 0, 0};
            break;
            
        default:
            throw std::invalid_argument("Config::setDefaultValue(uint16_t): the config key does not exist");
    }
    
    this->config[key] = nullptr;
}

template <typename ValueType>
ValueType Config::getValue(uint16_t key, ValueType* ptr)
{
    ValueType** valuePtr = &(this->config[key]);
    if (!(*valuePtr))
        this->setDefaultValue(key);
        
    if (ptr)
        *ptr = **valuePtr;
        
    return **valuePtr;
}

template <typename ValueType>
void Config::setValue(uint16_t key, ValueType value)
{
    if (!this->config[key])
        this->config[key] = new ValueType(value);
    else
        *((ValueType*) (this->config[key])) = value;
}

std::string Config::getStrKey(const std::string& line)
{
    return line.substr(0, line.find("="));
}

std::string Config::getStrValue(const std::string& line)
{
    return line.substr(line.find("=") + 1);
}
