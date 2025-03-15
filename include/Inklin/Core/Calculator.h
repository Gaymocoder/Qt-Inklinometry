#ifndef __INKLIN_CORE_CALCULATOR_H__
#define __INKLIN_CORE_CALCULATOR_H__

#include "Inklin/Core/Config.h"

#include <cstdint>
#include <iostream>
#include <filesystem>

#include <QObject>

namespace FS = std::filesystem;

template <typename TestName, typename InType1, typename InType2, typename OutType1, typename OutType2>
struct CalculatorTestClass;

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
                
                void (Calculator::*calculateDataSet[3])(DataSet*, DataSet*) const;
                
                void autoIdentifyFileType();
                void calculateFile(std::ostream& out = std::cout) const;
                
            public:
                Calculator(const FS::path& filePath, const FS::path& configFilePath = "./config.ini");
                
                void fromDelta(DataSet* prevDataBuf, DataSet* currDataBuf) const;
                void fromAzimuth(DataSet* prevDataBuf, DataSet* currDataBuf) const;
                void fromAbsolute(DataSet* prevDataBuf, DataSet* currDataBuf) const;
                
                Config getConfig() const;
                FS::path getFilePath() const;
                SourceDataType getFileType() const;
            
            signals:
                void fireCalculationFinished();
                
            protected slots:
                virtual void onFileChange(FS::path& newFile);
                virtual void onFileTypeChange(SourceDataType newFileType);
                virtual void onCalculateRequest() const;
                
            friend struct CalculatorTestClass;
        };
    }
}

#endif
