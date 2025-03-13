#ifndef __INKLIN_CORE_CONFIG_H__
#define __INKLIN_CORE_CONFIG_H__

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
                
            private:
                DataSet startPosition;
                
            public:
                Config(FS::path& configPath);
                void save() const;
                void load();
        }
    }
}

#endif
