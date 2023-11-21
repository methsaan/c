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

char *polynomialStr(int *polynomialCoeff, int polyDegree) {
	char *str = malloc(100 * sizeof(char));
	for (int x = 0; x < polyDegree; x++) {
		if (polynomialCoeff[x] != 0) {
			char termStr[15];
			if (polynomialCoeff[x] != 1 || x == polyDegree - 1) {
				sprintf(termStr, "%d", x == 0 ? polynomialCoeff[x] : abs(polynomialCoeff[x]));
				strcat(str, termStr);
			}
			if (x < polyDegree - 2) {
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
				sprintf(termStr, "x%s", polynomialCoeff[x+1] < 0 ? " - " : " + ");
				strcat(str, termStr);
			} else {
				;
			}
		}
	}
	return str;
}

// Find factor of polynomial
// Input: {1, -7, -12, 68, 112}
// Output: -2
double rationalRoots(int *polynomial, int numOfTerms, int showWork) {
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
			if (evalPolynomial(polynomial, (double)(*(constantFactors + x)) / *(leadCoeffFactors + y), numOfTerms-1) == 0) {
				return (double)(*(constantFactors + x)) / *(leadCoeffFactors + y);
			}
		}
	}
	return polynomial[numOfTerms-1];
}

int synthDiv(int *polynomial, int divisor, int dividendLen, int *quotient) {
	printf("%d | ", divisor);
	for (int x = 0; x < dividendLen; x++) {
		printf("%d\t ", polynomial[x]);
	}
	printf("\n  |\n  |\t ");
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
	for (int x = 0; x < dividendLen; x++) {
		printf("%d\t ", *(quotient-(dividendLen-x)));
	}
	printf("\n");
	return dividendLen-1;
}

int quadraticFactor(int a, int b, int c, double *zeros) {
	if (a == 1) {
		// integer solutions -> simple trinomial
		int constantFactors[200];
		int numOfConstFactors = factors(abs(c), constantFactors);
		for (int x = 0; x < numOfConstFactors; x++) {
			if (constantFactors[x] + c/constantFactors[x] == b) {
				*(zeros++) = -c/constantFactors[x];
				*(zeros++) = -constantFactors[x];
				return 0;
			}
		}
	} else {
		// no integer solutions -> complex trinomial
		int acFactors[200];
		int numOfacFactors = factors(abs(a*c), acFactors);
		for (int x = 0; x < numOfacFactors; x++) {
			if (acFactors[x] + a*c/acFactors[x] == b) {
				*(zeros++) = -(a*c/acFactors[x])/(double)a;
				*(zeros++) = -acFactors[x]/(double)a;
				return 1;
			}
		}
	}
	// no rational solutions -> quadratic formula
	int discriminant = pow(b, 2.0) - 4*a*c;
	if (discriminant >= 0) {
		*(zeros++) = (-b + sqrt(discriminant)) / (2*a);
		*(zeros++) = (-b - sqrt(discriminant)) / (2*a);
		return 2;
	} else {
		// no real solutions -> complex solutions
		*(zeros++) = discriminant;
		return 3;
	}
}

int isIn(double *arr, double num, int len) {
	for (int x = 0; x < len; x++) {
		if (arr[x] == num) {
			return 1;
		}
	}
	return 0;
}


