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
                
            public:
                Config(const FS::path& configPath);
                
                template <typename ValueType>
                void setValue(ConfigKeys key, ValueType value);
            
                template <typename ValueType>
                ValueType getValue(ConfigKeys) const;
                
                virtual void save() const;
                virtual void load();
                
                virtual ~Cofing();
        }
    }
}

#endif
