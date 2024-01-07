#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// polynomialFactor.c
// Oct. 10 - Nov. 28
// Factor polynomial given standard form
// Input: x^4 - 7x^3 - 12x^2 + 68x + 112
// Output: (x - 4)(x + 2)^2(x - 7)

// Test cases:

// "x^6 + 18x^5 + 60x^4 - 774x^3 - 7485x^2 - 24300x - 28000"
// Repeated factor, all integer solutions - PASS

// "x^8 + 9x^7 - 9x^6 - 271x^5 - 970x^4 - 1608x^3 - 1632x^2 - 1328x - 672"
// One complex solution, all integer solutions - PASS

// "x^6 - 18x^5 + 106x^4 - 150x^3 - 701x^2 + 2760x - 3150"
// One complex solution, all integer solutions - PASS

// "2x^5 + 5x^4 - 76x^3 - 46x^2 + 290x - 175"
// One rational, non-integer solution - PASS

// "6x^5 + 37x^4 - 63x^3 - 149x^2 + 309x - 140"
// More than one rational, non-integer solution - PASS

// "36x^6 + 228x^5 - 341x^4 - 957x^3 + 1705x^2 - 531x - 140"
// More than one rational, non-integer solution - PASS

// "72x^4 - 372x^3 - 1294x^2 + 2765x - 1225"
// More than one rational, non-integer solution - PASS

// "72x^8 - 372x^7 - 1294x^6 + 2765x^5 - 1225x^4"
// x is a factor - PASS

// "x^9 + 9x^8 - 9x^7 - 271x^6 - 970x^5 - 1608x^4 - 1632x^3 - 1328x^2 - 672x"
// x is a factor, complex solution - PASS

// "x^8 - 18x^7 + 107x^6 - 168x^5 - 595x^4 + 2610x^3 - 3851x^2 + 2760x - 3150"
// More than one complex/irrational solution - FAIL

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

// Determine if fraction is simplified
// Input: num = 4, den = 6
// Output: 0
int simplified(int num, int den) {
	// Store factors of numerator and denominator
	int numFactors[100];
	int denFactors[100];
	int numOfNumFactors = factors(num, numFactors);
	int numOfDenFactors = factors(den, denFactors);
	// Return false if numerator and denominator share a common factor other than 1
	for (int x = 0; x < numOfNumFactors; x++) {
		for (int y = 0; y < numOfDenFactors; y++) {
			if (numFactors[x] == denFactors[y] && numFactors[x] != 1 && numFactors[x] != -1) {
				return 0;
			}
		}
	}
	// Return true otherwise
	return 1;
}

// Return maximum number in a list
// Input: {4, 2, 1, 5, 9, 8}
// Output: 9
int max(int *num, int numOfTerms) {
	// Store max as first number
	int max = num[0];
	for (int x = 0; x < numOfTerms; x++) {
		// Store new biggest number in max
		if (num[x] > max) {
			max = num[x];
		}
	}
	// Return max
	return max;
}

// Evaluate polynomial function given x
// Input: {10, 39, -90, -175}, 2.5, 4
// Output: 0
double evalPolynomial(int *polynomial, double x, int numOfTerms) {
	// Store sum of terms
	double eval = 0;
	for (int i = numOfTerms; i >= 0; i--) {
		// Add next term
		eval += polynomial[numOfTerms-i]*pow(x, (double)i);
	}
	// Return total
	return eval;
}

