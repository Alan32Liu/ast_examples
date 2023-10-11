#include "headers/math/math_functions.h"


int main() {
    // TODO: Add a new function from a different header between add and minus,
    // to force a different 'file' item in the sibling nodes between them.
    // Then check if minus defines 'file' explicitly.
	return add(1,2) + minus(1,2);
}
