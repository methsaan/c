#include<stdio.h>
#include<string.h>
#include<array>

int main(int argv, char *argc){
	char type[20];
	int numOfData;
	printf("Enter mean, median, mode or range: ");
	scanf("%s", type);
	printf("Enter number of data: ");
	scanf("%d", numOfData);
	int data[numOfData];
	for (int x = 0; x < numOfData; x++){
		int y;
		printf("Enter data: ");
		scanf("%d", y);
		data[x] = y;
	}
	if (type == "mean"){
		int sum = 0;
		for (int x = 0; x < numOfData; x++){
			sum += data[x];
		}
		printf("%f\n", sum/numOfData);
	}
}
