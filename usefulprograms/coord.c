#include <stdio.h>
#include <math.h>

int main(int argc, char *argv){
	float start_point_x;
	float start_point_y;
	double distance;
	float a_sq_plus_b_sq;
	float angle_a;
	float remaining_angle;
	float end_point_x;
	float end_point_y;
	printf("Enter the x axis of the starting point: ");
	scanf("%lf", &start_point_x);
	printf("Enter the y axis of the starting point: ");
	scanf("%lf", &start_point_y);
	printf("Enter the distance: ");
	scanf("%lf", &distance);
	printf("Enter the angle: ");
	scanf("%lf", &angle_a);
	a_sq_plus_b_sq = distance*distance;
	float angle_b = 90-angle_a;

}
