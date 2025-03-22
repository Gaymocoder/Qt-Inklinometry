#ifndef __INKLIN_CORE_CALCULATOR_H__
#define __INKLIN_CORE_CALCULATOR_H__

#include "Inklin/Core/Config.h"

#include <cstdint>
#include <iostream>
#include <filesystem>

#include <QObject>

namespace FS = std::filesystem;

template <typename TestNum, typename InType1, typename InType2, typename OutType1, typename OutType2>
struct CalculatorTestClass;

namespace Inklin
{
    namespace Core
    {
        class Calculator : public QObject
        {
            Q_OBJECT;
            
            template <typename TestNum, typename InType1, typename InType2, typename OutType1, typename OutType2>
            friend struct ::CalculatorTestClass;
            
            private:
                FS::path file;
                Config* appConfig;
                SourceDataType fileType;
                
                void (Calculator::*calculateDataSet[3])(DataSet*, DataSet*, double*) const;
                
                void autoIdentifyFileType();
                void calculateFile(DataSet* checkingBuf = nullptr) const;
                
            public:
                Calculator(const FS::path& filePath, FS::path configFilePath = "");
                Calculator(Calculator&& moved);
                Calculator& operator=(Calculator&& moved);
                virtual ~Calculator();
                
                void fromDelta(DataSet* prevDataBuf, DataSet* currDataBuf, double* prevTVD = nullptr) const;
                void fromAzimuth(DataSet* prevDataBuf, DataSet* currDataBuf, double* prevTVD = nullptr) const;
                void fromAbsolute(DataSet* prevDataBuf, DataSet* currDataBuf, double* prevTVD = nullptr) const;
                
                Config getConfig() const;
                FS::path getFilePath() const;
                SourceDataType getFileType() const;
            
            signals:
                void fireTypeAutoIdentified(SourceDataType newFileType) const;
                void fireCalculationFinished() const;
                
            public slots:
                virtual void onFileChange(const FS::path& newFile);
                virtual void onFileTypeChange(SourceDataType newFileType);
                virtual void onCalculateRequest() const;
        };
    }
}

#endif
