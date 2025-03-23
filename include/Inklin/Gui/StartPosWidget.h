#ifndef __INKLIN_START_POS_WIDGET_H__
#define __INKLIN_START_POS_WIDGET_H__

#include "Inklin/SimpleTypes.h"

#include <QLineEdit>
#include <QPushButton>

namespace Inklin
{
    namespace Gui
    {
        class StartPosWidget : QWidget
        {
            Q_OBJECT;
            
            private:
                Core::Config* appConfig;
                
                QLineEdit* startPosValues[3];
                QPushButton* applyStartPos;
                
            public:
                explicit StartPosWidget(Core::Config* appConfig, QWidget* parent = nullptr);
                
            signals:
                void fireStartPosNew();
                
            public slots:
                virtual void onStartPosChange();
                virtual void onApplyButtonClick();
        };
    }
}

#endif
