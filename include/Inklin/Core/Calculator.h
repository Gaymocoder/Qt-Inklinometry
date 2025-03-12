#ifndef __INKLIN_CORE_CALCULATOR_H__
#define __INKLIN_CORE_CALCULATOR_H__

#include <filesystem>

#include <QWidget>

namespace FS = std::filesystem;

namespace Inklin
{
    enum DataFileType
    {
        ABSOLUTE = 0,
        DELTA    = 1,
        AZIMUTH  = 2,
        NONE     = 3,
    };
    
    namespace Core
    {
        class Calculator : public QObject
        {
            Q_OBJECT;
            
            private:
                FS::path file;
                DataFileType fileType;
                
                void autoIdentifyFileType();
                
            public:
                Calculator(FS::path& file);
            
            signals:
                void fireCalculationFinished();
                
            private slots:
                void onFileChange(FS::path& newFile);
                void onFileTypeChange(DataFileType newFileType);
                void onCalculateRequest();
        };
    }
}

#endif

