#include <stdio.h>

double smaller(double a, double b){
	if ((int)a > (int)b){
		return b;
	}
	else {
		return a;
	}
}
double larger(double a, double b){
	if ((int)a < (int)b) {
		return b;
	}else {
		return a;
	}
}
int main(int argc, char *argv) {
	double num1inp;
	double num2inp;
	double num1;
	double num2;
	printf("Enter two numbers to find the product: ");
	scanf("%lf %lf", &num1inp, &num2inp);
	num2 = smaller(num1inp, num2inp);
	num1 = larger(num1inp, num2inp);
	getchar();
	printf("Step 1:\n");
	double difference = num1-num2;
	printf("\t%g - %g = %g\n", num1, num2, difference);
	getchar();
	printf("Step 2:\n");
	double quotient = difference/2.0;
	printf("\t%g \u00F7 2 = %g\n", difference, quotient);
	getchar();
	printf("Step 3:\n");
	double midnum = smaller(num1, num2)+quotient;
	printf("\t%g + %g = %g\n", smaller(num1, num2), quotient, midnum);
	getchar();
	printf("Step 4:\n");
	double square = midnum*midnum;
	printf("\t%g\u00B2 = %g\n", midnum, square);
	getchar();
	printf("Step 5:\n");
	double quotsquare = quotient*quotient;
	printf("\t%g \u00F7 2 = %g\n", difference, quotient);
	printf("\t%g \u00D7 %g = %g\n", quotient, quotient, quotsquare);
	getchar();
	printf("Step 6:\n");
	double answer = square-quotsquare;
	printf("\t%g - %g = %g\n\n", square, quotsquare, answer);
	printf("Answer: %g\n", answer);
	printf("Press s and Enter see the steps. Press q to quit\n");
	char x = getchar();
	if (x == 's'){
		printf("Step 1: find the difference of the two numbers.\n");
		printf("Step 2: divide that result by 2.\n");
		printf("Step 3: add that result to the smaller number out of the two beginning numbers.\n");
		printf("Step 4: multiply that result by itself.\n");
		printf("Step 5: multiply the result in step 2 by itself.\n");
		printf("Step 6: subtract the result in step 4 by the result in step 5.\n");
	}else if (x == 'q'){
	}else {
	}
}
