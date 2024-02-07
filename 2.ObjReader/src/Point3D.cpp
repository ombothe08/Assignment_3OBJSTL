#include "../headers/Point3D.h"

Point3D::Point3D() : mX(0), mY(0), mZ(0) {}

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

void Point3D ::setX(double x)
{
    mX = x;
}
void Point3D ::setY(double y)
{
    mY = y;
}
void Point3D ::setZ(double z)
{
    mZ = z;
}

bool Point3D::operator<(const Point3D &other) const
{
    // Compare x-coordinates
    if (mX < other.mX)
        return true;
    if (mX > other.mX)
        return false;

    // If x-coordinates are equal, compare y-coordinates
    if (mY < other.mY)
        return true;
    if (mY > other.mY)
        return false;

    // If both x and y-coordinates are equal, compare z-coordinates
    return mZ < other.mZ;
}
