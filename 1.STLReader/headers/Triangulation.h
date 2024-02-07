#pragma once
#include "Triangle.h"
#include <vector>
using namespace std;

namespace Shapes3D
{
    // Class representing a triangulation consisting of unique points and triangles
    class Triangulation
    {
    public:
        Triangulation();
        ~Triangulation();

        vector<Point3D> &uniquePoints();
        vector<Triangle> &triangles();

    private:
        vector<Point3D> mUniquePoints;  // Vector storing unique points
        vector<Triangle> mTriangles;    //// Vector storing triangles
    };
}
