#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <map>
#include "../headers/ObjReader.h"
#include "../headers/Triangulation.h"
#include "../headers/Triangle.h"
using namespace std;

void ObjReader::readObj(Triangulation &triangulation)
{
    ifstream inputfile("objfile\\cube.obj");
    string line;

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
                Point3D P1(x, y, z); // Create Point3D object
                triangulation.uniquePoints().push_back(P1);
            }
        }

        if (line.find("f") != std::string::npos)
        {
            std::istringstream singleLine(line);
            std::string keyword;
            singleLine >> keyword;

            if (keyword == "f")
            {
                std::vector<int> vertices;
                std::string token;
                while (singleLine >> token)
                {
                    // Split the token by '/'
                    std::istringstream tokenStream(token);
                    std::string subtoken;
                    while (getline(tokenStream, subtoken, '/'))
                    {
                        // Convert substring to integer and push it to vertices
                        vertices.push_back(std::stoi(subtoken));
                    }
                }

                // Extract first values
                int v1 = vertices[0];
                int v2 = vertices[3];
                int v3 = vertices[6];

                Triangle T(v1, v2, v3);
                triangulation.triangles().push_back(T);
            }
        }
    }
    inputfile.close();
}
