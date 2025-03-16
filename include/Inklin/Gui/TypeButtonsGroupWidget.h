#ifndef __INKLIN_TYPE_BUTTONS_GROUP_WIDGET_H__
#define __INKLIN_TYPE_BUTTONS_GROUP_WIDGET_H__

#include "Inklin/SimpleTypes.h"

#include <QLabel>
#include <QPushButton>

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
                void onFileSelected();
                void onButtonClicked();
        };
    }
}

#endif
