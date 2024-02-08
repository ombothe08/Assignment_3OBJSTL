#pragma once
#include "Point3D.h"

// Class representing a triangle with vertex indices
class Triangle
{
public:
    Triangle();
    Triangle(int inV1, int inV2, int inV3);
    ~Triangle();

    const int v1() const;
    const int v2() const;
    const int v3() const;

    void setV1(const int v1);
    void setV2(const int v2);
    void setV3(const int v3);

private:
    int mV1;
    int mV2;
    int mV3;
};
