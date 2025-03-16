#include "Inklin/Gui/MainWindowWidget.h"
#include "Inklin/Gui/TypeButtonsGroupWidget.h"

#include <QFont>
#include <QLayout>
#include <QBoxLayout>
#include <QButtonGroup>

using namespace Inklin::Gui;

MainWindowWidget::MainWindowWidget(QWidget* parent) : QWidget(parent)
{
    QGridLayout* mainLayout = new QGridLayout(this);
    QVBoxLayout* layoutFileChoose = new QVBoxLayout();
    QGridLayout* layoutTypeChoose = new QGridLayout();
    
    QWidget* widgetFileChoose = new QWidget();
    TypeButtonsGroup* widgetTypeChoose = new TypeButtonsGroup();
    
    this->chosenFile = new QLabel("Choose a file with the source data", this);
    this->buttonFileSelect = new QPushButton("Select file", this);
    this->buttonCalculate = new QPushButton("Caclulate", this);
    
    QLabel* title = new QLabel("INKLINOMETRY", this);
    
    title->setFont(QFont("Arial", 40, 20));    

    buttonCalculate->setFixedSize(100, 30);
    buttonFileSelect->setFixedSize(100, 30);
    
    layoutFileChoose->addWidget(this->buttonFileSelect);
    layoutFileChoose->addWidget(this->chosenFile);
    layoutFileChoose->setAlignment(this->chosenFile, Qt::AlignHCenter | Qt::AlignTop);
    layoutFileChoose->setAlignment(this->buttonFileSelect, Qt::AlignCenter | Qt::AlignBottom);
    widgetFileChoose->setLayout(layoutFileChoose);

    mainLayout->addWidget(widgetTypeChoose, 7, 0, 1, 6);
    mainLayout->addWidget(widgetFileChoose, 4, 0, 1, 6);
    mainLayout->addWidget(title,            0, 0, 2, 6, Qt::AlignCenter);
    mainLayout->addWidget(buttonCalculate, 10, 1, 1, 4, Qt::AlignCenter);
    
    this->setLayout(mainLayout);
}
