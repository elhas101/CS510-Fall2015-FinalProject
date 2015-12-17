#include <vector>
#include <iostream>
#include <string>
#include "julia.h"


/* function juliamap that takes two COMPLEX structures, z and c,
and returns a COMPLEX structure representing the juliamap: z^2 + c.
*/

COMPLEX juliamap(COMPLEX z, COMPLEX c) {
  COMPLEX jm;
  jm = (z * z) + c;
  return jm;
};
