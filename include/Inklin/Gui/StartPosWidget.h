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
                Config* appConfig;
                
                QLineEdit* startPos[3];
                QPushButton* applyStartPos;
                
            public:
                explicit StartPosWidget(QWidget* parent = nullptr);
                
            signals:
                void fireStartPosNew();
                
            public slots:
                virtual void onStartPosChange();
                virtual void onApplyButtonClick();
        };
    }
}

#endif
