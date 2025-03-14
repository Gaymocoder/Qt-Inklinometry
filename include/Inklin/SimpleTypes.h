#ifndef __INKLIN_SIMPLE_TYPES_H__
#define __INKLIN_SIMPLE_TYPES_H__

#include <iostream>

namespace Inklin
{
    enum SourceDataType
    {
        ABSOLUTE = 0,
        DELTA    = 1,
        AZIMUTH  = 2,
        NONE     = 3,
    };
        
    namespace Core
    {
        struct DataSet
        {
            double Value1;
            double Value2;
            double Value3;
        };
        
        enum class ConfigKeys
        {
            STARTPOS,
        };
        
        std::istream& operator>>(std::istream& in, DataSet& ds);
        std::ostream& operator<<(std::ostream& out, const DataSet& ds);
        
        bool operator==(const DataSet& value1, const DataSet& value2);
    }
}

#endif
