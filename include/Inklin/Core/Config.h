#ifndef __INKLIN_CORE_CONFIG_H__
#define __INKLIN_CORE_CONFIG_H__

#include "Inklin/SimpleTypes.h"

#include <map>
#include <cstdint>
#include <filesystem>

namespace FS = std::filesystem;

template <typename TestNum, typename InType1, typename InType2, typename OutType>
struct ConfigTestClass;

namespace Inklin
{
    namespace Core
    {
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
                inline void setValue(const std::string& key, const std::string& value) {
                    this->setValue(Config::strToKey(key), value);
                }
                
                void setDefaultValue(ConfigKeys key);
                inline void setDefaultValue(const std::string& key) {
                    this->setDefaultValue(Config::strToKey(key));
                }
                
                virtual void save() const;
                virtual void load();
                
                virtual ~Config() = default;
                
            template <typename TestNum, typename InType1, typename InType2, typename OutType>
            friend struct ::ConfigTestClass;
        };
    }
}

#endif
