#ifndef __INKLIN_FILE_SELECTOR_WIDGET_H__
#define __INKLIN_FILE_SELECTOR_WIDGET_H__

#include "Inklin/SimpleTypes.h"

#include <QPushButton>

namespace Inklin
{
    namespace Gui
    {
        class FileSelectorWidget : public QFileDialog
        {
            Q_OBJECT;
            
            private:
                SourceDataType dataType;
                
            public:
                explicit FileSelectorWidget(QWidget* parent = nullptr);
                
            signals:
                void fireFileSelected();
        };
    }
}

#endif
