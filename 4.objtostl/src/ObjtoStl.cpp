#include "../headers/ObjtoStl.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/Point3D.h"
using namespace std;
 
void ObjtoStl :: writer(Triangulation &triangulation)
{
    ofstream outFile("textfiles/cube.txt");
    if (!outFile.is_open()) {
        std::cerr << "Unable to open file for writing." << std::endl;
        return;
    }
    const std::vector<Point3D>& points = triangulation.uniquePoints();
    const std::vector<Triangle>& triangles = triangulation.triangles();

    // Write header for STL-like text file
    outFile << "solid converted_obj" << std::endl;

    // Write triangles as facets
    for (const Triangle& triangle : triangles) {
        outFile << "  facet normal 0 0 0" << std::endl;
        outFile << "    outer loop" << std::endl;

        // Adjust indices since OBJ format uses 1-based indexing
        const Point3D& p1 = points[triangle.v1() - 1];
        const Point3D& p2 = points[triangle.v2() - 1];
        const Point3D& p3 = points[triangle.v3() - 1];

        // Write vertices of the triangle
        outFile << "      vertex " << p1.x() << " " << p1.y() << " " << p1.z() << std::endl;
        outFile << "      vertex " << p2.x() << " " << p2.y() << " " << p2.z() << std::endl;
        outFile << "      vertex " << p3.x() << " " << p3.y() << " " << p3.z() << std::endl;
        outFile << "    endloop" << std::endl;
        outFile << "  endfacet" << std::endl;
    }

    outFile << "endsolid converted_obj" << std::endl;
    outFile.close();
   
}