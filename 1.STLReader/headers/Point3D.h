#pragma once
namespace Shapes3D
{
    // Class representing a 3D point in space
    class Point3D
    {
    public:
        Point3D();
        Point3D(double x, double y, double z);
        ~Point3D();

        double x() const;
        double y() const;
        double z() const;
        bool operator<(const Point3D &other) const;

    private:
        double mX;
        double mY;
        double mZ;
    };
}
