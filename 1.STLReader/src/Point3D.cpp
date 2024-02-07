#include "../headers/Point3D.h"
using namespace Shapes3D;

Point3D::Point3D() : mX(), mY(), mZ() {}
Point3D::Point3D(double x, double y, double z) : mX(x), mY(y), mZ(z) {}
Point3D::~Point3D() {}

double Point3D::x() const
{
    return mX;
}

double Point3D::y() const
{
    return mY;
}

double Point3D::z() const
{
    return mZ;
}

// Overloaded less-than operator for comparing Point3D objects
bool Point3D::operator<(const Point3D &other) const
{
    if (mX < other.mX)
        return true;
    if (mX > other.mX)
        return false;

    if (mY < other.mY)
        return true;
    if (mY > other.mY)
        return false;

    return mZ < other.mZ;
}