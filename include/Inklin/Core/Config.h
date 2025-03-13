#ifndef __INKLIN_CORE_CONFIG_H__
#define __INKLIN_CORE_CONFIG_H__

#include <map>
#include <ctypes>
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
                
                static std::string getStrKey(std::string& line) const;
                static std::string getStrValue(std::string& line) const;
                
                
            protected:
                virtual void setDefault();
                
                template <typename ValueType>
                void deleteValue(ConfigKeys key);
                
            public:
                Config(const FS::path& configPath);
            
                template <typename ValueType>
                ValueType getValue(ConfigKeys key) const;
                
                template <typename ValueType>
                void setValue(ConfigKeys key, ValueType value);
                
                virtual void save() const;
                virtual void load();
                
                virtual ~Cofing();
        }
    }
}

#endif
