#include "Inklin/Core/Config.h"

#include <fstream>

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


