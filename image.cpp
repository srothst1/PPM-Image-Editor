#include "image.h"

#include <iostream>
using namespace std;

// Note: see image.h for documentation on functions.

void noRed(int width, int height, int* ppm) {
    // TODO: this image transformation
    int i;
    int total = width*height*3;
    for (i = 0 ; i < total; i = i + 3){
      ppm[i] = 0;
    }
}



/* Remember that the two flips are significantly harder than the
   other transofmations. We recommend that you work out the math
   on paper before attempting to write the code.
*/

void noGreen(int width, int height, int* ppm){
  int i;
  int total = width*height*3;
  for (i = 1 ; i < total; i = i + 3){
    ppm[i] = 0;
  }
}

void noBlue(int width, int height, int* ppm){
  int i;
  int total = width*height*3;
  for (i = 2 ; i < total; i = i + 3){
    ppm[i] = 0;
  }
}

void invert(int width, int height, int* ppm){
  int i;
  int total = width*height*3;
  for (i = 0 ; i < total; i++){
    int t = ppm[i];
    int pixel = 255 - t;
    ppm[i] = pixel;
  }
}

void greyscale(int width, int height, int* ppm){
  int i;
  int total = width*height*3;
  for (i = 0 ; i < total; i = i + 3){
    int average = (ppm[i] + ppm[i+1] + ppm[i+2]) / 3;
    ppm[i] = average;
    ppm[i+1] = average;
    ppm[i+2] = average;
  }
}

int getOffset(int row, int col, int  width){
  int offset = (row * width) + col;
return offset;
}

void flipHorizontally(int width, int height, int* ppm){
  int rgb = 3;
  int width_total = rgb*width;
  int total_length = height*width_total;

  for (int x = 0 ; x < total_length ; x = x + width_total){
    for (int j = 0 ; j < width_total/2 ; j = j +3){
      for (int z = 0 ; z < 3 ; z++){
        int sol1 = ppm[x+j+z];
        int sol2 = ppm[(width_total - 1) + x - j - (2-z)];
        ppm[x+j+z] = sol2;
        ppm[(width_total - 1) + x - j - (2-z)] = sol1;
      }}}}

void flipVertically(int width, int height, int* ppm){
  int rgb = 3;
  int width_total = width*rgb;
  int total_length = width_total*height;

  int*  ppm_copy;
  ppm_copy = new int [total_length];
  ppm_copy = ppm;

  for (int x = 0 ; x < (total_length/2) ; x = x + width_total){
    for (int y = 0 ; y < width_total ; y++){
      int a = ppm_copy[y + total_length - x];
      int a2 = ppm_copy[y + x];
      ppm[x+y] = a;
      ppm[total_length - x + y] = a2;
    }}}

void mirror(int width, int height, int* ppm){
  int rgb = 3;
  int width_total = width*rgb;
  int total_length = width_total*height;

  int*  ppm_copy;
  ppm_copy = new int [total_length];
  ppm_copy = ppm;

  for (int x = 0 ; x < (total_length/2) ; x = x + width_total){
    for (int y = 0 ; y < width_total ; y++){
      int a = ppm_copy[y + total_length - x];
      int a2 = ppm_copy[y + x]; // + x
      ppm[x+y] = a;
      ppm[y+width_total] = a;
    }}}

void simplify(int width, int height, int* ppm){
  int i;
  int total = width*height*3;
  for (i = 1 ; i < total; i++){
    int var = int(ppm[i]/10)*10;
    ppm[i] = var;
  }
}
