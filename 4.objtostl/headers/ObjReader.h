#pragma once
#include "Triangulation.h"

class ObjReader
{
public:
    ObjReader();
    ~ObjReader();
    void readObj(Triangulation &triangulation);
};