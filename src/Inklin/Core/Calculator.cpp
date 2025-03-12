#include "Calculator.h"

using namespace Inklin::Core;

Calculator::Calculator(FS::path& file)
{
    this->file = file;
    this->fileType = Inklin::SourceDataType::NONE;
}

void Calculator::onFileChange(FS::path& newFile)
{
    this->file = file;
}

void Calculator::onFileTypeChange(Inklin::SourceDataType newFileType)
{
    this->fileType = newFileType;
}

DataSet Calculator::getResult()
{
    return this->result;
}

FS::path Calculator::getFilePath()
{
    return this->file;
}

FS::path Calculator::getFileType()
{
    return this->fileType;
}
