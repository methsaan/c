#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv){
	char option[100];
 	double circumference;
 	double area;
 	double volume;
 	const double PI = 3.14159265358972;
 	double height;
	double radius;
 	printf("Options: circle_circ, circle_area, cylinder_area, cylinder_volume, cone_area, cone_vol, sphere_area, sphere_vol\nEnter your option: ");
	scanf("%s", option);
	if (strcmp(option, "circle_circ") == 0) {
		printf("Enter circumference: ");
		scanf("%lf", &circumference);
		radius = circumference/PI/2.0;
		printf("Radius: %.20g\n", radius);
	}else if (strcmp(option, "circle_area") == 0) {
		printf("Enter area: ");
		scanf("%lf", &area);
		radius = sqrt(area/PI);
		printf("radius: %f", radius);
		 _________
		V area/PI  = r
	}
}
