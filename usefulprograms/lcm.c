#include<stdio.h>
#include<math.h>

int main(int argc, char *argv){
	int num1;
	int num2;
	char arr[100];
	printf("Enter two numbers separated by a space: ");
	scanf("%d %d", &num1, &num2);
	int lcm;
	int multiples1[55];
	int multiples2[55];
	for (int x = 1; x < 56; x++){
		multiples1[x-1] = num1*x;
		multiples2[x-1] = num2*x;
	}
	printf("Multiples of %d: ", num1);
	for (int x = 0; x < 55; x++){
		printf("%d ", multiples1[x]);
	}
	printf("\nMultiples of %d: ", num2);
	for (int x = 0; x < 55; x++){
		printf("%d ", multiples2[x]);
	}
	printf("\n");
	int status;
	for (int x = 0; x < 55; x++){
		for (int y = 0; y < 55; y++){
			if (multiples1[x] == multiples2[y]){
				lcm = multiples1[x];
				status = 1;
				break;
			}else {
				status = 0;
			}
		}
		if (status == 1){
			break;
		}
	}
	printf("LCM: %d\n", lcm);
}
