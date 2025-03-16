#include "Inklin/Gui/MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Inklin::Gui::MainWindow window;
    window.show();
    return app.exec();
}
