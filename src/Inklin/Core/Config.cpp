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

std::string Config::getStrKey(const std::string& line)
{
    return line.substr(0, line.find("="));
}

std::string Config::getStrValue(const std::string& line)
{
    return line.substr(line.find("=") + 1);
}

void Config::load()
{
    std::string lineBuf;
    std::ifstream configFile(this->configFilePath.string());
    while (std::getline(configFile, lineBuf))
    {
        std::string key = Config::getStrKey(lineBuf);
        std::string Value = Config::getStrValue(lineBuf);
        this->setValue(key, value);
    }
    configFile.close();
}

