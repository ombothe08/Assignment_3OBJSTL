#pragma once

// Class representing a 3D point in space
class Point3D
{
public:
    Point3D();  // Default constructor
    Point3D(double x, double y, double z);  // Constructor with coordinates
    ~Point3D();  // Destructor

    // Getter methods for coordinates
    double x() const;
    double y() const;
    double z() const;

    // Setter methods for coordinates
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    // Comparison operator for sorting
    bool operator<(const Point3D &other) const;

private:
    double mX;  // x-coordinate
    double mY;  // y-coordinate
    double mZ;  // z-coordinate
};
