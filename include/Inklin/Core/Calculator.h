#ifndef __INKLIN_CORE_CALCULATOR_H__
#define __INKLIN_CORE_CALCULATOR_H__

#include <filesystem>

#include <QWidget>

namespace FS = std::filesystem;

namespace Inklin
{
    enum class SourceDataType
    {
        ABSOLUTE = 0,
        DELTA    = 1,
        AZIMUTH  = 2,
        NONE     = 3,
    };
    
    namespace Core
    {
        struct DataSet
        {
            double Value1;
            double Value2;
            double Value3;
        };
        
        class Calculator : public QObject
        {
            Q_OBJECT;
            
            private:
                FS::path file;
                SourceDataType fileType = SourceDataType::NONE;
                
                void autoIdentifyFileType();
                
            public:
                Calculator(FS::path& file);
                
                static void fromDelta(DataSet* data);
                static void fromAzimuth(DataSet* data);
                static void fromAbsolute(DataSet* data);
            
            signals:
                void fireCalculationFinished();
                
            private slots:
                void onFileChange(FS::path& newFile);
                void onFileTypeChange(SourceDataType newFileType);
                void onCalculateRequest();
        };
    }
}

#endif