int main() {
	printf("Enter f(x):\n");
	//char *polyStr = "x^8 + 9x^7 - 9x^6 - 271x^5 - 970x^4 - 1608x^3 - 1632x^2 - 1328x - 672";
	//char *polyStr = "x^6 + 18x^5 + 60x^4 - 774x^3 - 7485x^2 - 24300x - 28000";
	//char *polyStr = "2x^5 + 5x^4 - 76x^3 - 46x^2 + 290x - 175";
	//char *polyStr = "6x^5 + 37x^4 - 63x^3 - 149x^2 + 309x - 140";
	char *polyStr = "36x^6 + 228x^5 - 341x^4 - 957x^3 + 1705x^2 - 531x - 140";
	//char *polyStr = "72x^4 - 372x^3 - 1294x^2 + 2765x - 1225";
	printf("%s\n", polyStr);
	int coeff[30];
	int numOfTermsLeft = coefficients(polyStr, coeff);
	int numOfTermsInit = numOfTermsLeft;
	double zeros[15];
	int zerosCnt = 0;
	char *factoredForm = malloc(130 * sizeof(char));

	double root = rationalRoots(coeff, numOfTermsLeft, 1);
	if (root != 0) {
		char tempFactor[20];
		if ((int)rationalRoots(coeff, numOfTermsLeft, 0) == rationalRoots(coeff, numOfTermsLeft, 0)) {
			printf("f(%d) = 0\n", (int)rationalRoots(coeff, numOfTermsLeft, 0));
			printf("(x %s %d)\n", rationalRoots(coeff, numOfTermsLeft, 0) > 0 ? "-" : "+", abs(rationalRoots(coeff, numOfTermsLeft, 0)));
		} else {
			int num;
			int den = 1;
			double decimal = rationalRoots(coeff, numOfTermsLeft, 0);
			double temp = decimal;
			while ((int)(decimal*den) - temp >= 0.000001 || (int)(decimal*den) - temp <= -0.000001) {
				temp += decimal;
				den++;
			}
			num = (int)round(temp);
			printf("f(%d/%d) = 0\n", num, den);
			printf("(%dx %s %d)\n", den, num < 0 ? "+" : "-", abs(num));
		}
		zeros[zerosCnt++] = root;
		//sprintf(tempFactor, "(x %s %d)", root > 0 ? "-" : "+", abs(root));
		//strcat(factoredForm, tempFactor);
	}

	for (int x = 0; x < numOfTermsInit-3; x++) {
		numOfTermsLeft = synthDiv(coeff, -root, numOfTermsLeft, coeff);
		root = rationalRoots(coeff, numOfTermsLeft, 1);
		if (root != 0) {
			char tempFactor[20];
			if ((int)rationalRoots(coeff, numOfTermsLeft, 0) == rationalRoots(coeff, numOfTermsLeft, 0)) {
				printf("f(%d) = 0\n", (int)rationalRoots(coeff, numOfTermsLeft, 0));
				printf("(x %s %d)\n", rationalRoots(coeff, numOfTermsLeft, 0) > 0 ? "-" : "+", abs(rationalRoots(coeff, numOfTermsLeft, 0)));
			} else {
				int num;
				int den = 1;
				double decimal = rationalRoots(coeff, numOfTermsLeft, 0);
				double temp = decimal;
				while ((int)(decimal*den) - temp >= 0.000001 || (int)(decimal*den) - temp <= -0.000001) {
					temp += decimal;
					den++;
				}
				num = (int)round(temp);
				printf("f(%d/%d) = 0\n", num, den);
				printf("(%dx %s %d)\n", den, num < 0 ? "+" : "-", abs(num));
			}

			if (x != numOfTermsInit-4) {
				zeros[zerosCnt++] = root;
			}
			//sprintf(tempFactor, "(x %s %d)", root > 0 ? "-" : "+", abs(root));
			//strcat(factoredForm, tempFactor);
		} // else - x is a factor
	}
	double solutions[2];
	int type = quadraticFactor(coeff[0], coeff[1], coeff[2], solutions);
	if (type == 0) {
		char tempFactor[20];
		printf("(x %s %d)(x %s %d)\n", solutions[0] > 0 ? "-" : "+", abs(solutions[0]), solutions[1] > 0 ? "-" : "+", abs(solutions[1]));
		zeros[zerosCnt++] = solutions[0];
		zeros[zerosCnt++] = solutions[1];
		//sprintf(tempFactor, "(x %s %d)(x %s %d)", solutions[0] > 0 ? "-" : "+", abs(solutions[0]), solutions[1] > 0 ? "-" : "+", abs(solutions[1]));
		//strcat(factoredForm, tempFactor);
	} else if (type == 1) {
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
			char tempFactor[20];
			if (den[x] == 1) {
				printf("(x %s %d)", num[x] < 0 ? "+" : "-", abs(num[x]));
				//sprintf(tempFactor, "(x %s %d)", num[x] < 0 ? "+" : "-", abs(num[x]));
				//strcat(factoredForm, tempFactor);
			} else {
				printf("(%dx %s %d)", den[x], num[x] < 0 ? "+" : "-", abs(num[x]));
				//sprintf(tempFactor, "(%dx %s %d)", den[x], num[x] < 0 ? "+" : "-", abs(num[x]));
				//strcat(factoredForm, tempFactor);
			}
		}
		printf("\n");
	} else if (type == 2) {
		char tempFactor[20];
		printf("%s\n", polynomialStr(coeff, numOfTermsLeft));
		sprintf(tempFactor, "(%s)", polynomialStr(coeff, numOfTermsLeft));
		strcat(factoredForm, tempFactor);
	} else {
		char tempFactor[20];
		printf("%s\n", polynomialStr(coeff, numOfTermsLeft));
		sprintf(tempFactor, "(%s)", polynomialStr(coeff, numOfTermsLeft));
		strcat(factoredForm, tempFactor);
	}
	printf("%s\n", factoredForm);
	for (int x = 0; x < zerosCnt; x++) {
		printf("%f ", zeros[x]);
	}
	printf("\n");
	double zerosRemRepeat[zerosCnt];
	int zerosFreq[zerosCnt];
	int uniqueZeroCnt = 0;
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
	for (int x = 0; x < uniqueZeroCnt; x++) {
		printf("%f ", zerosRemRepeat[x]);
	}
	printf("\n");
	for (int x = 0; x < uniqueZeroCnt; x++) {
		printf("%d ", zerosFreq[x]);
	}
	printf("\n");
	for (int x = 0; x < uniqueZeroCnt; x++) {
		if (zerosFreq[x] > 1) {
			printf("(");
		}
		if ((int)zerosRemRepeat[x] == zerosRemRepeat[x]) {
			printf("(x %s %d)", zerosRemRepeat[x] > 0 ? "-" : "+", abs(zerosRemRepeat[x]));
		} else {
			int num;
			int den = 1;
			double decimal = rationalRoots(coeff, numOfTermsLeft, 0);
			double temp = decimal;
			while ((int)(decimal*den) - temp >= 0.000001 || (int)(decimal*den) - temp <= -0.000001) {
				temp += decimal;
				den++;
			}
			num = (int)round(temp);
			printf("(%dx %s %d)", den, num < 0 ? "+" : "-", abs(num));
		}
		if (zerosFreq[x] > 1) {
			printf("^%d)", zerosFreq[x]);
		}
	}
	printf("\n");
}
