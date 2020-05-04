#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv){
	char option[100];
	double radius;
	const double PI = 3.14159265358979323846264833;
	double height;
	printf("Options: circle_area, circle_circ, cylinder_area, cylinder_volume, cone_area, cone_vol, sphere_area, sphere_vol\nEnter your option: ");
	fgets(option, 100, stdin);
	if (strcmp(option, "circle_area\n") == 0){
		printf("Enter radius: ");
		scanf("%lf", &radius);
		printf("Area: %.50fu\u00B2\n", PI*pow(radius, 2));
	}else if (strcmp(option, "circle_circ\n") == 0){
		printf("Enter radius: ");
		scanf("%lf", &radius);
		printf("Circumference: %.50fu\n", 2*PI*radius);
	}else if (strcmp(option, "cylinder_area\n") == 0){
		printf("Enter radius: ");
		scanf("%lf", &radius);
		printf("Enter height: ");
		scanf("%lf", &height);
		printf("Surface area: %.50fu\u00B2\n", (PI*pow(radius, 2))*2+(2*PI*radius)*height);
	}else if (strcmp(option, "cylinder_volume\n") == 0){
		printf("Enter radius: ");
		scanf("%lf", &radius);
		printf("Enter height: ");
		scanf("%lf", &height);
		printf("Volume: %.50fu\u00B3\n", (PI*pow(radius, 2))*height);
	}else if (strcmp(option, "cone_area\n") == 0){
		printf("Enter radius: ");
		scanf("%lf", &radius);
		printf("Enter height: ");
		scanf("%lf", &height);
		printf("Surface area: %.50fu\u00B2\n", PI*radius*(radius+sqrt(pow(radius, 2) + pow(height, 2))));
	}else if (strcmp(option, "cone_vol\n") == 0){
		printf("Enter radius: ");
		scanf("%lf", &radius);
		printf("Enter height: ");
		scanf("%lf", &height);
		printf("Surface area: %.50fu\u00B3\n", (PI*pow(radius, 2)*height)/3);
	}else if (strcmp(option, "sphere_area\n") == 0){
		printf("Enter radius: ");
		scanf("%lf", &radius);
		printf("Surface area: %.50fu\u00B2\n", 4*PI*pow(radius, 2));
	}else if (strcmp(option, "sphere_vol\n") == 0){
		printf("Enter radius: ");
		scanf("%lf", &radius);
		printf("Volume: %.50fu\u00B3\n", (4/3)*PI*pow(radius, 3));
	}else{
		printf("%s: %.50f\n", option, 0.0);
	}
}
