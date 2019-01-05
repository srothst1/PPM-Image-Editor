#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

#include "ppmio.h"

using namespace std;

/* helper function that returne width or height of ppm image
   filename: name of ppm file
   tetWidth: if true, return width, otherwise return height
*/
int ppm_helper(string filename, bool retWidth){
  ifstream file;
  file.exceptions(iostream::failbit | iostream::badbit);
  file.open(filename);

  string s;
  file >> s;
  if (s != "P3") {
    throw runtime_error("Input file is not a P3 PPM file.");
  }

  int dim;
  file >> dim;
  if(retWidth){
    file.close();
    return dim;
  }
  file >> dim;
  file.close();
  return dim;
}

int ppm_width(string filename) {
  return ppm_helper(filename, true);
}

int ppm_height(string filename) {
  return ppm_helper(filename, false);
}

void read_ppm(string filename, int* ppm, int ppmSize) {
  ifstream file;
  file.exceptions(iostream::failbit | iostream::badbit);
  file.open(filename);

  string s;
  file >> s;
  if (s != "P3") {
    throw runtime_error("Input file is not a P3 PPM file.");
  }
  int width;
  file >> width;
  int height;
  file >> height;

  if(3*width*height > ppmSize) {
    throw runtime_error("Input file is too large.");
  }

  file >> s;
  if (s != "255") {
    throw runtime_error("Input file does not contain 8-bit pixel samples.");
  }

  for (int i=0;i<width*height*3;i++) {
    file >> ppm[i];
  }
  for(int i=width*height*3; i<ppmSize; i++) {
    ppm[i] = -1;		// initialize to invalid pixel.
  }
  file.close();

}

void write_ppm(string filename, int width, int height, int* ppm) {
  ofstream file;
  file.exceptions(iostream::failbit | iostream::badbit);
  file.open(filename);

  file << "P3" << endl;
  file << width << " " << height << endl;
  file << "255" << endl;
  for (int i=0;i<width*height*3;i++) {
    file << ppm[i] << endl;
  }

  file.close();
}
