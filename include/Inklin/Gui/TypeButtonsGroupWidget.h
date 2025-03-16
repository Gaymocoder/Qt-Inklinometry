#ifndef __INKLIN_TYPE_BUTTONS_GROUP_WIDGET_H__
#define __INKLIN_TYPE_BUTTONS_GROUP_WIDGET_H__

#include "Inklin/Gui/FileTypeButton.h"

#include <QLabel>
#include <QWidget>

namespace Inklin
{
    namespace Gui
    {
        class TypeButtonsGroup : public QWidget
        {
            Q_OBJECT;
            
            private:
                QLabel* autoDefinedType;
                QButtonGroup* buttonTypeGroup;
            
            public:
                explicit TypeButtonsGroup(QWidget* parent = nullptr);
                
            signals:
                void fireFileTypeChanged(SourceDataType newFileType);
                
            public slots:
                virtual void onButtonToggled(QAbstractButton* button);
                virtual void onAutoTypeIdentified(SourceDataType newFileType);
        };
    }
}

#endif
