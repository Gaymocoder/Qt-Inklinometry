#ifndef __INKLIN_CORE_CALCULATOR_H__
#define __INKLIN_CORE_CALCULATOR_H__

#include <cstdint>
#include <iostream>
#include <filesystem>

#include <QWidget>

namespace FS = std::filesystem;

namespace Inklin
{
    enum SourceDataType
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
                SourceDataType fileType;
                void (*calculateDataSet[3])(DataSet*);
                
                void autoIdentifyFileType();
                
                void calculateFile();
                
            public:
                Calculator(FS::path& file);
                
                static void fromDelta(DataSet* data);
                static void fromAzimuth(DataSet* data);
                static void fromAbsolute(DataSet* data);
                
                FS::path getFilePath() const;
                SourceDataType getFileType() const;
            
            signals:
                void fireCalculationFinished();
                
            private slots:
                void onFileChange(FS::path& newFile);
                void onFileTypeChange(SourceDataType newFileType);
                void onCalculateRequest();
        };
        
        std::istream& operator>>(std::istream& in, DataSet& ds);
        std::ostream& operator<<(std::ostream& out, const DataSet& ds);
    }
}

#endif

