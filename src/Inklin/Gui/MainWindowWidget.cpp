#include "Inklin/Gui/FileTypeButton.h"
#include "Inklin/Gui/MainWindowWidget.h"

#include <QVBoxLayout>

using namespace Inklin::Gui;

MainWindowWidget::MainWindowWidget(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    
    FileTypeButton* buttonAbsolute = new FileTypeButton(Inklin::ABSOLUTE, this);
    FileTypeButton* buttonDelta = new FileTypeButton(Inklin::DELTA, this);
    FileTypeButton* buttonAzimuth = new FileTypeButton(Inklin::AZIMUTH, this);
    
    mainLayout->addWidget(buttonAbsolute);
    mainLayout->addWidget(buttonDelta);
    mainLayout->addWidget(buttonAzimuth);
    
    this->setLayout(mainLayout);
}
