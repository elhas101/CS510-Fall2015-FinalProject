// Define types as abstraction layer to protect against implementation changes
typedef unsigned long int INDEX;
typedef long double VALUE;

// Use abstract types inside matrix definition for robustness
typedef struct cplane {
  VALUE xmin;
  VALUE xmax;
  VALUE ymin;
  VALUE ymax;
  INDEX xpoints;
  INDEX ypoints;
  COMPLEX *mat;
} CPLANE;

// Constructor that initializes type in sensible way
CPLANE new_cplane(const VALUE, const VALUE, const VALUE, const VALUE, const INDEX, const INDEX);
// Destructor for allocated memory
void delete_cplane(CPLANE);
// Setter for individual elements
void set(CPLANE *, const INDEX, const INDEX, const COMPLEX);
// Getter for individual elements
COMPLEX get(const CPLANE *, const INDEX, const INDEX);
// Abstraction layer for printing values
void print_value(const COMPLEX);
// Abstraction layer for printing matrices
void print_matrix(const CPLANE *);
