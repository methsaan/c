#include<stdio.h>

int main(int argc, char *argv){
	int factors1[100];
	int factors2[100];
	int num1;
	int num2;
	int gcf;
	int len1 = 0;
	int len2 = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	printf("Enter 2 numbers separated by a comma: ");
	scanf("%d, %d", &num1, &num2);
	for (int x = 1; x < num1; x++){
		if ((double)num1/x == ((double)num1)/((double)x)){
			factors1[cnt1] = num1/x;
			cnt1++;
			len1++;
		}
	}
	printf("Factors of %d: ", num1);
	for (int x = 0; x < len1; x++){
		printf("%d ", factors1[x]);
	}
	printf("\n");
}
