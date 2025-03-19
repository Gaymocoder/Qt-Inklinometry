#include "Inklin/Gui/FileTypeButton.h"

using namespace Inklin::Gui;

FileTypeButton::FileTypeButton(Inklin::SourceDataType fileType, QWidget* parent) : QPushButton(parent)
{
    this->dataType = fileType;
    switch (fileType)
    {
        case Inklin::ABSOLUTE:
            this->setText("Absolute");
            break;
            
        case Inklin::DELTA:
            this->setText("Delta");
            break;
            
        case Inklin::AZIMUTH:
            this->setText("Azimuth\n(in development)");
            this->setEnabled(false);
            break;
            
        default:
            break;
    }
}

Inklin::SourceDataType FileTypeButton::getDataType() const
{
    return this->dataType;
}
