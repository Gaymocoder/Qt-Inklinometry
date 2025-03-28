#include "Inklin/Core/Calculator.h"

#include "Inklin/Gui/StartPosWidget.h"
#include "Inklin/Gui/MainWindowWidget.h"
#include "Inklin/Gui/TypeButtonsGroupWidget.h"

#include <QFont>
#include <QLayout>
#include <QBoxLayout>
#include <QButtonGroup>
#include <QMessageBox>
#include <QFileDialog>

using namespace Inklin::Gui;

MainWindowWidget::MainWindowWidget(QWidget* parent) : QWidget(parent)
{
    Inklin::Core::Calculator* theCalculator = new Inklin::Core::Calculator("");
    
    QWidget* widgetFileChoose = new QWidget(this);
    StartPosWidget* widgetStartPosEdit = new StartPosWidget(theCalculator, this);
    
    QGridLayout* mainLayout = new QGridLayout(this);
    QGridLayout* layoutFileChoose = new QGridLayout(widgetFileChoose);
    
    this->widgetTypeChoose = new TypeButtonsGroup(this);
    this->chosenFileLabel = new QLabel("Choose a file with the source data", this);
    this->buttonFileSelect = new QPushButton("Select file", this);
    this->buttonCalculate = new QPushButton("Caclulate", this);
    
    QLabel* title = new QLabel("INKLINOMETRY", this);
    
    title->setFont(QFont("Arial", 40, 20));
    chosenFileLabel->setAlignment(Qt::AlignCenter);
    buttonCalculate->setEnabled(false);
    
    buttonCalculate->setFixedSize(100, 30);
    buttonFileSelect->setFixedSize(100, 30);
    
    layoutFileChoose->addWidget(this->buttonFileSelect);
    layoutFileChoose->addWidget(this->chosenFileLabel);
    layoutFileChoose->setAlignment(this->chosenFileLabel,  Qt::AlignCenter | Qt::AlignTop);
    layoutFileChoose->setAlignment(this->buttonFileSelect, Qt::AlignCenter | Qt::AlignBottom);
    widgetFileChoose->setLayout(layoutFileChoose);

    mainLayout->addWidget(title,              0, 0, 3, 12, Qt::AlignCenter);
    mainLayout->addWidget(widgetStartPosEdit, 3, 0, 2, 12);
    mainLayout->addWidget(new QWidget(this),  6, 0, 1, 12);
    mainLayout->addWidget(widgetFileChoose,  10, 0, 2, 12);
    mainLayout->addWidget(widgetTypeChoose,  16, 0, 2, 12);
    mainLayout->addWidget(buttonCalculate,   20, 2, 2,  8, Qt::AlignCenter);
    
    connect(this, &MainWindowWidget::fireNewFileSelected, theCalculator, &Inklin::Core::Calculator::onFileChange);
    connect(this, &MainWindowWidget::fireNewFileSelected, this, &MainWindowWidget::calculateButtonEnableRequest);
    
    connect(widgetTypeChoose, &TypeButtonsGroup::fireFileTypeChanged, theCalculator, &Inklin::Core::Calculator::onFileTypeChange);
    connect(widgetTypeChoose, &TypeButtonsGroup::fireFileTypeChanged, this, &MainWindowWidget::calculateButtonEnableRequest);
    
    connect(theCalculator, &Inklin::Core::Calculator::fireTypeAutoIdentified, widgetTypeChoose, &TypeButtonsGroup::onAutoTypeIdentified);
    connect(theCalculator, &Inklin::Core::Calculator::fireCalculationFinished, this, &MainWindowWidget::onCalculationFinished);
    
    connect(buttonCalculate, &QPushButton::clicked, theCalculator, &Inklin::Core::Calculator::onCalculateRequest);
    connect(buttonFileSelect, &QPushButton::clicked, this, &MainWindowWidget::onFileSelectButtonClick);
    
    this->setLayout(mainLayout);
}

void MainWindowWidget::onFileSelectButtonClick()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter("Текстовые документы (*.txt);;Все файлы (*.*)");
    dialog.setViewMode(QFileDialog::Detail);
    
    if(dialog.exec())
    {
        std::string fileSelected = dialog.selectedFiles().first().toStdString();
        if (fileSelected.length() > 50)
            fileSelected.replace(25, fileSelected.length() - 50, "...");
        this->chosenFileLabel->setText((std::string("Selected file:\n") + fileSelected).c_str());
        
        emit fireNewFileSelected(fileSelected);
    }
}

void MainWindowWidget::calculateButtonEnableRequest()
{
    bool fileIsSelected = this->chosenFileLabel->text() != "Choose a file with the source data";
    bool typeIsSelected = this->widgetTypeChoose->isTypeSelected();
    
    if (fileIsSelected && typeIsSelected)
        this->buttonCalculate->setEnabled(true);
}

void MainWindowWidget::onCalculationFinished()
{
    std::cout << "End of calculating of the " << this->chosenFileLabel->text().toStdString() << std::endl;
    QMessageBox::information(this, "Calculations finished", "Calculations are finished! All data was printed to STDOUT");
}
