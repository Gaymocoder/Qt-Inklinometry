#ifndef __INKLIN_START_POS_WIDGET_H__
#define __INKLIN_START_POS_WIDGET_H__

#include "Inklin/Core/Calculator.h"

#include <QLineEdit>
#include <QPushButton>

namespace Inklin
{
    namespace Gui
    {
        class StartPosWidget : public QWidget
        {
            Q_OBJECT;
            
            private:
                Core::Calculator* calculator;
                
                QLineEdit* startPosValues[3];
                QPushButton* applyStartPos;
                
            public:
                explicit StartPosWidget(Core::Calculator* calculator, QWidget* parent = nullptr);
                
            signals:
                void fireStartPosNew();
                
            public slots:
                virtual void onStartPosChange();
                virtual void onApplyButtonClick();
        };
    }
}

#endif
