#include "math_functions.h"
#include <string.h>
#include <stdio.h>

typedef struct Fraction {
    int numerator;
    int denominator;
} Fraction;

enum Math_Result {
    MATH_SUCCESS,
    MATH_ERROR_DIVISION_BY_ZERO,
    MATH_ERROR_UNKNOWN_OPERATION
};


int negate(int a) {
    // No definition in math_functions.h
    return a * -1;
}

int add(int a, int b) {
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

static int upgrade(int a) {
    return a * a;
}

int abs(int a) {
    if(a<0) {
        return a * -1;
    }
    return a;
}

enum Math_Result mathOperation(const char operation, double operand1, double operand2, double *result) {
    if (operation == '+') {
        *result = operand1 + operand2;
        return MATH_SUCCESS;
    } else if (operation == '-') {
        *result = operand1 - operand2;
        return MATH_SUCCESS;
    } else if (operation == '*') {
        *result = operand1 * operand2;
        return MATH_SUCCESS;
    } else if (operation == '/') {
        if (operand2 == 0.0) {
            return MATH_ERROR_DIVISION_BY_ZERO;
        }
        *result = operand1 / operand2;
        return MATH_SUCCESS;
    } else {
        return MATH_ERROR_UNKNOWN_OPERATION;
    }
}