// Get coefficients given polynomial string
// Input: "x^4 - 7x^3 - 12x^2 + 68x + 112"
// Output: {1, -7, -12, 68, 112}
int coefficients(char *polynomialStr, int *allCoeff) {
	// Duplicate of string with added space - extra character for parsing
	size_t len = strlen(polynomialStr);
	char *polynomialStr2 = malloc(len + 1);
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

// Return polynomial as a string given coefficients
// Input: {4, 7, 0, 0, -5, 0}
// Output: 4x^4 + 7x^3 -5x
char *polynomialStr(int *polynomialCoeff, int polyDegree) {
	// Initialize string
	char *str = malloc(100 * sizeof(char));
	// Loop through coefficients
	for (int x = 0; x < polyDegree; x++) {
		// Add term string to final result if coefficient is not zero
		if (polynomialCoeff[x] != 0) {
			char termStr[15];
			// coefficient portion
			if (polynomialCoeff[x] != 1 || x == polyDegree - 1) {
				// if coefficient is not 1 or if term is a constant
				sprintf(termStr, "%d", x == 0 ? polynomialCoeff[x] : abs(polynomialCoeff[x]));
				strcat(str, termStr);
			}
			// variable portion
			if (x < polyDegree - 2) {
				// term has a degree greater than 1
				int nextTerm;
				for (int y = x+1; y < polyDegree; y++) {
					if (polynomialCoeff[y] != 0) {
						nextTerm = polynomialCoeff[y];
						break;
					}
				}
				sprintf(termStr, "x^%d%s", polyDegree-x-1, nextTerm < 0 ? " - " : " + ");
				strcat(str, termStr);
			} else if (x == polyDegree - 2) {
				// term degree is 1
				sprintf(termStr, "x%s", polynomialCoeff[x+1] < 0 ? " - " : " + ");
				strcat(str, termStr);
			} else {
				// term is constant (no variable portion to add)
				;
			}
		}
	}
	// return result
	return str;
}

// Perform rational roots test - find zero of polynomial
// Input: {1, -7, -12, 68, 112}
// Output: -2
double rationalRoots(int *polynomial, int numOfTerms, int showWork) {
	// return 0 as a zero if constant is 0
	if (polynomial[numOfTerms-1] == 0) {
		return 0;
	}
	// Store factors of lead coefficient and constant
	int constantFactors[200];
	int numOfConstFactors = factors(abs(polynomial[numOfTerms-1]), constantFactors);
	int leadCoeffFactors[200];
	int numOfLeadFactors = factors(polynomial[0], leadCoeffFactors);
	// display possible zeroes (all constant factors / all lead coefficient factors)
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
	// return value that evaluates to zero
	for (int x = 0; x < numOfConstFactors; x++) {
		for (int y = 0; y < numOfLeadFactors; y++) {
			if (evalPolynomial(polynomial, (double)(*(constantFactors + x)) / *(leadCoeffFactors + y), numOfTerms-1) == 0) {
				return (double)(*(constantFactors + x)) / *(leadCoeffFactors + y);
			}
		}
	}
	// return constant if no factors
	return polynomial[numOfTerms-1];
}

// Perform synthetic division given polynomial and divisor
// Input: {1, 18, 60, -774, -7485, -24300, -28000}, -8
// Output: {1, 26, 268, 1370, 3475, 3500}
int synthDiv(int *polynomial, int divisor, int dividendLen, int *quotient) {
	// Display dividend and divisor
	printf("%d | ", divisor);
	for (int x = 0; x < dividendLen; x++) {
		printf("%d\t ", polynomial[x]);
	}
	printf("\n  |\n  |\t ");
	// Calculate quotient and display product of quotient and divisor
	*(quotient++) = polynomial[0];
	for (int x = 1; x < dividendLen; x++) {
		printf("%d\t ", divisor * *(quotient-1));
		*(quotient++) = -divisor * *(quotient-1) + polynomial[x];
	}
	printf("\n  |");
	for (int x = 0; x < dividendLen; x++) {
		printf("________");
	}
	printf("\n    ");
	// Display quotient
	for (int x = 0; x < dividendLen; x++) {
		printf("%d\t ", *(quotient-(dividendLen-x)));
	}
	printf("\n");
	return dividendLen-1;
}

// Perform polynomial long division given polynomial and numerator and
// denominator of linear divisor zero
// Input: {2, 5, -76, -46, 290, -175}, num=-5, den=2
// Output: {1, -38, 72, -35}
int polyLongDiv(int *polynomial, int num, int den, int dividendLen, int *quotient) {
	// Duplicate dividend polynomial to modify values
	int polynomial2[dividendLen];
	for (int x = 0; x < dividendLen; x++) {
		polynomial2[x] = polynomial[x];
	}
	// Duplicate to preserve original dividend
	int polynomial3[dividendLen];
	for (int x = 0; x < dividendLen; x++) {
		polynomial3[x] = polynomial[x];
	}
	// Calculate quotient terms
	for (int x = 0; x < dividendLen-1; x++) {
		*(quotient++) = polynomial2[x]/den;
		polynomial2[x+1] += num * *(quotient-1);
	}
	printf("\n");
	printf("\t\t\t ");
	for (int x = 0; x < dividendLen-1; x++) {
		printf(" %d\t", *(quotient-dividendLen+x+1));
	}
	printf("\n");
	printf(" \t\t__________________________________\n");
	printf("%d\t %d \t| ", den, -num);
	for (int x = 0; x < dividendLen; x++) {
		printf("%d\t ", polynomial3[x]);
	}
	printf("\n");
	for (int x = 0; x < dividendLen-1; x++) {
		if (x > 0) {
			for (int y = 0; y < x+1; y++) {
				printf("\t");
			}
			printf(" %d\t %d\n", polynomial2[x-1], -num * *(quotient-dividendLen+x));
			for (int y = 0; y < x+1; y++) {
				printf("\t");
			}
			printf("_____________\n");
		}
	}
	for (int y = 0; y < dividendLen; y++) {
		printf("\t");
	}
	printf(" %d\t %d\n", polynomial2[dividendLen-2], -num * *(quotient-1));
	for (int y = 0; y < dividendLen; y++) {
		printf("\t");
	}
	printf("____________\n");
	for (int y = 0; y < dividendLen+1; y++) {
		printf(" \t");
	}
	printf("0\n");
	return dividendLen-1;
	return dividendLen-1;
}

// Return zeroes and type of quadratic given quadratic terms
// 0 = integer solutions
// 1 = non-integer, rational solutions
// 2 = irrational, real solutions
// 3 = complex solutions
// Input: 1, -6, 5
// Output: zeros: -5 -1, type: 0
int quadraticFactor(int a, int b, int c, double *zeros) {
	if (a == 1) {
		// integer solutions -> simple trinomial
		// store factors of constant
		int constantFactors[200];
		int numOfConstFactors = factors(abs(c), constantFactors);
		// find factors that multiply to c and add to b
		for (int x = 0; x < numOfConstFactors; x++) {
			if (constantFactors[x] + c/constantFactors[x] == b) {
				// store factors as zeros
				*(zeros++) = -c/constantFactors[x];
				*(zeros++) = -constantFactors[x];
				// return type
				return 0;
			}
		}
	} else {
		// no integer solutions -> complex trinomial
		// store factors of ac
		int acFactors[200];
		int numOfacFactors = factors(abs(a*c), acFactors);
		// find factors that add to b
		for (int x = 0; x < numOfacFactors; x++) {
			if (acFactors[x] + a*c/acFactors[x] == b) {
				// store factors as zeros
				//*(zeros++) = -(a*c/acFactors[x])/(double)a;
				*(zeros++) = -c/acFactors[x];
				*(zeros++) = -acFactors[x]/(double)a;
				// return type
				return 1;
			}
		}
	}
	// no rational solutions -> quadratic formula
	// calculate discriminant
	int discriminant = pow(b, 2.0) - 4*a*c;
	if (discriminant >= 0) {
		// real solutions -> quadratic formula
		// calculate zeros from discriminant and store
		*(zeros++) = (-b + sqrt(discriminant)) / (2*a);
		*(zeros++) = (-b - sqrt(discriminant)) / (2*a);
		// return type
		return 2;
	} else {
		// no real solutions -> complex solutions
		// store discriminant as zero
		*(zeros++) = discriminant;
		// return type
		return 3;
	}
}

// check if number is in an array or not
// Input: {3, 2, 5.5, 2, 3.5}, 5.5
// Output: 1
int isIn(double *arr, double num, int len) {
	for (int x = 0; x < len; x++) {
		if (arr[x] == num) {
			return 1;
		}
	}
	return 0;
}

// Main program
int main() {
	// Ask user for f(x) - polynomial to factor
	printf("Enter f(x):\n");
	char polyStr[150];
	fgets(polyStr, 150, stdin);
	// Store number of terms and string as coefficients
	int coeff[30];
	int numOfTermsLeft = coefficients(polyStr, coeff);
	int numOfTermsInit = numOfTermsLeft;
	// Declare array of zeros
	double zeros[15];
	int zerosCnt = 0;
	// Factored form string - final result
	char *factoredForm = malloc(130 * sizeof(char));
	// Factored portion of equation after each division operation
	char *tempFactored = malloc(130 * sizeof(char));
	// Temporary factor to add to tempFactored after division
	char tempFactorDiv[20];

	// Wait for return key before printing step
	getchar();
	// Print function
	printf("f(x) = %s\n", polynomialStr(coeff, numOfTermsLeft));
	printf("Let P(x) = %s\n", polyStr);
	// Find 1 zero of function
	double root = rationalRoots(coeff, numOfTermsLeft, 1);
	int num; // numerator of non-integer rational zero
	int den; // denominator, -1 if zero is an integer

	// if 0 is not a zero
	if (root != 0) {
		if ((int)rationalRoots(coeff, numOfTermsLeft, 0) == rationalRoots(coeff, numOfTermsLeft, 0)) {
			// Display zero and add to factored portion of f(x) string
			printf("P(%d) = 0\n", (int)rationalRoots(coeff, numOfTermsLeft, 0));
			printf("(x %s %d) is a factor\n", rationalRoots(coeff, numOfTermsLeft, 0) > 0 ? "-" : "+", abs(rationalRoots(coeff, numOfTermsLeft, 0)));
			sprintf(tempFactorDiv, "(x %s %d)", rationalRoots(coeff, numOfTermsLeft, 0) > 0 ? "-" : "+", abs(rationalRoots(coeff, numOfTermsLeft, 0)));
			strcat(tempFactored, tempFactorDiv);
			den = -1;
		} else {
			// Calculate denominator and numerator of fraction
			// given rational decimal
			den = 1;
			double decimal = rationalRoots(coeff, numOfTermsLeft, 0);
			double temp = decimal;
			while ((int)(decimal*den) - temp >= 0.000001 || (int)(decimal*den) - temp <= -0.000001) {
				temp += decimal;
				den++;
			}
			num = (int)round(temp);
			// Display zero and add to factored portion of f(x) string
			printf("P(%d/%d) = 0\n", num, den);
			printf("(%dx %s %d) is a factor\n", den, num < 0 ? "+" : "-", abs(num));
			sprintf(tempFactorDiv, "(%dx %s %d)", den, num < 0 ? "+" : "-", abs(num));
			strcat(tempFactored, tempFactorDiv);
		}
		// Add root to zeroes list
		zeros[zerosCnt++] = root;
	} else {
		// x is a factor
		zeros[zerosCnt++] = 0;
		numOfTermsLeft--;
		den = -1;
	}
	// While number of unfactored terms left is greater than 3
	for (int x = 0; x < numOfTermsInit-3; x++) {
		// Wait for return key before printing step
		getchar();
		// if 0 is not a zero
		if (root != 0) {
			// Divide polynomial by root
			if (den != -1) {
				// Use polynomial long division if root is a non-integer
				numOfTermsLeft = polyLongDiv(coeff, num, den, numOfTermsLeft, coeff);
			} else {
				// Use synthetic division if root is a integer
				numOfTermsLeft = synthDiv(coeff, -root, numOfTermsLeft, coeff);
			}
		}
		// Wait for return key before printing step
		getchar();
		// Display f(x)
		printf("f(x) = %s(%s)\n", tempFactored, polynomialStr(coeff, numOfTermsLeft));
		// Initialize P(x) (unfactored portion of f(x))
		printf("Let P(x) = %s\n", polynomialStr(coeff, numOfTermsLeft));
		root = rationalRoots(coeff, numOfTermsLeft, x != numOfTermsInit-4 ? 1 : 0);
		if (root != 0) {
			if ((int)rationalRoots(coeff, numOfTermsLeft, 0) == rationalRoots(coeff, numOfTermsLeft, 0)) {
				// If number of unfactored terms left is greater than 4
				if (x != numOfTermsInit-4) {
					// Display zero and add to factored portion of f(x) string
					printf("P(%d) = 0\n", (int)rationalRoots(coeff, numOfTermsLeft, 0));
					printf("(x %s %d) is a factor\n", rationalRoots(coeff, numOfTermsLeft, 0) > 0 ? "-" : "+", abs(rationalRoots(coeff, numOfTermsLeft, 0)));
					sprintf(tempFactorDiv, "(x %s %d)", rationalRoots(coeff, numOfTermsLeft, 0) > 0 ? "-" : "+", abs(rationalRoots(coeff, numOfTermsLeft, 0)));
					strcat(tempFactored, tempFactorDiv);
				}
				den = -1;
			} else {
				// Calculate denominator and numerator of fraction
				// given rational decimal
				den = 1;
				double decimal = rationalRoots(coeff, numOfTermsLeft, 0);
				double temp = decimal;
				while ((int)(decimal*den) - temp >= 0.000001 || (int)(decimal*den) - temp <= -0.000001) {
					temp += decimal;
					den++;
				}
				num = (int)round(temp);
				// If number of unfactored terms left is greater than 4
				if (x != numOfTermsInit-4) {
					// Display zero and add to factored portion of f(x) string
					printf("P(%d/%d) = 0\n", num, den);
					printf("(%dx %s %d) is a factor\n", den, num < 0 ? "+" : "-", abs(num));
					sprintf(tempFactorDiv, "(%dx %s %d)", den, num < 0 ? "+" : "-", abs(num));
					strcat(tempFactored, tempFactorDiv);
				}
			}

			if (x != numOfTermsInit-4) {
				// Add root
				zeros[zerosCnt++] = root;
			}
		} else {
			// x is a factor
			zeros[zerosCnt++] = 0;
			numOfTermsLeft--;
			den = -1;
		}
	}
	// Find zeroes of remaining 3 terms and type of quadratic equation
	double solutions[2];
	int type = quadraticFactor(coeff[0], coeff[1], coeff[2], solutions);
	char unfactorable[20]; // Remaining string if unfactorable
	// Add zeroes and show work for quadratic factoring
	if (type == 0) {
		// Integer solutions
		printf("P(x) = %s\n", polynomialStr(coeff, numOfTermsLeft));
		printf("     = (x %s %d)(x %s %d)\n", solutions[0] > 0 ? "-" : "+", abs(solutions[0]), solutions[1] > 0 ? "-" : "+", abs(solutions[1]));
		zeros[zerosCnt++] = solutions[0];
		zeros[zerosCnt++] = solutions[1];
	} else if (type == 1) {
		// Non-integer rational solutions
		printf("P(x) = %s\n     = ", polynomialStr(coeff, numOfTermsLeft));
		zeros[zerosCnt++] = solutions[0];
		zeros[zerosCnt++] = solutions[1];
		int num[2];
		int den[] = {1, 1};
		for (int x = 0; x < 2; x++) {
			double temp = solutions[x];
			while ((int)(solutions[x]*den[x]) - temp >= 0.000001 || (int)(solutions[x]*den[x]) - temp <= -0.000001) {
				temp += solutions[x];
				den[x]++;
			}
			num[x] = temp;
		}
		for (int x = 0; x < 2; x++) {
			if (den[x] == 1) {
				printf("(x %s %d)", num[x] < 0 ? "+" : "-", abs(num[x]));
			} else {
				printf("(%dx %s %d)", den[x], num[x] < 0 ? "+" : "-", abs(num[x]));
			}
		}
		printf("\n");
	} else if (type == 2) {
		// Real, irrational solutions
		printf("Cannot factor further.");
		sprintf(unfactorable, "(%s)", polynomialStr(coeff, numOfTermsLeft));
	} else {
		// Complex solutions
		printf("Cannot factor further.");
		sprintf(unfactorable, "(%s)", polynomialStr(coeff, numOfTermsLeft));
	}
	double zerosRemRepeat[zerosCnt]; // Zeroes without duplicates
	int zerosFreq[zerosCnt]; // Frequency of zeroes (parallel with zerosRemRepeat)
	int uniqueZeroCnt = 0; // number of unique zeros
	// Store zeros without duplicates and determine frequencies
	for (int x = 0; x < zerosCnt; x++) {
		if (!isIn(zerosRemRepeat, zeros[x], uniqueZeroCnt)) {
			zerosRemRepeat[uniqueZeroCnt++] = zeros[x];
		}
	}
	for (int x = 0; x < uniqueZeroCnt; x++) {
		zerosFreq[x] = 0;
		for (int y = 0; y < zerosCnt; y++) {
			if (zerosRemRepeat[x] == zeros[y]) {
				zerosFreq[x]++;
			}
		}
	}
	// Add factor strings to result
	for (int x = 0; x < uniqueZeroCnt; x++) {
		if (zerosRemRepeat[x] != 0) {
			if (zerosFreq[x] > 1) {
				strcat(factoredForm, "(");
				}
			if ((int)zerosRemRepeat[x] == zerosRemRepeat[x]) {
				char tempFactor[20];
				sprintf(tempFactor, "(x %s %d)", zerosRemRepeat[x] > 0 ? "-" : "+", abs(zerosRemRepeat[x]));
				strcat(factoredForm, tempFactor);
			} else {
				char tempFactor[20];
				int num;
				int den = 1;
				double decimal = zerosRemRepeat[x];
				double temp = decimal;
				while ((int)(decimal*den) - temp >= 0.000001 || (int)(decimal*den) - temp <= -0.000001) {
					temp += decimal;
					den++;
				}
				num = (int)round(temp);
				sprintf(tempFactor, "(%dx %s %d)", den, num < 0 ? "+" : "-", abs(num));
				strcat(factoredForm, tempFactor);
			}
			if (zerosFreq[x] > 1) {
				char tempFactor[20];
				sprintf(tempFactor, "^%d)", zerosFreq[x]);
				strcat(factoredForm, tempFactor);
			}
		} else {
			// x is a factor
			char tempFactor[6];
			if (zerosFreq[x] > 1) {
				sprintf(tempFactor, "(x^%d)", zerosFreq[x]);
			} else {
				sprintf(tempFactor, "x");
			}
			strcat(factoredForm, tempFactor);
		}
	}
	if (type == 2 || type == 3) {
		// Add unfactorable
		strcat(factoredForm, unfactorable);
	}
	printf("\n");
	// Output result
	printf("f(x) = %s\n", factoredForm);
}
