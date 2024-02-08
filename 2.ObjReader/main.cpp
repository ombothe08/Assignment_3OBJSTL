#include <iostream>
#include "./headers/ObjReader.h"
#include "./headers/ObjWriter.h"
#include "./headers/Point3D.h"
#include "./headers/Triangulation.h"
#include "./headers/Triangle.h"
using namespace std;

int main()
{
    Triangulation triangulation;
    ObjReader reader;
    reader.readObj(triangulation); // Read OBJ file and populate triangulation data
    ObjWriter writer;
    writer.writeObj(triangulation); // Write triangulation data to OBJ file
    return 0;
}
