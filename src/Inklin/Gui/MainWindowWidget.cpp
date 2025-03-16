#include "Inklin/Gui/FileTypeButton.h"
#include "Inklin/Gui/MainWindowWidget.h"

#include <QFont>
#include <QLayout>
#include <QBoxLayout>

using namespace Inklin::Gui;

MainWindowWidget::MainWindowWidget(QWidget* parent) : QWidget(parent)
{
    QGridLayout* mainLayout = new QGridLayout(this);
    QVBoxLayout* layoutFileChoose = new QVBoxLayout();
    QGridLayout* layoutTypeChoose = new QGridLayout();
    
    QWidget* widgetTypeChoose = new QWidget();
    QWidget* widgetFileChoose = new QWidget();
    
    this->chosenFile = new QLabel("Choose a file with the source data", this);
    this->autoDefinedType = new QLabel("There'll be something", this);
    this->buttonFileSelect = new QPushButton("Select file", this);
    this->buttonCalculate = new QPushButton("Caclulate", this);
    
    QLabel* title = new QLabel("INKLINOMETRY", this);
    FileTypeButton* buttonDelta = new FileTypeButton(Inklin::DELTA, this);
    FileTypeButton* buttonAzimuth = new FileTypeButton(Inklin::AZIMUTH, this);
    FileTypeButton* buttonAbsolute = new FileTypeButton(Inklin::ABSOLUTE, this);
    
    title->setFont(QFont("Arial", 40, 20));    
    buttonDelta->setFixedSize(130, 50);
    buttonAzimuth->setFixedSize(130, 50);
    buttonAbsolute->setFixedSize(130, 50);
    buttonCalculate->setFixedSize(100, 30);
    buttonFileSelect->setFixedSize(100, 30);
    
    layoutFileChoose->addWidget(this->buttonFileSelect);
    layoutFileChoose->addWidget(this->chosenFile);
    layoutFileChoose->setAlignment(this->chosenFile, Qt::AlignHCenter | Qt::AlignTop);
    layoutFileChoose->setAlignment(this->buttonFileSelect, Qt::AlignCenter | Qt::AlignBottom);
    widgetFileChoose->setLayout(layoutFileChoose);
    
    layoutTypeChoose->addWidget(buttonDelta,     0, 1);
    layoutTypeChoose->addWidget(buttonAzimuth,   0, 2);
    layoutTypeChoose->addWidget(buttonAbsolute,  0, 0);
    layoutTypeChoose->addWidget(autoDefinedType, 1, 0, 1, 3);
    layoutTypeChoose->setAlignment(buttonDelta, Qt::AlignCenter);
    layoutTypeChoose->setAlignment(buttonAzimuth, Qt::AlignCenter);
    layoutTypeChoose->setAlignment(buttonAbsolute, Qt::AlignCenter);
    layoutTypeChoose->setAlignment(autoDefinedType, Qt::AlignCenter | Qt::AlignTop);
    widgetTypeChoose->setLayout(layoutTypeChoose);

    mainLayout->addWidget(widgetTypeChoose, 7, 0, 1, 6);
    mainLayout->addWidget(widgetFileChoose, 4, 0, 1, 6);
    mainLayout->addWidget(title,            0, 0, 2, 6, Qt::AlignCenter);
    mainLayout->addWidget(buttonCalculate, 10, 1, 1, 4, Qt::AlignCenter);
    
    this->setLayout(mainLayout);
}
