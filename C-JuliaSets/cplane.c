#include <stdio.h>
#include <stdlib.h>
#include "complex.h"
#include "cplane.h"

// Constructor that initializes cplane in a sensible way 
// setting the bounds and grids of the cplane
CPLANE new_cplane(const VALUE xmin, const VALUE xmax, const VALUE ymin, const VALUE ymax, const INDEX xpoints, const INDEX ypoints) {
  CPLANE c;

  c.mat = (COMPLEX *)calloc(xpoints * ypoints, sizeof(COMPLEX));
  if (c.mat == NULL) {
    fprintf(stderr, "Failed to allocate new_cplane\n");
  }

  INDEX rows, cols;
  // switching v to COMPLEX
  COMPLEX v;

  c.xmin = xmin;
  c.xmax = xmax;
  c.ymin = ymin;
  c.ymax = ymax;
  c.xpoints = xpoints;
  c.ypoints = ypoints;

  // set step values

  VALUE col_step = (xmax - xmin)/(xpoints);
  VALUE row_step = (ymax - ymin)/(ypoints);

  // loop to set values for the matrix
  for(rows=0; rows<ypoints; rows++) {
    for(cols=0; cols<xpoints; cols++) {

      v.x = xmin + cols*col_step;
      v.y = ymin + rows*row_step;
      set(&c,rows,cols,v);

     }
  }

  return c;
}

void delete_cplane(CPLANE c) {
  // Free memory that was allocated, to avoid memory leak
  free(c.mat);
}

void set(CPLANE *c, const INDEX row, const INDEX col, const COMPLEX v) {
  // Find the pointer to the block of memory containing 
  // the matrix mat, then jump forward row number of rows
  // and col number of columns.  Inside that block of memory
  // insert the value v.
  if (row < 0 || col < 0 || row >= c->ypoints || col >= c->xpoints) {
    fprintf(stderr, "ERROR: indexing matrix outside bounds");
    return;
  }
  *(c->mat + (c->xpoints * row) + col) = v;
}

COMPLEX get(const CPLANE *c, const INDEX row, const INDEX col) {
  // Find the pointer to the block of memory containing 
  // the matrix mat, then jump forward row number of rows
  // and col number of columns.  Return the value inside.
  COMPLEX n;
  n.x = 1;
  n.y = 1;
  if (row < 0 || col < 0 || row >= c->ypoints || col >= c->xpoints) {
    fprintf(stderr, "ERROR: indexing matrix outside bounds");
    return n;
  }
  return *(c->mat + c->xpoints * row + col);
}

// Abstraction layer in case implementation of VALUE changes later
void print_value(const COMPLEX v) {
  printf("%Lf", v);
}

void print_matrix(const CPLANE *c) {
  INDEX row, col, maxr, maxc;
  maxr = c->xpoints;
  maxc = c->ypoints;

  printf("Matrix (rows: %d, cols: %d) \n", maxr, maxc);
  for(row=0; row<maxr; row++) {
    for(col=0; col<maxc; col++) {
      // print values of matrix separated by tabs
      // with each row on a separate line
      print_value(get(c, row, col));
      printf(" ");
    }
    puts("\n");
  }
  puts("");
}
