#pragma once
#include "Point3D.h"

// Class representing a triangle with vertex indices
class Triangle
{
public:
    Triangle();  // Default constructor
    Triangle(int v1, int v2, int v3);  // Constructor with vertex indices

    // Getter methods for vertex indices
    const int v1() const;
    const int v2() const;
    const int v3() const;

    // Setter methods for vertex indices
    void setV1(const int v1);
    void setV2(const int v2);
    void setV3(const int v3);

private:
    int mV1;  // Index of vertex 1
    int mV2;  // Index of vertex 2
    int mV3;  // Index of vertex 3
};
