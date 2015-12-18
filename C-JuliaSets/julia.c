#include <stdio.h>
#include <stdlib.h>
#include "complex.h"
#include "cplane.h"


// main function where the juliaset program is run 
int main(int argc, char **argv) {

  
  if (argc != 9) // exactly 8 (9-1) arguments were not passed
    {
      printf ( "Expecting 8 parameters, you entered :%d \n", argc -1);
      return(-1);
    } 

  // Parameters initialization
  CPLANE cp;
  COMPLEX c, z, v, tmp;
  int MAXITER=256;
  char *num;
  VALUE xmin = atoi (argv[1]);
  VALUE xmax = atoi (argv[2]);
  VALUE ymin = atoi (argv[3]);
  VALUE ymax = atoi (argv[4]);
  INDEX xpoints = atoi (argv[5]);
  INDEX ypoints = atoi (argv[6]);
  VALUE creal = atoi (argv[7]);
  VALUE cimag = atoi (argv[8]);
  INDEX row, col;
  c.x = creal;
  c.y = cimag;
  
  // generate a COMPLEX plane
  cp = new_cplane(xmin, xmax, ymin, ymax, xpoints, ypoints);
  
  //  iterate over a CPLANE that is created with the command line arguments
  for(row=0; row<ypoints; row++) {
    for(col=0; col<xpoints; col++) {
      v = get(&cp, row, col);
      z.x = v.x;
      z.y = v.y;
      /* iterate the function juliamap(z,c) until the COMPLEX
      result has a magnitude larger than 2 or the number of 
      iterations exceeds MAXITER=256
      */
      int iter = 0;
      while (1) {
        tmp = juliamap(z, c);
        iter++;
        if (abs(z.x+z.y) > 2) {
          //printf("ABS(z) > 2. %d \n", iter);
          break;
        };
        if (iter >= MAXITER) {
          //printf("Exceeded MAXITER. %d, %d \n", iter, 0);
          break;
        };
      };
    };
  };

  // Destruct matrix when done
  delete_cplane(cp);

  return 0;
}
