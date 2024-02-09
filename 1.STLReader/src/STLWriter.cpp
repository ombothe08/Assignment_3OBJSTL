#include <iostream>
#include <fstream>
#include "../headers/STLWriter.h"
using namespace std;
using namespace Shapes3D;

STLWriter::STLWriter() {}
STLWriter::~STLWriter() {}

// Method to write triangulation data to an STL file
Triangulation STLWriter::writeSTL(std::string &filePath, Triangulation &triangulationObj)
{
    ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        cout << "Error while opening the file for writing." << endl;
    }

    // Get references to the unique points and triangles in the triangulation object
    vector<Point3D> &points = triangulationObj.uniquePoints();
    vector<Triangle> &triangles = triangulationObj.triangles();

    // Write the triangulation data to the file
    for (const Triangle &triangle : triangles)
    {
        outFile << points[triangle.indexOne()].x() << " " << points[triangle.indexTwo()].y() << " " << points[triangle.indexThree()].z() << endl;
    }
    outFile.close();
    return triangulationObj;
}
