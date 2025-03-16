#include "Inklin/Gui/MainWindow.h"

#include <QScreen>
#include <QApplication>

using namespace Inklin::Gui;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    this->centralWidget = new MainWindowWidget(this);
    this->setCentralWidget(this->centralWidget);
    
    QScreen *screen = QGuiApplication::primaryScreen();
    int width = screen->geometry().width() * 0.25;
    int height = screen->geometry().height() * 0.6;
    
    int x = (screen->geometry().width() - width) / 2;
    int y = (screen->geometry().height() - height) / 2;
    
    this->move(x, y);
    this->setFixedSize(width, height);
}
