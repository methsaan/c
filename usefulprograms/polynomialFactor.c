#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int simplified(int num, int den) {
	int numFactors[100];
	int denFactors[100];
	int numOfNumFactors = factors(num, numFactors);
	int numOfDenFactors = factors(den, denFactors);
	for (int x = 0; x < numOfNumFactors; x++) {
		for (int y = 0; y < numOfDenFactors; y++) {
			if (numFactors[x] == denFactors[y] && numFactors[x] != 1 && numFactors[x] != -1) {
				return 0;
			}
		}
	}
	return 1;
}


int max(int *coeff, int numOfTerms) {
	int max = coeff[0];
	for (int x = 0; x < numOfTerms; x++) {
		if (coeff[x] > max) {
			max = coeff[x];
		}
	}
	return max;
}

double evalPolynomial(int *polynomial, double x, int numOfTerms) {
	double eval = 0;
	for (int i = numOfTerms; i >= 0; i--) {
		eval += polynomial[numOfTerms-i]*pow(x, (double)i);
	}
	return (float)(((int)(eval * 100 + 0.5)) / 100);
}


// Get coefficients given polynomial string
// Input: "x^4 - 7x^3 - 12x^2 + 68x + 112"
// Output: {1, -7, -12, 68, 112}

int coefficients(char *polynomialStr, int *allCoeff) {
	size_t len = strlen(polynomialStr);
	char  *polynomialStr2 = malloc(len + 1);
	strcpy(polynomialStr2, polynomialStr);
	polynomialStr2[len] = ' ';
	int exp = 0;
	int tempExp = 0;
	int termDegrees[15];
	int constant = 1;
	int termCnt = 0;
	int coeff = 0;
	int termCoeff[15];
	int tempCoeff = 0;
	int signFactor = 1;
	for (int x = 0; x < strlen(polynomialStr2); x++) {
		if (polynomialStr2[x] - '0' >= 0 && polynomialStr2[x] - '0' <= 9) {
			if (exp) {
				tempExp *= 10;
				tempExp += polynomialStr2[x] - '0';
			} else {
				tempCoeff *= 10;
				tempCoeff += polynomialStr2[x] - '0';
				coeff = 1;
			}
		} else if (polynomialStr2[x] == '^') {
			exp = 1;
		} else if (polynomialStr2[x] == 'x') {
			constant = 0;
			if (!coeff) {
				tempCoeff = 1;
			}
		} else if (polynomialStr2[x] == '-') {
			signFactor *= -1;
		} else {
			if (exp == 1) {
				termDegrees[termCnt] = tempExp;
				termCoeff[termCnt] = tempCoeff * signFactor;
				termCnt += 1;
				tempExp = 0;
				tempCoeff = 0;
				signFactor = 1;
			} else if (!constant) {
				termDegrees[termCnt] = 1;
				termCoeff[termCnt] = tempCoeff * signFactor;
				termCnt += 1;
				tempCoeff = 0;
				signFactor = 1;
			} else if (tempCoeff != 0) {
				termDegrees[termCnt] = 0;
				termCoeff[termCnt] = tempCoeff * signFactor;
				termCnt += 1;
				tempCoeff = 0;
				signFactor = 1;
			}
			exp = 0;
			constant = 1;
			coeff = 0;
		}
	}
	int totalTerms = max(termDegrees, termCnt) + 1;
	for (int x = 0; x < totalTerms; x++) {
		int termDegree = totalTerms - x - 1;
		int coefficient = 0;
		for (int y = 0; y < termCnt; y++) {
			if (termDegrees[y] == termDegree) {
				coefficient = termCoeff[y];
			} 
		}
		*(allCoeff++) = coefficient;
	}
	return totalTerms;
}

// Find factor of polynomial
// Input: {1, -7, -12, 68, 112}
// Output: -2
int rationalRoots(int *polynomial, int numOfTerms, int showWork) {
	int constantFactors[200];
	int numOfConstFactors = factors(abs(polynomial[numOfTerms-1]), constantFactors);
	int leadCoeffFactors[200];
	int numOfLeadFactors = factors(polynomial[0], leadCoeffFactors);
	if (showWork) {
		printf("Possible zeros: ");
		for (int x = 0; x < numOfConstFactors; x++) {
			for (int y = 0; y < numOfLeadFactors; y++) {
				if (*(constantFactors + x) > 0 && *(leadCoeffFactors + y) > 0) {
					if (simplified(*(constantFactors + x), *(leadCoeffFactors + y))) {
						if (*(constantFactors + x) % *(leadCoeffFactors + y) == 0) {
							printf("\u00B1%d ", *(constantFactors + x) / *(leadCoeffFactors + y));
						} else {
							printf("\u00B1%d/%d ", *(constantFactors + x), *(leadCoeffFactors + y));
						}
					}
				}
			}
		}
		printf("\n");
	}
	for (int x = 0; x < numOfConstFactors; x++) {
		for (int y = 0; y < numOfLeadFactors; y++) {
			if (evalPolynomial(polynomial, *(constantFactors + x) / *(leadCoeffFactors + y), numOfTerms-1) == 0) {
				return *(constantFactors + x) / *(leadCoeffFactors + y);
			}
		}
	}
	return polynomial[numOfTerms-1];
}


int synthDiv(int *polynomial, int divisor, int dividendLen, int *quotient) {
	*(quotient++) = polynomial[0];
	for (int x = 1; x < dividendLen; x++) {
		*(quotient++) = -divisor * *(quotient-1) + polynomial[x];
	}
	return divisor;
}

int main() {
	printf("Enter f(x):\n");
	char *polyStr = "x^8 + 9x^7 - 9x^6 - 271x^5 - 970x^4 - 1608x^3 - 1632x^2 - 1328x - 672";
	int coeff[30];
	int numOfTermsTot = coefficients(polyStr, coeff);
	for (int x = 0; x < numOfTermsTot; x++) {
		printf("%d ", coeff[x]);
	}
	printf("\n");
	char factoredForm[70];
	int root = rationalRoots(coeff, numOfTermsTot, 0);
	if (root != 0) {
		printf("f(%d) = 0\n", rationalRoots(coeff, numOfTermsTot, 1));
		printf("(x %s %d) is a factor\n", root > 0 ? "-" : "+", abs(root));
	}
	int q[numOfTermsTot-1];
	printf("%d\n", synthDiv(coeff, root, numOfTermsTot, q));
	for (int x = 0; x < numOfTermsTot-1; x++) {
		printf("%d ", q[x]);
	}
	printf("\n");
}
