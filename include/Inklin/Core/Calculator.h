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
    };
    
    namespace Core
    {
        class Calculator : public QObject
        {
            Q_OBJECT;
            
            private:
                FS::path file;
                DataFileType fileType;
                
            public:
                explicit Calculator(QWidget* parent = nullptr);
            
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

