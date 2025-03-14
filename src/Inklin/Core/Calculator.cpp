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
    
    this->calculateDataSet[DELTA] = &Calculator::fromDelta;
    this->calculateDataSet[AZIMUTH] = &Calculator::fromAzimuth;
    this->calculateDataSet[ABSOLUTE] = &Calculator::fromAbsolute;
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

Config Calculator::getConfig() const
{
    return this->appConfig;
}

void Calculator::onCalculateRequest() const
{
    this->calculateFile();
}

void Calculator::fromAbsolute(DataSet* prevDataBuf, DataSet* currDataBuf, double* prevTVD) const
{
    double& MD = currDataBuf->Value1;
    double& X  = currDataBuf->Value2;
    double& Y  = currDataBuf->Value3;
    
    double& prMD  = prevDataBuf->Value1;
    double& prX   = prevDataBuf->Value2;
    double& prY   = prevDataBuf->Value3;
    
    double A = pow(X - prX, 2);
    double B = pow(Y - prY, 2);
    double C = pow(MD - prMD, 2);
    
    *prevDataBuf = *currDataBuf;
    double Z = sqrt(C - (A + B));
    
    if (prevTVD)
    {
        Z += *prevTVD;
        *prevTVD = Z;
    }
    
    *currDataBuf = {X, Y, Z};
}

void Calculator::fromDelta(DataSet* prevDataBuf, DataSet* currDataBuf, double* prevTVD) const
{
    currDataBuf->Value2 += this->appConfig.startPosition.Value1; // X = dX + X0
    currDataBuf->Value3 += this->appConfig.startPosition.Value2; // Y = dY + Y0
    this->fromAbsolute(prevDataBuf, currDataBuf, prevTVD);
}

void Calculator::fromAzimuth(DataSet* prevDataBuf, DataSet* currDataBuf, double* prevTVD) const
{
}

void Calculator::calculateFile(std::ostream& out) const
{
    std::string strbuf;
    double prevTVD = 0;
    DataSet currDataBuf;
    DataSet prevDataBuf = this->appConfig.startPosition;
    
    out << this->appConfig.startPosition << std::endl;
    
    // To "Z X Y" record view
    prevDataBuf.Value3 = prevDataBuf.Value2;
    prevDataBuf.Value2 = prevDataBuf.Value1;
    prevDataBuf.Value1 = 0;
    
    std::ifstream absoluteFile(this->file.string());
    if (!absoluteFile)
        throw std::ios_base::failure("Calculator::calculateAbsoluteFile(): Failed to open the file");
    
    std::getline(absoluteFile, strbuf);
    while (std::getline(absoluteFile, strbuf))
    {
        std::stringstream ssbuf(strbuf);
        ssbuf >> currDataBuf;
        
        (this->*calculateDataSet[this->fileType])(&prevDataBuf, &currDataBuf, &prevTVD);
        out << currDataBuf << std::endl;
    }
    absoluteFile.close();
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
    int roundV1 = 11 - (static_cast <int> (std::log10(std::fabs(ds.Value1))) + 1);
    int roundV2 = 11 - (static_cast <int> (std::log10(std::fabs(ds.Value2))) + 1);
    int roundV3 = 11 - (static_cast <int> (std::log10(std::fabs(ds.Value3))) + 1);
    
    if (roundV1 > 10) roundV1 = 10;
    if (roundV2 > 10) roundV2 = 10;
    if (roundV3 > 10) roundV3 = 10;
    
    out << std::fixed << std::setprecision(roundV1) << ds.Value1 << "  "
        << std::fixed << std::setprecision(roundV2) << ds.Value2 << "  "
        << std::fixed << std::setprecision(roundV3) << ds.Value3;
    
    return out;
}

bool Inklin::Core::operator==(const DataSet& lv, const DataSet& rv)
{
    int roundV1 = 11 - (static_cast <int> (std::log10(std::fabs(lv.Value1))) + 1);
    int roundV2 = 11 - (static_cast <int> (std::log10(std::fabs(lv.Value2))) + 1);
    int roundV3 = 11 - (static_cast <int> (std::log10(std::fabs(lv.Value3))) + 1);
        
    return (
        std::fabs(lv.Value1 - rv.Value1) < std::pow(10, -roundV1) &&
        std::fabs(lv.Value2 - rv.Value2) < std::pow(10, -roundV2) &&
        std::fabs(lv.Value3 - rv.Value3) < std::pow(10, -roundV3)
    );
}
