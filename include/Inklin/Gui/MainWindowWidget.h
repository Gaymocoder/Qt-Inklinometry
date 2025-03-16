#ifndef __INKLIN_MAIN_WINDOW_WIDGET_H__
#define __INKLIN_MAIN_WINDOW_WIDGET_H__

#include "Inklin/Gui/FileSelectorWidget.h"

#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>

namespace Inklin
{
    namespace Gui
    {
        class MainWindowWidget : public QWidget
        {
            Q_OBJECT;
            
            private:
                QLabel* chosenFile;
                QLabel* autoDefinedType;
                
                FileSelectorWidget* fileSelector;
                
                QButtonGroup* buttonTypes;
                
                QPushButton* buttonCalculate;
                
            public:
                explicit MainWindowWidget(QWidget* parent = nullptr);
        };
    }
}

#endif
