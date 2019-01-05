#include <string>
#include <iostream>

#include "image.h"
#include "ppmio.h"


using namespace std;

int main() {
  string infile, outfile, transform;
  cout << "Welcome to Sam's image editor!  Most of my features are standard.  simplify and mirror are bonus!" << endl;

  cout << "Enter name of input file: ";
  cin >> infile;

  cout << "Enter name of output file: ";
  cin >> outfile;

  // get width and height of input image
  int width = ppm_width(infile);
  int height = ppm_height(infile);

  // create array for ppm file
  int ppmSize = width * height * 3;
  int* ppm = new int[ppmSize];

  // read in image
  read_ppm(infile, ppm, ppmSize);

  // Now, ask user for transformation function
  cout << "Enter filter command: ";
  cin >> transform;

  // repeat until user enters valid filter
  bool valid = false; // will be changed when input is confirmed correct
  while(!valid) {
    if(transform == "noRed") {
      noRed(width, height, ppm);
      valid = true;			// filter applied; exit loop
    }
    else if(transform == "noGreen") {
      noGreen(width, height, ppm);
      valid = true;			// filter applied; exit loop
    }
    else if(transform == "noBlue") {
      noBlue(width, height, ppm);
      valid = true;			// filter applied; exit loop
    }
    else if(transform == "invert") {
      invert(width, height, ppm);
      valid = true;			// filter applied; exit loop
    }
    else if(transform == "greyscale") {
      greyscale(width, height, ppm);
      valid = true;			// filter applied; exit loop
    }
    else if(transform == "flipHorizontally") {
      flipHorizontally(width, height, ppm);
      valid = true;			// filter applied; exit loop
    }
    else if(transform == "flipVertically"){
      flipVertically(width, height, ppm);
      valid = true;
    }
    else if(transform == "mirror"){
      mirror(width, height, ppm);
      valid = true;
    }
    else if(transform == "simplify"){
      simplify(width, height, ppm);
      valid = true;
    }

    else{
      cout << "Here is the list of commands:  noRed, noGreen, noBlue, inver, \
      greyscale, flipHorizontally , flipVertically, mirror, simplify" << endl;
      cout << "The command you have entered is not valid. Please enter another command: "  << endl;
      cin >> transform;
    }
  }

  write_ppm(outfile, width, height, ppm);

  cout << "complete!"<< endl;

  delete [] ppm;

  return 0;
}
