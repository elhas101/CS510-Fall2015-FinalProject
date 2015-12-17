#include <iostream>
#include "cplane.hpp"
#include "julia.h"

using namespace std;
// main function where the juliaset program is run 
int main(int argc, char **argv) {

  
  if (argc != 7) // check exactly 6 (7-1) arguments were not passed
    {
      cout << "Expecting 6 parameters, you entered : " << argc -1 <<endl;
      return(-1);
    } 

  // Parameters initialization
  CPLANE cp;

  int MAXITER=256;
  VALUE xmin = atoi (argv[1]);
  VALUE xmax = atoi (argv[2]);
  VALUE ymin = atoi (argv[3]);
  VALUE ymax = atoi (argv[4]);
  INDEX xpoints = atoi (argv[5]);
  INDEX ypoints = atoi (argv[6]);

  MAT mat;
  COMPLEX c, z;
  INDEX row, col;
  
  
  // generate a COMPLEX plane
  mat = cp.set(xmin, xmax, ymin, ymax, xpoints, ypoints);
  
  //  iterate over a CPLANE that is created with the command line arguments
  for(row=0; row<ypoints; row++) {
    for(col=0; col<xpoints; col++) {
      c = mat(row, col);
      /* iterate the function juliamap(z,c) until the COMPLEX
      result has a magnitude larger than 2 or the number of 
      iterations exceeds MAXITER=256
      */
      int iter = 0;
      while (1) {
        z = juliamap(z, c);
        iter++;
        if (abs(z) > 2) {
          cout << "ABS(z) > 2. " << iter << endl;
          break;
        };
        if (iter >= MAXITER) {
          cout << "Exceeded MAXITER. " << iter << " " << 0 << endl;
          break;
        };
      };
    };
  };

  return 0;
}
