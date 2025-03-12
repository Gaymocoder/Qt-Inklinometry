#ifndef __INKLIN_MAIN_WINDOW_WIDGET_H__
#define __INKLIN_MAIN_WINDOW_WIDGET_H__

#include <QLabel>
#include <QWidget>
#include <QPushButton>

namespace Inklin
{
    class FileTypeButton;
    class FileSelectorWidget;
    
    class MainWindowWidget : public QWidget
    {
        Q_OBJECT;
        
        private:
            QLabel* chosenFile;
            QLabel* autoDefinedType;
            
            FileSelectorWidget* fileSelector;
            
            FileTypeButton* buttonAbsolute;
            FileTypeButton* buttonDelta;
            FileTypeButton* buttonAzimuth;
            
            QPushButton* buttonCalculate;
            
        public:
            explicit MainWindowWidget(QWidget* parent = nullptr);
    };
}

#endif
