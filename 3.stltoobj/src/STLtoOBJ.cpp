#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "../headers/StlToObj.h"
#include "../headers/Point3D.h"
using namespace std;

// Method to write triangulation data to an OBJ file
void StlToObj ::writer(Triangulation &triangulation)
{
    ofstream outFile("objfile//cube.obj");
    if (!outFile.is_open())
    {
        cout << "Error while opening text file." << endl;
        return;
    }

    vector<Point3D> &points = triangulation.uniquePoints();
    vector<Point3D> &normal = triangulation.uniqueNormals();
    vector<Triangle> &triangles = triangulation.triangles();

    for (int i = 0; i < points.size(); i++)
    {
        outFile << "v"
                << " " << points[i].x() << " " << points[i].y() << " " << points[i].z() << endl;
    }

    // Writing facet into Obj File from Triangles Vector
    for (int i = 0; i < normal.size(); i++)
    {
        outFile << "vn"
                << " " << normal[i].x() << " " << normal[i].y() << " " << normal[i].z() << endl;
    }

    for (const Triangle &triangle : triangles)
    {
        outFile << "f"
                << " " << triangle.v1() << "/ /" << triangle.n() + 1
                << " " << triangle.v2() << "/ /" << triangle.n() + 1
                << " " << triangle.v3() << "/ /" << triangle.n() + 1 << endl;
    }
    outFile.close();
}