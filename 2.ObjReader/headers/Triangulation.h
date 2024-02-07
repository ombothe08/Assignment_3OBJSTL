#pragma once
#include <vector>
#include "Triangle.h"
#include "Point3D.h"

// Class representing a triangulation
class Triangulation
{
public:
    Triangulation();  // Default constructor
    ~Triangulation();  // Destructor

    // Getter method for triangles
    std::vector<Triangle> &triangles();

    // Getter method for unique points
    std::vector<Point3D> &uniquePoints();

    // Method to print triangles
    void printTriangles();

private:
    std::vector<Triangle> mTriangles;  // Vector of triangles
    std::vector<Point3D> mUniquePoints;  // Vector of unique points
};
