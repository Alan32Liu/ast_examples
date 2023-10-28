#include "math_functions.h"

typedef struct Fraction {
    int numerator;
    int denominator;
} Fraction;

int add(int a, int b) {
    // TODO: Use a new function from a different header to force a different
    // 'file' item in the child node of `add`.
    // Then check if minus defines 'file' explicitly.
    return a + b;
}

int minus(int a, int b) {
    return a - b;
}

void set_fraction(FractionType * fraction) {
    fraction->numerator = 1;
    fraction->denominator = 2;
}

int validate_fraction(FractionType fraction) {
    // Fraction demoninator cannot be 0.
    return fraction.denominator;
}
