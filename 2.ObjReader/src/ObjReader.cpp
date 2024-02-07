#include "../headers/ObjReader.h"     
#include "../headers/Triangulation.h" 
#include "../headers/Triangle.h"      
#include <iostream>                   
#include <fstream>                    
#include <sstream>                    
#include <unordered_map>              
#include <map>                        
#include <algorithm>              

using namespace std;  

void ObjReader::readObj(Triangulation &triangulation)
{
    vector<Point3D> points;    
    vector<Triangle> triangles; 

    ifstream inputfile("objfile\\cube.obj"); 
    string line;                    

    // Read file line by line
    while (getline(inputfile, line))
    {
        // Check if line contains vertex coordinates
        if (line.find("v") != string::npos)
        {
            double x, y, z;                   
            istringstream singleline(line);   
            string keyword;                   
            singleline >> keyword >> x >> y >> z; 
            if (keyword == "v")               
            {
                Point3D P1(x, y, z);         // Create Point3D object
                points.push_back(P1);         
            }
        }

        // Check if line contains face definitions
        if (line.find("f") != string::npos)
        {
            string x, y, z;                   
            istringstream singleLine(line);   
            string keyword;                   // String to store keyword ("f")
            singleLine >> keyword >> x >> y >> z; 
            if (keyword == "f")              
            {
                int v1, v2, v3;             
                v1 = x[0]; v1 -= 48;        
                v2 = y[0]; v2 -= 48;         
                v3 = z[0]; v3 -= 48;         
                Triangle T(v1, v2, v3);      // Create Triangle object
                triangles.push_back(T);      // Add Triangle object to vector
            }
        }
    }

    // Assign populated vectors to Triangulation object
    triangulation.triangles() = triangles;
    triangulation.uniquePoints() = points;

    inputfile.close();  
}
