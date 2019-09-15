#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *intToStr(int num) {
	int numvar = num;
	char *ones[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen" "nineteen"};
	char *placevalues[] = {"", "ty", "hundred", "thousand", "ty thousand", "hundred thousand", "million"};
	char numchar[8];
	for (int x = 0; x < 8; x++) {
		numchar[x] = num%((int)(pow(10, 8-x)));
	}
	return numchar;
}

int main(int argc, char *argv[]) {
	printf("%s\n", intToStr(2312));
}
