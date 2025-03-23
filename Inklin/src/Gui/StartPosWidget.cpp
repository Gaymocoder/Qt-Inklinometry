#include "Inklin/Gui/StartPosWidget.h"

#include <QLabel>
#include <QGridLayout>
#include <QDoubleValidator>

using namespace Inklin::Gui;

enum PositionSystemNames
{
    X = 0,
    Y = 1,
    Z = 2,
};

StartPosWidget::StartPosWidget(Inklin::Core::Calculator* calculator, QWidget* parent) : QWidget(parent)
{
    this->calculator = calculator;
    Inklin::Core::Config appConfig = calculator->getConfig();
    QDoubleValidator* valueValidator = new QDoubleValidator(0, 10000000000, -1, this);
    
    double& StartX = appConfig.startPosition.Value1;
    double& StartY = appConfig.startPosition.Value2;
    double& StartZ = appConfig.startPosition.Value3;
    
    QGridLayout* mainLayout = new QGridLayout(this);
    
    QLabel* posNames[3];
    posNames[X] = new QLabel("X<sub>0</sub>");
    posNames[Y] = new QLabel("Y<sub>0</sub>");
    posNames[Z] = new QLabel("Z<sub>0</sub>");
    
    posNames[X]->setFont(QFont("Arial", 12));
    posNames[Y]->setFont(QFont("Arial", 12));
    posNames[Z]->setFont(QFont("Arial", 12));
    
    this->startPosValues[X] = new QLineEdit(QString(std::to_string(StartX).c_str()));
    this->startPosValues[Y] = new QLineEdit(QString(std::to_string(StartY).c_str()));
    this->startPosValues[Z] = new QLineEdit(QString(std::to_string(StartZ).c_str()));
    
    this->startPosValues[X]->setMaxLength(12);
    this->startPosValues[Y]->setMaxLength(12);
    this->startPosValues[Z]->setMaxLength(12);
    
    this->startPosValues[X]->setAlignment(Qt::AlignCenter);
    this->startPosValues[Y]->setAlignment(Qt::AlignCenter);
    this->startPosValues[Z]->setAlignment(Qt::AlignCenter);
    
    this->startPosValues[X]->setValidator(valueValidator);
    this->startPosValues[Y]->setValidator(valueValidator);
    this->startPosValues[Z]->setValidator(valueValidator);
    
    this->applyStartPos = new QPushButton("Apply");
    this->applyStartPos->setFixedSize(65, 28);
    this->applyStartPos->setEnabled(false);
    
    mainLayout->addWidget(posNames[X], 0, 0, 1, 1);
    mainLayout->addWidget(posNames[Y], 0, 1, 1, 1);
    mainLayout->addWidget(posNames[Z], 0, 2, 1, 1);
    mainLayout->addWidget(startPosValues[X], 1, 0, 1, 1);
    mainLayout->addWidget(startPosValues[Y], 1, 1, 1, 1);
    mainLayout->addWidget(startPosValues[Z], 1, 2, 1, 1);
    mainLayout->addWidget(applyStartPos, 2, 1, 1, 1);
    
    mainLayout->setAlignment(posNames[X], Qt::AlignCenter | Qt::AlignBottom);
    mainLayout->setAlignment(posNames[Y], Qt::AlignCenter | Qt::AlignBottom);
    mainLayout->setAlignment(posNames[Z], Qt::AlignCenter | Qt::AlignBottom);
    mainLayout->setAlignment(startPosValues[X], Qt::AlignCenter | Qt::AlignTop);
    mainLayout->setAlignment(startPosValues[Y], Qt::AlignCenter | Qt::AlignTop);
    mainLayout->setAlignment(startPosValues[Z], Qt::AlignCenter | Qt::AlignTop);
    mainLayout->setAlignment(applyStartPos, Qt::AlignCenter);
    
    connect(this->startPosValues[X], &QLineEdit::textEdited, this, &StartPosWidget::onStartPosChange);
    connect(this->startPosValues[Y], &QLineEdit::textEdited, this, &StartPosWidget::onStartPosChange);
    connect(this->startPosValues[Z], &QLineEdit::textEdited, this, &StartPosWidget::onStartPosChange);
    connect(this->applyStartPos, &QPushButton::clicked, this, &StartPosWidget::onApplyButtonClick);
    
    this->setLayout(mainLayout);
}

void StartPosWidget::onStartPosChange()
{
    if (!this->applyStartPos->isEnabled())
        this->applyStartPos->setEnabled(true);
}

void StartPosWidget::onApplyButtonClick()
{
    QString qstrStartPosition = this->startPosValues[X]->text() + " " +
                                this->startPosValues[Y]->text() + " " +
                                this->startPosValues[Z]->text();
    qstrStartPosition = qstrStartPosition.replace(',', '.');
    this->calculator->setConfigValue("STARTPOS", qstrStartPosition.toStdString());
    this->applyStartPos->setEnabled(false);
}
