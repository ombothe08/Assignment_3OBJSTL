#include <iostream>
#include <map>
#include <vector>
#include "..\headers\Triangulation.h"

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
vector<Point3D> &Triangulation::uniqueNormals()
{
    return mUniqueNormals;
}