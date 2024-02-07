#pragma once
#include <vector>
#include "Triangle.h"
#include "Triangulation.h"

// Class representing an OBJ file writer for triangulation
class ObjWriter
{
public:
    void writeOBJ(Triangulation &triangulation);
};
