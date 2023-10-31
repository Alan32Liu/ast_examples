#include <stddef.h>
#include "headers/math/math_functions.c"
#include "headers/math/test_math_functions.c"
#include "headers/math/rand_functions.h"

extern int rand(int a, int b);

int main() {
    // TODO: Add a new function from a different header between add and minus,
    // to force a different 'file' item in the sibling nodes between them.
    // Then check if minus defines 'file' explicitly.
    FractionType* f = NULL;
    set_fraction(f);
    //validate_fraction(*f);
	return add(1,2) + minus(2,1);
}
