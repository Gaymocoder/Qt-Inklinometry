#ifndef __INKLIN_MAIN_WINDOW_H__
#define __INKLIN_MAIN_WINDOW_H__

#include "Inklin/Gui/MainWindowWidget.h"

#include <QMainWindow>

namespace Inklin
{
    namespace Gui
    {
        class MainWindow : public QMainWindow
        {
            Q_OBJECT;
            
            private:
                MainWindowWidget* centralWidget;
                
            public:
                explicit MainWindow(QWidget* parent = nullptr);
        };
    }
}

#endif
