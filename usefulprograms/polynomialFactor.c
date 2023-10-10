#include <stdio.h>
#include <math.h>

// Factor polynomial given standard form
// Input: x^4 - 7x^3 - 12x^2 + 68x + 112
// Output: (x - 4)(x + 2)^2(x - 7)

// Return factors of a number
// Input: 68
// Output: {1, -1, 68, -68, 2, -2, 34, -34, 4, -4, 17, -17}
int factors(int num, int *f) {
	// Initialize number of factors
	int numOfFactors = 0;
	// Loop through all possible smaller factors
	for (int x = 1; x <= sqrt(num); x++) {
		// Add to list if number divides evenly
		if (num % x == 0) {
			// Add positive and negative of both smaller
			// and larger factor
			*(f++) = x;
			*(f++) = -x;
			numOfFactors += 2;
			if (x != num / x) {
				*(f++) = num / x;
				*(f++) = -num / x;
				numOfFactors += 2;
			}
		}
	}
	return numOfFactors;
}

double evalPolynomial(int *polynomial, double x, int numOfTerms) {
	int eval = 0;
	for (int i = numOfTerms; i > 0; i--) {
		eval += polynomial[numOfTerms-i]*pow(x, i-1);
	}
	return eval;
}


// Get coefficients given polynomial string
// Input: "x^4 - 7x^3 - 12x^2 + 68x + 112"
// Output: {1, -7, -12, 68, 112}

//int *coefficients(char *polyStr) {
//}

// Find factor of polynomial
// Input: {1, -7, -12, 68, 112}
// Output: -2
int rationalRoots(int *polynomial, int numOfTerms) {
	int constantFactors[200];
	int numOfConstFactors = factors(polynomial[numOfTerms], constantFactors);
	int leadCoeffFactors[200];
	int numOfLeadFactors = factors(polynomial[0], leadCoeffFactors);
	for (int x = 0; x < numOfConstFactors; x++) {
		for (int y = 0; y < numOfLeadFactors; y++) {
			if (evalPolynomial(polynomial, *(constantFactors + x) / *(leadCoeffFactors + y), 5) == 0) {
				return *(constantFactors + x) / *(leadCoeffFactors + y);
			}
		}
	}
	return polynomial[numOfTerms];
}

int main() {
	int nums[] = {1, -7, -12, 68, 112};
	int degree = 4;
	char factoredForm[70];
	printf("%d\n", rationalRoots(nums, degree));
}
