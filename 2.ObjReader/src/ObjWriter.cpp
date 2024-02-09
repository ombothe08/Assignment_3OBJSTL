#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/Triangle.h"
#include "../headers/Triangulation.h"
#include "../headers/Point3D.h"
#include "../headers/ObjWriter.h"
using namespace std;

void ObjWriter::writeObj(Triangulation &triangulation)
{
    std::ofstream outFile("./textfiles/Cube.txt");
    if (!outFile.is_open())
    {
        cout << "File is not opening" << endl;
    }

    vector<Point3D> &points = triangulation.uniquePoints();

    vector<Triangle> &triangles = triangulation.triangles();
    for (const Triangle &triangle : triangles)
    {
        outFile << points[triangle.v1() - 1].x() << " " << points[triangle.v1() - 1].y() << " " << points[triangle.v1() - 1].z() << endl;
        outFile << points[triangle.v2() - 1].x() << " " << points[triangle.v2() - 1].y() << " " << points[triangle.v2() - 1].z() << endl;
        outFile << points[triangle.v3() - 1].x() << " " << points[triangle.v3() - 1].y() << " " << points[triangle.v3() - 1].z() << endl;
    }
    outFile.close();
}
