#ifndef __INKLIN_CORE_CONFIG_H__
#define __INKLIN_CORE_CONFIG_H__

#include <map>
#include <cstdint>
#include <filesystem>

namespace FS = std::filesystem;

namespace Inklin
{
    namespace Core
    {
        constexpr uint16_t configKeysAmount = 1;
        
        enum ConfigKeys
        {
            STARTPOS = 0, // Inklin::Core::DataSet
        };
        
        class Config
        {
            private:
                const FS::path configFilePath;
                void* config[configKeysAmount];
                
            protected:
                static std::string getStrKey(const std::string& line);
                static std::string getStrValue(const std::string& line);
                
                virtual void deleteValue(uint16_t key);
                virtual void setDefaultValue(uint16_t key);
                
            public:
                Config(const FS::path& configPath);
                
                void setDefault();
            
                template <typename ValueType>
                ValueType getValue(uint16_t key, ValueType* ptr);
                
                template <typename ValueType>
                void setValue(uint16_t key, ValueType value);
                
                virtual void save() const;
                virtual void load();
                
                virtual ~Config();
        };
    }
}

#endif
