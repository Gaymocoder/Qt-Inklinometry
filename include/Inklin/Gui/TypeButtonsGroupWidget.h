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
                SourceDataType selectedType;
                QLabel* autoDefinedType;
            
            public:
                explicit TypeButtonsGroup(QWidget* parent = nullptr);
                
            signals:
                void fireFileTypeChanged(SourceDataType newFileType);
                
            protected slots:
                virtual void onButtonClicked(QAbstractButton* button);
                virtual void onAutoTypeIdentified(SourceDataType newFileType);
        };
    }
}

#endif
