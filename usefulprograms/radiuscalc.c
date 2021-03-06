#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv){
	char option[100];
 	double circumference;
 	double area;
 	double volume;
 	const double PI = 3.141592653589793;
 	double height;
	double radius;
 	printf("Options: circle circ, circle area, cylinder volume, cylinder area\nEnter your option: ");
	fgets(option, 100, stdin);
	if (strcmp(option, "circle circ\n") == 0) {
		printf("Enter circumference: ");
		scanf("%lf", &circumference);
		radius = circumference/PI/2.0;
		printf("Radius: %.20g\n", radius);
	}else if (strcmp(option, "circle area\n") == 0) {
		printf("Enter area: ");
		scanf("%lf", &area);
		radius = sqrt(area/PI);
		printf("radius: %.20g\n", radius);
	}else if (strcmp(option, "cylinder area\n") == 0) {
		printf("Enter surface area: ");
		scanf("%lf", &area);
		printf("Enter height: ");
		scanf("%lf", &height);
		radius = (sqrt(pow(height, 2)+2*area/PI) - height) / 2;
		printf("radius: %.20g\n", radius);
	}else if (strcmp(option, "cylinder volume\n") == 0) {
		printf("Enter volume: ");
		scanf("%lf", &volume);
		printf("Enter height: ");
		scanf("%lf", &height);
		area = volume/height;
		radius = sqrt(area/PI);
		printf("radius: %.20g\n", radius);
	}
}
