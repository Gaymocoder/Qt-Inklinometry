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
        class Config
        {
            private:
                const FS::path configFilePath;
                
            protected:
                static std::string getStrKey(const std::string& line);
                static std::string getStrValue(const std::string& line);
                
            public:
                Config(const FS::path& configPath);
                                
                virtual void save() const;
                virtual void load();
        };
    }
}

#endif
