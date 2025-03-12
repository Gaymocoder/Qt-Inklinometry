#ifndef __INKLIN_MAIN_WINDOW_H__
#define __INKLIN_MAIN_WINDOW_H__

#include <QMainWindow>

namespace Inklin
{
    class MainWindowWidget;
    
    class MainWindow : public QMainWindow
    {
        Q_OBJECT;
        
        private:
            MainWindowWidget* centralWidget;
            
        public:
            explicit MainWindow(QWidget* parent = nullptr);
    };
}

#endif
