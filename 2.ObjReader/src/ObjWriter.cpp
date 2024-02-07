#include "../headers/Triangle.h"
#include "../headers/Triangulation.h"
#include "../headers/Point3D.h"
#include "../headers/ObjWriter.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void ObjWriter::writeOBJ(Triangulation &triangulation)
{
    std::ofstream outFile("./textfiles/Cube.txt"); // Open output file stream for writing to "Cube.txt"

    if (!outFile.is_open()) // Check if file is successfully opened
    {
        cout << "File is not opening" << endl; // Output error message if file opening fails
    }

    vector<Point3D> &points = triangulation.uniquePoints(); // Get reference to vector of unique points

    vector<Triangle> &triangles = triangulation.triangles(); // Get reference to vector of triangles
    for (const Triangle &triangle : triangles) // Iterate over each triangle
    {
        // Write vertex coordinates of triangle to file
        outFile << points[triangle.v1() - 1].x() << " " << points[triangle.v1() - 1].y() << " " << points[triangle.v1() - 1].z() << endl;
        outFile << points[triangle.v2() - 1].x() << " " << points[triangle.v2() - 1].y() << " " << points[triangle.v2() - 1].z() << endl;
        outFile << points[triangle.v3() - 1].x() << " " << points[triangle.v3() - 1].y() << " " << points[triangle.v3() - 1].z() << endl;
    }
    outFile.close(); // Close output file stream
}
