#include <iostream>
#include <map>
#include <vector>
#include "..\headers\Triangulation.h"
using namespace std;

Triangulation::Triangulation()
{
}
Triangulation::~Triangulation()
{
}

vector<Triangle> &Triangulation::triangles()
{
    return mTriangles;
}

vector<Point3D> &Triangulation::uniquePoints()
{
    return mUniquePoints;
}