#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/Triangle.h"
#include "../headers/Triangulation.h"
#include "../headers/Point3D.h"
#include "../headers/ObjReader.h"
#include "../headers/ObjtoStl.h"

using namespace std;

void ObjtoStl::writer(Triangulation &triangulation)
{
    ofstream outFile("stlfile//cube.stl");

    if (!outFile.is_open())
    {
        cout << "Error while opening the file for writing." << endl;
    }

    vector<Point3D> &points = triangulation.uniquePoints();
    vector<Triangle> &triangles = triangulation.triangles();
    vector<Point3D> &Normal = triangulation.uniqueNormals();

    // Writing Obj to Stl in STL file Format
    outFile << "solid exported " << endl;

    for (const Triangle &triangle : triangles)
    {

        outFile << " face Normal " << Normal[triangle.triangleNormal()].x() << " " << Normal[triangle.triangleNormal()].y() << " " << Normal[triangle.triangleNormal()].z() << endl;
        outFile << "      "
                << "outer loop" << endl;
        outFile << "         "
                << "vertex " << points[triangle.v1()].x() << " " << points[triangle.v1()].y() << " " << points[triangle.v1()].z() << endl;
        outFile << "         "
                << "vertex " << points[triangle.v2()].x() << " " << points[triangle.v2()].y() << " " << points[triangle.v2()].z() << endl;
        outFile << "         "
                << "vertex " << points[triangle.v3()].x() << " " << points[triangle.v3()].y() << " " << points[triangle.v3()].z() << endl;
        outFile << "      "
                << "endloop" << endl;
        outFile << "     "
                << "endfacet" << endl;
    }
    outFile << "End " << endl;
    outFile.close();
}