#include <iostream>
#include "./headers/ObjReader.h"
#include "./headers/ObjtoStl.h"
#include "./headers/Point3D.h"
#include "./headers/Triangulation.h"
#include "./headers/Triangle.h"

using namespace std;

int main()
{
    Triangulation triangulation;
    ObjReader reader;
    reader.readObj(triangulation);
    // Instantiate ObjtoStl object and write triangulation data to STL file
    ObjtoStl obj;
    obj.writer(triangulation);
    return 0;
}