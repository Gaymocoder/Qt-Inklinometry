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
    this->config[STARTPOS] = new DataSet {-1, -1, -1};
}

void Config::deleteValue(uint16_t key)
{
    switch (key)
    {
        case STARTPOS:
            delete (DataSet*) this->config[key];
            break;
            
        default:
            throw std::invalid_argument("Config::deleteValue(ConfigKeys): the config key does not exist");
    }
    
    this->config[key] = nullptr;
}
