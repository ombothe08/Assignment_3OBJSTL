#include <fstream>
#include <iostream>
#include <cmath>
#include "./headers/StlReader.h"
#include "./headers/STLtoOBj.h"
using namespace std;

int main()
{
  StlReader stlreader;
  Triangulation triangualtion;
  // Read triangulation data from STL file
  stlreader.readFile1(triangualtion );
  StlToObj obj;
  obj.writer(triangualtion);
  return 0;
}
