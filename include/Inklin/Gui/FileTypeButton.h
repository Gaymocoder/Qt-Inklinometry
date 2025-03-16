#ifndef __INKLIN_FILE_TYPE_BUTTON_H__
#define __INKLIN_FILE_TYPE_BUTTON_H__

#include "Inklin/SimpleTypes.h"

#include <QPushButton>

namespace Inklin
{
    namespace Gui
    {
        class FileTypeButton : public QPushButton
        {
            Q_OBJECT;
            
            private:
                Inklin::SourceDataType dataType;
                
            public:
                explicit FileTypeButton(SourceDataType fileType, QWidget* parent = nullptr);
                
                Inklin::SourceDataType getDataType() const;
        };
    }
}

#endif
