#pragma once
#include <vector>
#include "Triangle.h"
#include "Point3D.h"

// Class representing a triangulation
class Triangulation
{
public:
    Triangulation();
    ~Triangulation();

    std::vector<Triangle> &triangles();

    std::vector<Point3D> &uniquePoints();

private:
    std::vector<Triangle> mTriangles;
    std::vector<Point3D> mUniquePoints;
};
