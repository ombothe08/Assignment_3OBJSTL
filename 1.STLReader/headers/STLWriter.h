#pragma once
#include <string>
#include "../headers/Triangulation.h"
namespace Shapes3D
{
    class STLWriter
    {
    public:
        STLWriter();
        ~STLWriter();

        // Method to write triangulation data to an STL file
        Triangulation writeSTL(std::string &filePath, Triangulation &triangulationObj);
    };
}
