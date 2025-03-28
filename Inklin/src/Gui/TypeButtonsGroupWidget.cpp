#include "Inklin/Gui/TypeButtonsGroupWidget.h"

#include <QButtonGroup>
#include <QGridLayout>

using namespace Inklin::Gui;

TypeButtonsGroup::TypeButtonsGroup(QWidget* parent) : QWidget(parent)
{
    QGridLayout* mainLayout = new QGridLayout(this);
 
    this->autoDefinedType = new QLabel("", this);
    
    this->buttonTypeGroup = new QButtonGroup(this);
    FileTypeButton* buttonDelta = new FileTypeButton(Inklin::DELTA, this);
    FileTypeButton* buttonAzimuth = new FileTypeButton(Inklin::AZIMUTH, this);
    FileTypeButton* buttonAbsolute = new FileTypeButton(Inklin::ABSOLUTE, this);
    
    this->buttonTypeGroup->setExclusive(true);
    this->buttonTypeGroup->addButton(buttonDelta, 1);
    this->buttonTypeGroup->addButton(buttonAzimuth, 2);
    this->buttonTypeGroup->addButton(buttonAbsolute, 0);
    
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
    
    connect(this->buttonTypeGroup, &QButtonGroup::buttonToggled, this, &TypeButtonsGroup::onButtonToggled);
    
    this->setLayout(mainLayout);
}

bool TypeButtonsGroup::isTypeSelected()
{
    return (this->buttonTypeGroup->checkedButton() != nullptr);
}

void TypeButtonsGroup::onButtonToggled(QAbstractButton* button, bool checked)
{
    if (!checked) return;
    FileTypeButton* ftButton = dynamic_cast <FileTypeButton*> (button);
    emit fireFileTypeChanged(ftButton->getDataType());
}

void TypeButtonsGroup::onAutoTypeIdentified(Inklin::SourceDataType newFileType)
{
    if (newFileType == Inklin::NONE)
    {
        if (this->isTypeSelected())
        {
            emit fireFileTypeChanged((Inklin::SourceDataType) this->buttonTypeGroup->checkedId());
            return;
        }
        
        this->autoDefinedType->setText("Cannot automatically identify file type");
        return;
    }
    this->buttonTypeGroup->button(newFileType)->setChecked(true);
    this->autoDefinedType->setText("File type identified automatically");
    
    emit fireFileTypeChanged(newFileType);
}
