#include "..\headers\Triangulation.h"
#include<map>
#include<vector>
#include<iostream>
using namespace std;

Triangulation::Triangulation()
{

}
Triangulation::~Triangulation()
{
    
}

vector<Triangle> & Triangulation::triangles()
{
    return mTriangles;
}

vector<Point3D> & Triangulation::uniquePoints()
{
    return mUniquePoints;
}