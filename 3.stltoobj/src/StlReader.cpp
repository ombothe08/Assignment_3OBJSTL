#include <cmath>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
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

void StlReader ::readFile1(Triangulation &triangualtion)
{
    std::ifstream readFromFile("stlfile\\cube.stl");
    map<Point3D, int> mp;
    map<Point3D, int> mappedNormals;
    string line;

    if (readFromFile.is_open())
    {
        int count = 1;
        int normalIndex = 1;
        int v1;
        int v2;
        int v3;
        int Normal;
        while (getline(readFromFile, line))
        {
            if (line.find("facet normal") != std::string::npos)
            {
                double x;
                double y;
                double z;
                istringstream iss(line);
                string token1;
                string token2;
                iss >> token1 >> token2 >> x >> y >> z;
                Point3D point(x, y, z);

                // Check if the point is already mapped
                auto iterator = mappedNormals.find(point);

                // If not mapped, add to uniquePoints and update the mapping
                if (iterator == mappedNormals.end())
                {
                    mappedNormals[point] = triangualtion.uniqueNormals().size();
                    triangualtion.uniqueNormals().push_back(point);
                }
                normalIndex = mappedNormals[point];
            }

            if (line.find("vertex") != string::npos)
            {
                istringstream vertexStream(line);
                string token;
                double x, y, z;

                vertexStream >> token >> x >> y >> z;
                // Stored Coordinates x,y,z into object of Point3D
                Point3D point(x, y, z);

                auto it = mp.find(point);

                if (it == mp.end())
                {
                    triangualtion.uniquePoints().push_back(point);

                    mp[point] = triangualtion.uniquePoints().size();
                }
                if (count == 1)
                {
                    v1 = mp[point];
                    count++;
                }
                else if (count == 2)
                {
                    v2 = mp[point];
                    count++;
                }
                else if (count == 3)
                {
                    v3 = mp[point];
                    count++;
                }
            }
            if (count == 4)
            {
                Triangle T(v1, v2, v3, normalIndex);
                triangualtion.triangles().push_back(T);
                count = 1;
            }
        }
        readFromFile.close();
    }
}
