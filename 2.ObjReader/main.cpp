#include <iostream>
#include "./headers/Point3D.h"
#include "./headers/Triangulation.h"
#include "./headers/Triangle.h"
#include "./headers/ObjReader.h"
#include "./headers/ObjWriter.h"
using namespace std;

int main()
{
    Triangulation triangulation; // Create a Triangulation object

    ObjReader reader; // Create an ObjReader object
    reader.readObj(triangulation); // Read OBJ file and populate triangulation data

    ObjWriter writer; // Create an ObjWriter object
    writer.writeOBJ(triangulation); // Write triangulation data to OBJ file

    return 0;
}
