#include <stdio.h>
#include <math.h>

int main(int argc, char *argv) {
	double x;
	double repeating;
	char repeatingstr[5];
	printf("Enter a number with repeating digits: ");
	scanf("%lf", &x);
	printf("Enter the part of the number that repeats: ");
	scanf("%lf", &repeating);
	snprintf(repeatingstr, 5, "%d", repeating);
	int repeatingstrlen = printf("%s", repeatingstr);
	printf("\n");
	double x_X_100 = (x*100);
	printf("%d\n\n", repeatingstrlen);
	printf("%f     <><><><>\n\n\n", x_X_100);
	for (int i = sizeof(repeatingstr); i < 6; i += sizeof(repeatingstr)) {
		x_X_100 += repeating * (pow(10, -i));
		printf("%f     <><><><>\n\n\n", x_X_100);
	}
	printf("%f", x_X_100);
	printf(" - %f", x);
	printf(" = %f\n", x_X_100-x);
}
