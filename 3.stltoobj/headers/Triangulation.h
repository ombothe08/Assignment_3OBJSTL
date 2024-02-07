#pragma once
#include <vector>
#include "Triangle.h"
using namespace std;

// Class representing a triangulation
class Triangulation
{
public:
    Triangulation();
    ~Triangulation();

    vector<Triangle> &triangles();
    vector<Point3D> &uniquePoints();
     // Method to print triangles
    void printtriangles();

private:
    vector<Triangle> mTriangles;  // Vector of triangles
    vector<Point3D> mUniquePoints; // Vector of unique points
}; 
