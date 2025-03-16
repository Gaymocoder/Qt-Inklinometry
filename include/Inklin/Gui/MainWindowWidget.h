#ifndef __INKLIN_MAIN_WINDOW_WIDGET_H__
#define __INKLIN_MAIN_WINDOW_WIDGET_H__

#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
#include <QFileDialog>

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
                
                QFileDialog* fileSelector;
                
                QButtonGroup* buttonTypes;
                QPushButton* buttonFileSelect;
                QPushButton* buttonCalculate;
                
            public:
                explicit MainWindowWidget(QWidget* parent = nullptr);
        };
    }
}

#endif
