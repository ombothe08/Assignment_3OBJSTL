#pragma once
#include "Triangulation.h"
// Class for reading triangulation data from an STL file
class StlReader
{
    public:
        StlReader();
        ~StlReader();
   
    void readFile1(Triangulation & triangulation);
};
