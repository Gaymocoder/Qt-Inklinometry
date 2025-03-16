#include "Inklin/Gui/TypeButtonsGroupWidget.h"

#include <QButtonGroup>
#include <QGridLayout>

using namespace Inklin::Gui;

TypeButtonsGroup::TypeButtonsGroup(QWidget* parent) : QWidget(parent)
{
    QGridLayout* mainLayout = new QGridLayout();
 
    this->selectedType = Inklin::NONE;
    this->autoDefinedType = new QLabel("There'll be something", this);
    
    QButtonGroup* buttonTypeGroup = new QButtonGroup(this);
    FileTypeButton* buttonDelta = new FileTypeButton(Inklin::DELTA, this);
    FileTypeButton* buttonAzimuth = new FileTypeButton(Inklin::AZIMUTH, this);
    FileTypeButton* buttonAbsolute = new FileTypeButton(Inklin::ABSOLUTE, this);
    
    buttonTypeGroup->setExclusive(true);
    buttonTypeGroup->addButton(buttonDelta, 1);
    buttonTypeGroup->addButton(buttonAzimuth, 2);
    buttonTypeGroup->addButton(buttonAbsolute, 3);
    
    buttonDelta->setCheckable(true);
    buttonAzimuth->setCheckable(true);
    buttonAbsolute->setCheckable(true);
    
    buttonDelta->setFixedSize(130, 50);
    buttonAzimuth->setFixedSize(130, 50);
    buttonAbsolute->setFixedSize(130, 50);
    
    mainLayout->addWidget(buttonDelta,     0, 1);
    mainLayout->addWidget(buttonAzimuth,   0, 2);
    mainLayout->addWidget(buttonAbsolute,  0, 0);
    mainLayout->addWidget(autoDefinedType, 1, 0, 1, 3);
    
    mainLayout->setAlignment(buttonDelta, Qt::AlignCenter);
    mainLayout->setAlignment(buttonAzimuth, Qt::AlignCenter);
    mainLayout->setAlignment(buttonAbsolute, Qt::AlignCenter);
    mainLayout->setAlignment(autoDefinedType, Qt::AlignCenter | Qt::AlignTop);
    
    this->setLayout(mainLayout);
}

void TypeButtonsGroup::onButtonClicked(QAbstractButton* button)
{
}

void TypeButtonsGroup::onAutoTypeIdentified(Inklin::SourceDataType newFileType)
{
}
