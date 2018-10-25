#include<stdio.h>

int main(int argc, char *argv){
	int factors1[100];
	int factors2[100];
	int num1;
	int num2;
	int gcf;
	int len1 = 0;
	int len2 = 0;
	printf("Enter 2 numbers separated by a comma: ");
	scanf("%d, %d", &num1, &num2);
	for (int x = 1; x < (num1>num2 ? num1 : num2); x++){
		if ((double)num1/x == ((double)num1)/((double)x)){
			factors1[x] = num1/x;
			len1++;
		}
		if ((double)num2/x == ((double)num2)/((double)x)){
			factors2[x] = num2/x;
			len2++;
		}
	}
	factors1[len1] = 1;
	factors2[len2] = 2;
	len1++;
	len2++;
	for (int x = 0; x < len1; x++){
		printf("%d ", factors1[x]);
	}
	printf("\n");
	for (int x = 0; x < len2; x++){
		printf("%d ", factors2[x]);
	}
	for (int x = 0; x < (num1>num2 ? num1 : num2); x++){
		if (num1 > num2) {
			if (factors[x]
		}
	}
}
