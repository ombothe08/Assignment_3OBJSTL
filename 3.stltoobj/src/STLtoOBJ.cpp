#include "../headers/StlToObj.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/Point3D.h"
using namespace std;

// Method to write triangulation data to an OBJ file
void StlToObj :: writer(Triangulation &triangulation)
{  
    ofstream outFile("objfile//cube.obj");
    if (!outFile.is_open())
    {
        cout << "Error while opening text file." << endl;
        return;
    }
    // Write the vertices to the OBJ file
    vector<Point3D> &points = triangulation.uniquePoints();
    for (size_t i = 0; i < points.size(); i++)
    {
        outFile<<"v"<<" "<<points[i].x()<<" " << points[i].y() << " " << points[i].z() << endl;
    }
    // Write the faces to the OBJ file
    vector<Triangle> &triangles = triangulation.triangles();
    cout<<triangulation.triangles().size();
    int countVertex=1;
    for (const Triangle &triangle : triangles)
    {  
        outFile << "f" << " "<< triangle.v1()<<"/_/_"<<" "<<triangle.v2()<<"/_/_"<<" "<<triangle.v3()<<"/_/_"<<endl;
    }
    outFile.close();
}