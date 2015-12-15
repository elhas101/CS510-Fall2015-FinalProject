/* structure called complex with two components, x and y
We will interpret the component x as the real part, 
and y as the imaginary part
*/
struct complex {
	long double x; // real 
	long double y; // imaginary
};

typedef struct complex COMPLEX;

COMPLEX mult2(COMPLEX a, COMPLEX b);
COMPLEX square(COMPLEX a);
COMPLEX add2(COMPLEX a, COMPLEX b);
COMPLEX juliamap(COMPLEX a, COMPLEX b);
void complex_print(const COMPLEX z);
void test(void);


