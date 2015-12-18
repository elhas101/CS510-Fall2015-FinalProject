#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "cplane.hpp"

// using boost algorithm and std
using namespace std;
using namespace boost::numeric::ublas;


// Constructor that initializes cplane in a sensible way 
MAT CPLANE::set( VALUE xmin, VALUE xmax, VALUE ymin, VALUE ymax, INDEX xpoints, INDEX ypoints) {
  
  MAT mat(xpoints, ypoints);
  INDEX rows, cols;
  VALUE x, y;
  // set step values

  const VALUE col_step = (xmax - xmin)/(xpoints);
  const VALUE row_step = (ymax - ymin)/(ypoints);

  // loop to set values for the matrix
  for(rows=0; rows<ypoints; rows++) {
    for(cols=0; cols<xpoints; cols++) {

      x = xmin + cols*col_step;
      y = ymin + rows*row_step;
      mat(rows,cols) = x + y*1i;

     }
  }
  return(mat);
};

COMPLEX CPLANE::get( MAT c, INDEX row, INDEX col) {
  
  COMPLEX n;
  n = c(row,col);
  
  return n;
};

