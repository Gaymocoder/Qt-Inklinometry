#include "Inklin/Core/Calculator.h"

#include <iomanip>
#include <fstream>
#include <stdexcept>

using Inklin::SourceDataType;
using namespace Inklin::Core;

Calculator::Calculator(const FS::path& filePath, const FS::path& configFilePath) : appConfig(configFilePath)
{
    this->file = filePath;
    this->fileType = NONE;
    
    this->calculateDataSet[DELTA] = Calculator::fromDelta;
    this->calculateDataSet[AZIMUTH] = Calculator::fromAzimuth;
    this->calculateDataSet[ABSOLUTE] = Calculator::fromAbsolute;
}

void Calculator::onFileChange(FS::path& newFile)
{
    this->file = newFile;
}

void Calculator::onFileTypeChange(Inklin::SourceDataType newFileType)
{
    this->fileType = newFileType;
}

FS::path Calculator::getFilePath() const
{
    return this->file;
}

Inklin::SourceDataType Calculator::getFileType() const
{
    return this->fileType;
}

void Calculator::onCalculateRequest() const
{
    this->calculateFile();
}

void Calculator::fromAbsolute(DataSet* prevDataBuf, DataSet* currDataBuf)
{
    double& MD = currDataBuf->Value1;
    double& X  = currDataBuf->Value2;
    double& Y  = currDataBuf->Value3;
    
    double& prMD  = prevDataBuf->Value2;
    double& prX   = prevDataBuf->Value2;
    double& prY   = prevDataBuf->Value2;
    
    double A = pow(X - prX, 2);
    double B = pow(Y - prY, 2);
    double C = pow(MD - prMD, 2);
    
    *prevDataBuf = *currDataBuf;
    
    *currDataBuf = {X, Y, sqrt(C - (A + B))};
}

void Calculator::fromDelta(DataSet* prevDataBuf, DataSet* currDataBuf)
{
}

void Calculator::fromAzimuth(DataSet* prevDataBuf, DataSet* currDataBuf)
{
}

void Calculator::calculateFile() const
{
    std::string strbuf;
    DataSet currDataBuf;
    DataSet prevDataBuf = this->appConfig.startPosition;
    
    std::ifstream absoluteFile(this->file.string());
    if (!absoluteFile)
        throw std::ios_base::failure("Calculator::calculateAbsoluteFile(): Failed to open the file");
    
    std::getline(absoluteFile, strbuf);
    while (std::getline(absoluteFile, strbuf))
    {
        std::stringstream ssbuf(strbuf);
        ssbuf >> currDataBuf;
        
        this->calculateDataSet[this->fileType](&prevDataBuf, &currDataBuf);
        std::cout << currDataBuf << std::endl;
    }
}

std::istream& Inklin::Core::operator>>(std::istream& in, DataSet& ds)
{
    in >> ds.Value1;
    in >> ds.Value2;
    in >> ds.Value3;
    
    return in;
}

std::ostream& Inklin::Core::operator<<(std::ostream& out, const DataSet& ds)
{
    out << std::setw(15) << std::left << std::fixed << std::setprecision(12) << ds.Value1
        << std::setw(15) << std::left << std::fixed << std::setprecision(12) << ds.Value2
        << std::setw(15) << std::left << std::fixed << std::setprecision(12) << ds.Value3;
    
    return out;
}
