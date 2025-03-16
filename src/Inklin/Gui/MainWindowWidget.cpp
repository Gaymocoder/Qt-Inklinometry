#include "Inklin/Core/Calculator.h"

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
    const FS::path currentApplicationPath = FS::canonical("/proc/self/exe").remove_filename();
    Inklin::Core::Calculator* theCalculator = new Inklin::Core::Calculator("", currentApplicationPath/"config.ini");
    
    QGridLayout* mainLayout = new QGridLayout(this);
    QGridLayout* layoutFileChoose = new QGridLayout(this);
    
    QWidget* widgetFileChoose = new QWidget();
    TypeButtonsGroup* widgetTypeChoose = new TypeButtonsGroup();
    
    this->chosenFile = new QLabel("Choose a file with the source data", this);
    this->buttonFileSelect = new QPushButton("Select file", this);
    this->buttonCalculate = new QPushButton("Caclulate", this);
    
    QLabel* title = new QLabel("INKLINOMETRY", this);
    
    title->setFont(QFont("Arial", 40, 20));
    chosenFile->setAlignment(Qt::AlignCenter);
    buttonCalculate->setEnabled(false);
    
    buttonCalculate->setFixedSize(100, 30);
    buttonFileSelect->setFixedSize(100, 30);
    
    layoutFileChoose->addWidget(this->buttonFileSelect);
    layoutFileChoose->addWidget(this->chosenFile);
    layoutFileChoose->setAlignment(this->chosenFile, Qt::AlignCenter | Qt::AlignTop);
    layoutFileChoose->setAlignment(this->buttonFileSelect, Qt::AlignCenter | Qt::AlignBottom);
    widgetFileChoose->setLayout(layoutFileChoose);

    mainLayout->addWidget(widgetTypeChoose, 7, 0, 1, 6);
    mainLayout->addWidget(widgetFileChoose, 4, 0, 1, 6);
    mainLayout->addWidget(title,            0, 0, 2, 6, Qt::AlignCenter);
    mainLayout->addWidget(buttonCalculate, 10, 1, 1, 4, Qt::AlignCenter);
    
    connect(this, &MainWindowWidget::fireNewFileSelected, theCalculator, &Inklin::Core::Calculator::onFileChange);
    connect(buttonCalculate,  &QPushButton::clicked, theCalculator, &Inklin::Core::Calculator::onCalculateRequest);
    connect(buttonFileSelect, &QPushButton::clicked, this, &MainWindowWidget::onFileSelectButtonClick);
    connect(widgetTypeChoose, &TypeButtonsGroup::fireFileTypeChanged, theCalculator, &Inklin::Core::Calculator::onFileTypeChange);
    connect(widgetTypeChoose, &TypeButtonsGroup::fireFileTypeChanged, this, &MainWindowWidget::onFileTypeSelected);
    connect(theCalculator, &Inklin::Core::Calculator::fireTypeAutoIdentified, widgetTypeChoose, &TypeButtonsGroup::onAutoTypeIdentified);
    connect(theCalculator, &Inklin::Core::Calculator::fireCalculationFinished, this, &MainWindowWidget::onCalculationFinished);
    
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
        emit fireNewFileSelected(fileSelected);
        
        if (fileSelected.length() > 50)
            fileSelected.replace(25, fileSelected.length() - 50, "...");
        this->chosenFile->setText((std::string("Selected file:\n") + fileSelected).c_str());
    }
}

void MainWindowWidget::onFileTypeSelected()
{
    if (!this->buttonCalculate->isEnabled())
        this->buttonCalculate->setEnabled(true);
}

void MainWindowWidget::onCalculationFinished()
{
    std::cout << "End of calculating of the " << this->chosenFile->text().toStdString() << std::endl;
    QMessageBox::information(this, "Calculations finished", "Calculations are finished! All data was printed to STDOUT");
}
