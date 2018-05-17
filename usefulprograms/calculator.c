#include <stdio.h>
#include <math.h>

int main(int argc, char* argv)
{
	char operator[20];
	double a;
	double b;
	double c;
	printf("Welcome to calculator. Options: add, sub, mul, div\n");
	printf("Enter operator: ");
	scanf("%s", operator);
	printf("Enter first number: ");
	scanf("%f", &a);
	printf("Enter second number: ");
<<<<<<< HEAD
	scanf("%f", &b);
	if (operator == "add"){
		c = a + b;
		printf("%f + %f = %f\n", a, b, c);
	}
	if (operator == "sub"){
		c = a - b;
		printf("%f - %f = %f\n", a, b, c);
	}
	if (operator == "mul"){
		c = a * b;
		printf("%f x %f = %f\n", a, b, c);
	}
	if (operator == "div"){
		c = a / b;
		printf("%f / %f = %f\n", a, b, c);
	}
	if (operator != "add") && (operator != "sub") && (operator != "mul") && (operator != "div"){
		printf("Invalid operator\n");
	}
	return(0);
=======
	scanf("%lf", &b);
	//if (operator == "add"){
	c = a + b;
	printf("%lf + %lf = %lf\n", a, b, c);
	//}else if (operator == "sub"){
	//	c = a - b;
	//	printf("%lf - %lf = %lf\n", a, b, c);
	//}else if (operator == "mul"){
	//	c = a * b;
	//	printf("%lf x %lf = %lf\n", a, b, c);
	//}else if (operator == "div"){
	//	c = a / b;
	//	printf("%lf / %lf = %lf\n", a, b, c);
	//}else{
	//	printf("Invalid operator\n");
	//}
	//return(0);
>>>>>>> dd6143908f8ef7ffcdabd1a0524492eefa1fd562
}
