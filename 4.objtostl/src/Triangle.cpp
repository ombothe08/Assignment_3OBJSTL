#include "../headers/Triangle.h"

Triangle::Triangle() : mV1(), mV2(), mV3() {}
Triangle::Triangle(int inV1, int inV2, int inV3, int inNormal)
{
    mV1 = inV1;
    mV2 = inV2;
    mV3 = inV3;
    mNormal = inNormal;
}

const int Triangle::v1() const
{
    return mV1;
}

const int Triangle::v2() const
{
    return mV2;
}

const int Triangle::v3() const
{
    return mV3;
}

const int Triangle::triangleNormal() const
{
    return mNormal;
}

void Triangle::setV1(const int v1)
{
    mV1 = v1;
}

void Triangle::setV2(const int v2)
{
    mV2 = v2;
}

void Triangle::setV3(const int v3)
{
    mV3 = v3;
}