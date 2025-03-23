#include "Inklin/Gui/StartPosWidget.h"

#include <QLabel>
#include <QGridLayout>

using namespace Inklin::Gui;

enum PositionSystemNames
{
    X = 0,
    Y = 1,
    Z = 2,
};

StartPosWidget::StartPosWidget(Inklin::Core::Config* appConfig, QWidget* parent) : QWidget(parent)
{
    this->appConfig = appConfig;
    double& StartX = appConfig->Value1;
    double& StartY = appConfig->Value2;
    double& StartZ = appConfig->Value3;
    
    QGridLayout* mainLayout = new QGridLayout(this);
    
    QLabel* posNames[3];
    posNames[X] = new QLabel("X");
    posNames[Y] = new QLabel("Y");
    posNames[Z] = new QLabel("Z");
    
    this->startPosValues[X] = new QLineEdit(std::to_string(StartX));
    this->startPosValues[Y] = new QLineEdit(std::to_string(StartY));
    this->startPosValues[Z] = new QLineEdit(std::to_string(StartZ));
    
    this->startPosValues[X]->setMaxLength(12);
    this->startPosValues[Y]->setMaxLength(12);
    this->startPosValues[Z]->setMaxLength(12);
    
    this->startPosValues[X]->setInputMask("0.0");
    this->startPosValues[Y]->setInputMask("0.0");
    this->startPosValues[Z]->setInputMask("0.0");
    
    this->applyStartPos = new QPushButton("Apply");
    
    mainLayout->addWidget(posNames[X], 0, 0, 1, 1);
    mainLayout->addWidget(posNames[Y], 0, 1, 1, 1);
    mainLayout->addWidget(posNames[Z], 0, 2, 1, 1);
    
    mainLayout->addWidget(startPosValues[X], 1, 0, 1, 1);
    mainLayout->addWidget(startPosValues[X], 1, 1, 1, 1);
    mainLayout->addWidget(startPosValues[X], 1, 2, 1, 1);
    
    mainLayout->addWidget(applyStartPos, 2, 1, 1, 1);
    
    this->setLayout(mainLayout);
}
