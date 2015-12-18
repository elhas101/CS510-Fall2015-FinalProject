#include <stdio.h>
#include "complex.h"

/* function mult2 that takes two COMPLEX structures, a and b,
and returns a COMPLEX structure representing their product. 
[Recall if a = x1 + y1 i and b = x2 + y2 i, 
then a * b = (x1 * x2 - y1 * y2) + (x1 * y2 + x2 * y1) i ]
*/
COMPLEX mult2(COMPLEX a, COMPLEX b) {
	COMPLEX c;
	c.x = (a.x * b.x - a.y * b.y);
	c.y = (a.x * b.y + b.x * a.y);
	return c;
}; 

/* function square that takes a COMPLEX structure and returns
the square of that structure
*/
COMPLEX square(COMPLEX a) {
	COMPLEX sq;
	sq.x = a.x*a.x - a.y*a.y;
	sq.y = 2*a.x*a.y;
	return sq;
};

/*  function add2 that takes two COMPLEX structures, a and b, and
returns a COMPLEX structure representing their sum. 
[Recall if a = x1 + y1 i and b = x2 + y2 i, then a + b = 
(x1 + x2) + (y1 + y2) i ]
*/

COMPLEX add2(COMPLEX a, COMPLEX b) {
	COMPLEX add;
	add.x = a.x + b.x;
	add.y = a.y + b.y;
	return add;
};

/* function juliamap that takes two COMPLEX structures, z and c,
and returns a COMPLEX structure representing the juliamap: z^2 + c.
*/

COMPLEX juliamap(COMPLEX a, COMPLEX b) {
	COMPLEX jm;
	jm = add2(square(a), b);
	return jm;
};

/*
COMPLEX_print that takes a COMPLEX structure, z, and
prints the string "z = x + y i" where x and y are its 
real and imaginary parts.
*/

void complex_print(COMPLEX z) {
	printf("z = %1f + %1fi", z.x, z.y);
};

/*
 function test that demonstrates that the functions (mult2,
square, add2, juliamap, COMPLEX_to_str) work as desired by 
printing to the screen.
*/
/*
void test() {
	COMPLEX a, b;
	a.x = 2.0;
	a.y = 3.0;
	b.x = 4;
	b.y = 5;
	printf("Input a and b where a + ib is the first COMPLEX number.\n");
	printf("a = ");
	scanf("%f", &a.x);
	printf("b = ");
	scanf("%f", &a.y);
	printf("Input c and d where c + id is the second COMPLEX number.\n");
	printf("c = ");
	scanf("%f", &b.x);
	printf("d = ");
	scanf("%f", &b.y);
	printf ("You have entered the COMPLEX numbers :%.1f %+.1f and %.1f %+.1fi\n", a.x,a.y,b.x,b.y);
	printf ("Testing multiplication of COMPLEX numbers are :%.1f %+.1fi\n", mult2(a,b).x, mult2(a,b).y);
	printf ("Testing square of COMPLEX number is :%.1f %+.1fi\n", square(a).x, square(a).y);
	printf ("Testing addition of COMPLEX numbers are :%.1f %+.1fi\n", add2(a,b).x, add2(a,b).y);
	printf ("Testing juliamap of COMPLEX numbers are :%.1f %+.1fi\n", juliamap(a,b).x, juliamap(a,b).y);
	COMPLEX_print(a);
	COMPLEX_print(b);
}

int main(void) {

	test();
 	return 0;
}
*/