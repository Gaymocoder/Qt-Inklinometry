#ifndef __INKLIN_CORE_CALCULATOR_H__
#define __INKLIN_CORE_CALCULATOR_H__

#include "Inklin/Core/Config.h"

#include <cstdint>
#include <iostream>
#include <filesystem>

#include <QWidget>

namespace FS = std::filesystem;

namespace Inklin
{
    namespace Core
    {
        class Calculator : public QObject
        {
            Q_OBJECT;
            
            private:
                FS::path file;
                Config appConfig;
                SourceDataType fileType;
                
                void (*calculateDataSet[3])(DataSet*, DataSet*);
                
                void autoIdentifyFileType();
                void calculateFile() const;
                
            public:
                Calculator(const FS::path& filePath, const FS::path& configFilePath = "./config.ini");
                
                static void fromDelta(DataSet* prevDataBuf, DataSet* currDataBuf);
                static void fromAzimuth(DataSet* prevDataBuf, DataSet* currDataBuf);
                static void fromAbsolute(DataSet* prevDataBuf, DataSet* currDataBuf);
                
                FS::path getFilePath() const;
                SourceDataType getFileType() const;
            
            signals:
                void fireCalculationFinished();
                
            protected slots:
                virtual void onFileChange(FS::path& newFile);
                virtual void onFileTypeChange(SourceDataType newFileType);
                virtual void onCalculateRequest() const;
        };
    }
}

#endif
