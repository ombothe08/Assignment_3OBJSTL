#include "../headers/STLReader.h"
#include "../headers/Triangulation.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;
using namespace Shapes3D;

STLReader::STLReader() {}

STLReader::~STLReader() {}

// Method to read triangulation data from an STL file and populate a Triangulation object
Triangulation STLReader::readSTL(const std::string &filePath)
{
    Triangulation triangulationObj;

    ifstream file(filePath);

    if (!file.is_open())
    {
        cout << "Error while opening the file." << endl;
    }

    string line;
    vector<Point3D> points;
    vector<Triangle> triangles;
    map<Point3D, int> pointIndexMap;
    int count = 0;
    while (getline(file, line))
    {
        istringstream iss(line);
        string token;
        iss >> token;

        if (token == "vertex")
        {
            double x, y, z;
            iss >> x >> y >> z;

            Point3D point(x, y, z);

            // Check if the point is already in the map
            auto it = pointIndexMap.find(point);
            if (it == pointIndexMap.end())
            {
                // If not, add it to the points vector and update the point index map
                int index = points.size();
                pointIndexMap[point] = index;
                points.push_back(point);
            }
            else
            {
                count++;
            }
            int index1 = pointIndexMap[point];
            int index2 = pointIndexMap[point];
            int index3 = pointIndexMap[point];
            triangles.push_back(Triangle(index1, index2, index3));      
        }
    }
    // Assign the points and triangles to the Triangulation object
    triangulationObj.uniquePoints() = points;
    triangulationObj.triangles() = triangles;

     // Return the Triangulation object
    return triangulationObj;
}
