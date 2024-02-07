#pragma once
#include "Triangulation.h"
// Class for reading triangulation data from an OBJ file
class ObjReader
{
public:
    void readObj(Triangulation &triangulation);
};