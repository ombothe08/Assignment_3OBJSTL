#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include "../headers/Point3D.h"
#include "../headers/StlReader.h"
#include "../headers/Triangle.h"
#include "../headers/Triangulation.h"
using namespace std;

StlReader ::StlReader()
{
}
StlReader ::~StlReader()
{
}
// Method to read triangulation data from an STL file and populate a Triangulation object
void StlReader ::readFile1(Triangulation &triangualtion)
{
    std::ifstream readFromFile("stlfile\\cube.stl");
    vector<Triangle> vertexData;
    vector<Point3D> points;
    vector<Point3D>different;
    map<Point3D,int>mp;
    string line;
    vector<Triangle>tri;

    if (readFromFile.is_open() )
    {
        int count=1;
        int v1;
        int v2;
        int v3;
        while (getline(readFromFile, line))
        {
            // Check if the line contains vertex data
            if (line.find("vertex") != std::string::npos)
            {
                istringstream iss(line);
                string keyword;
                double x, y, z; 
                
                iss >> keyword >> x >> y >> z;
               
                Point3D point(x, y, z);
                auto it =mp.find(point);

                // If the point is not found in the map, add it to the list of unique points
                if(it == mp.end())
                {
                    different.push_back(point);
                    
                    mp[point] = different.size();
                }
                // Determine the vertex indices based on the count
                if (count ==1)
                {
                    v1=mp[point];
                    count++;
                }
                else if(count ==2)
                {
                    v2=mp[point];
                    count++;
                }
                else if (count ==3)
                {
                    
                    v3=mp[point];
                    count++;
                }

                points.push_back(point);
                if(count==4)
                {   

                    Triangle T(v1,v2,v3);
                    tri.push_back(T);
                    count=1;
                }  
            }
        }
        cout<<"uniquepints size - "<< different .size ()<<endl;
        cout<<"points size - "<<points.size()<<endl;
        cout<<tri.size()<<endl;
        triangualtion.triangles() = tri;
        triangualtion.uniquePoints() = different;
        readFromFile.close();
    }
    else
    {
        std::cerr << "Error while opening files" << std::endl;
    }
}
