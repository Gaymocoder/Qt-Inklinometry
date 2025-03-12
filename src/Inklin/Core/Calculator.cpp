#include "Inklin/Core/Calculator.h"

#include <stdexcept>

using namespace Inklin::Core;

Calculator::Calculator(FS::path& file)
{
    this->file = file;
    this->fileType = Inklin::SourceDataType::NONE;
}

void Calculator::onFileChange(FS::path& newFile)
{
    this->file = newFile;
}

void Calculator::onFileTypeChange(Inklin::SourceDataType newFileType)
{
    this->fileType = newFileType;
}

DataSet Calculator::getResult() const
{
    return this->result;
}

FS::path Calculator::getFilePath() const
{
    return this->file;
}

Inklin::SourceDataType Calculator::getFileType() const
{
    return this->fileType;
}

void Calculator::onCalculateRequest()
{
    this->startCalculatingFile();
}

void Calculator::startCalculatingFile()
{
    switch (this->fileType)
    {
        case SourceDataType::ABSOLUTE:
            this->calculateAbsoluteFile();
            break;
            
        case SourceDataType::AZIMUTH:
            this->calculateAzimuthFile();
            break;
            
        case SourceDataType::DELTA:
            this->calculateDeltaFile();
            break;
            
        default:
            throw std::invalid_argument("Calculator::startCalculatingFile(): Calculator::fileType cannot be NONE");
    }
}
