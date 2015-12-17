#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>

// define types

typedef long int INDEX;
typedef long double VALUE;


// store COMPLEX in std::complex<long double> types
typedef std::complex<long double> COMPLEX;

// Store mat in boost::numeric::ublas::matrix<std::complex<long double> > type 
typedef boost::numeric::ublas::matrix<std::complex<long double> > MAT;  

class CPLANE {
	public:
	  VALUE xmin;
	  VALUE xmax;
	  VALUE ymin;
	  VALUE ymax;
	  INDEX xpoints;
	  INDEX ypoints;
	  MAT mat;

	  // declare functions used in .cpp
	  MAT set(VALUE , VALUE , VALUE , VALUE , INDEX , INDEX );
	  COMPLEX get(MAT, INDEX, INDEX);

};

