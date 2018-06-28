#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(int argv, char *argc){
	char type[20];
	int numOfData;
	printf("Enter mean, median, mode or range: ");
	scanf("%s", type);
	printf("Enter number of data: ");
	scanf("%d", &numOfData);
	int data[numOfData];
	for (int x = 0; x < numOfData; x++){
		int y;
		printf("Enter data: ");
		scanf("%d", &y);
		data[x] = y;
	}
	if (strcmp(type, "mean") == 0){
		double sum = 0.00;
		for (int x = 0; x < numOfData; x++){
			sum += data[x];
		}
		printf("%f\n", sum/numOfData);
	}else if (strcmp(type, "median") == 0){
		while (1){
			int swapped = 0;
			for (int x = 0; x < numOfData-1; x++){
				if (data[x] > data[x+1]){
					int temp = data[x];
					data[x] = data[x+1];
					data[x+1] = temp;
					swapped = 1;
				}
			}
			if (swapped == 0){
				break;
			}
		}
		for (int x = 0; x < numOfData;x++){
			printf("%d ", data[x]);
		}
		if (numOfData%2 == 0){
			printf("%.1f\n", (data[numOfData/2]+data[numOfData/2])/2);
		}else {
			printf("%d\n", data[floor((numOfData/2)+0.5)]);
		}
	}else if (strcmp(type, "mode") == 0){
		for (int x = 0; x < numOfData;x++){
			printf("MODE%d\n", x);
		}
	}
}
