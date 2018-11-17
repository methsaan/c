#include <stdio.h>

int smaller(int a, int b){
	if (a > b){
		return b;
	}
	else {
		return a;
	}
}
int larger(int a, int b){
	if (a < b) {
		return b;
	}else {
		return a;
	}
}
int main(int argc, char *argv) {
	int num1inp;
	int num2inp;
	int num1;
	int num2;
	printf("Enter two numbers with an even difference to find the product: ");
	scanf("%d %d", &num1inp, &num2inp);
	num2 = smaller(num1inp, num2inp);
	num1 = larger(num1inp, num2inp);
	getchar();
	printf("Step 1:\n");
	int difference = num1-num2;
	printf("\t%d - %d = %d\n", num1, num2, difference);
	getchar();
	printf("Step 2:\n");
	int quotient = difference/2;
	printf("\t%d \u00F7 2 = %d\n", difference, quotient);
	getchar();
	printf("Step 3:\n");
	int midnum = smaller(num1, num2)+quotient;
	printf("\t%d + %d = %d\n", smaller(num1, num2), quotient, midnum);
	getchar();
	printf("Step 4:\n");
	int square = midnum*midnum;
	printf("\t%d\u00B2 = %d\n", midnum, square);
	getchar();
	printf("Step 5:\n");
	int quotsquare = quotient*quotient;
	printf("\t%d \u00F7 2 = %d\n", difference, quotient);
	printf("\t%d \u00D7 %d = %d\n", quotient, quotient, quotsquare);
	getchar();
	printf("Step 6:\n");
	int answer = square-quotsquare;
	printf("\t%d - %d = %d\n\n", square, quotsquare, answer);
	printf("Answer: %d\n", answer);
	printf("Press s and Enter see the steps. Press q to quit\n");
	char x = getchar();
	if (x == 'q'){
	}else if (x == 's'){
		printf("Step 1: find the difference of the two numbers.\n");
		printf("Step 2: divide that result by 2.\n");
		printf("Step 3: add that result to the smaller number out of the two beginning numbers.\n");
		printf("Step 4: multiply that result by itself.\n");
		printf("Step 5: multiply the result in step 2 by itself.\n");
		printf("Step 6: subtract the result in step 4 by the result in step 5.\n");
	}else {
	}
}
