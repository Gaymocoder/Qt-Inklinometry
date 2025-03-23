#ifndef __INKLIN_MAIN_WINDOW_WIDGET_H__
#define __INKLIN_MAIN_WINDOW_WIDGET_H__

#include <filesystem>

#include <QLabel>
#include <QWidget>
#include <QPushButton>

namespace FS = std::filesystem;

namespace Inklin
{
    namespace Gui
    {
        class MainWindowWidget : public QWidget
        {
            Q_OBJECT;
            
            private:
                QLabel* chosenFileLabel;
                
                QPushButton* buttonFileSelect;
                QPushButton* buttonCalculate;
                
            public:
                explicit MainWindowWidget(QWidget* parent = nullptr);
                
            signals:
                void fireNewFileSelected(const FS::path& newFilePath);
                
            public slots:
                virtual void onFileSelectButtonClick();
                virtual void onCalculationFinished();
                virtual void onFileTypeSelected();
        };
    }
}

#endif
