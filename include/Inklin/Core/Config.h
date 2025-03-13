#ifndef __INKLIN_CORE_CONFIG_H__
#define __INKLIN_CORE_CONFIG_H__

#include "Inklin/Core/Calculator.h"

#include <map>
#include <cstdint>
#include <filesystem>

namespace FS = std::filesystem;

namespace Inklin
{
    namespace Core
    {
        enum class ConfigKeys
        {
            STARTPOS,
        };
        
        class Config
        {
            private:
                const FS::path configFilePath;
                
            protected:
                static std::string getStrKey(const std::string& line);
                static std::string getStrValue(const std::string& line);
                
                static ConfigKeys strToKey(const std::string& key);
                static std::string pairToStr(ConfigKeys key, const void* value_ptr);
                
            public:
                DataSet startPosition;
                
            public:
                Config(const FS::path& configPath);
                
                void setValue(ConfigKeys key, const std::string& value);
                inline void setValue(const std::string& key, const std::string& value);
                
                void setDefaultValue(ConfigKeys key);
                inline void setDefaultValue(const std::string& key);
                
                virtual void save() const;
                virtual void load();
        };
    }
}

#endif
