#include <iostream>
#include "./headers/Triangulation.h"
#include "./headers/Triangle.h"
#include "./headers/STLReader.h"
#include "./headers/STLWriter.h"

using namespace Shapes3D;
// Define a typedef for a vector of Triangle objects
typedef vector<Triangle> Triangles;

int main()
{
    std::string inputFilePath = "stlFiles/cube.stl";
    std::string outputFilePath = "textFiles/Cube.txt";  

    Shapes3D::STLReader stlReader;
    // Read triangulation data from the input STL file
    Triangulation triangulation = stlReader.readSTL(inputFilePath);

    Shapes3D::STLWriter stlWriter;
    // Write triangulation data to the output text file
    stlWriter.writeSTL(outputFilePath, triangulation);

    return 0;
}
