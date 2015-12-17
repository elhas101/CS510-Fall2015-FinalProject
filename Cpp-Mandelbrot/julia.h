// Include library
#include <complex>
#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>


// define types
typedef long int INDEX;
typedef long double VALUE;

typedef std::complex<long double> COMPLEX;

// juliamap declaration for cpp file
COMPLEX juliamap(COMPLEX n, COMPLEX m);
