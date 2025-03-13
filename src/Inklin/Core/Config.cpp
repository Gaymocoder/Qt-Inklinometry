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

void Config::load() const
{
    std::string lineBuf;
    std::ifstream configFile(this->configFilePath.string());
    while (std::getline(configFile, lineBuf))
    {
        ConfigKeys key = Config::fromStrKey(Config::getStrKey(lineBuf));
        std::string strValue = Config::getStrValue(lineBuf);
    }
}
