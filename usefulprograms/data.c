#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<unistd.h>

int numOfData = 45;
void pushZerosToEnd(int arr[], int n){
	int count = 0;
	for (int i = 0; i < n; i++){
		if (arr[i] != 0){
			arr[count++] = arr[i];
		}
	}
	while (count < n){
		arr[count++] = 0;
	}
}
int main(int argv, char *argc){
	char type[20];
	printf("Enter average, median, mode or range: ");
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
	printf("Your data: ");
	for (int x = 0; x < numOfData;x++){
		printf("%d ", data[x]);
	}
	printf("\n");
	if (strcmp(type, "average") == 0){
		double sum = 0.00;
		for (int x = 0; x < numOfData; x++){
			sum += data[x];
		}
		printf("Average: %g\n", sum/numOfData);
	}else if(strcmp(type, "median") == 0){
		int swapped = 0;
		int temps;
		for (int x = 0;x < numOfData; x++){
			for (int y = 0; y < numOfData; y++){
				if (data[x] < data[y]){
					temps = data[x];
					data[x] = data[y];
					data[y] = temps;
				}
			}
		}
		if (numOfData%2 == 0){
			int midsum = data[(numOfData/2)-1]+data[numOfData/2];
			double mid = midsum/2.0;
			printf("Median: %g\n", mid);
		}else {
			int a = (numOfData/2)+0.5;
			printf("Median: %d\n", data[a]);
		}
	}else if (strcmp(type, "mode") == 0){
		int n2 = numOfData;
		int i, j, count, freq[numOfData];
		for (i = 0; i < numOfData; i++){
			freq[i] = -1;
		}
		for (i = 0; i < numOfData; i++){
			count = 1;
			for (j=i+1; j<numOfData; j++){
				if (data[i] == data[j]){
					count++;
					freq[j] = 0;
				}
			}
			if (freq[i] != 0){
				freq[i] = count;
			}
		}
		int ii;
		int jj;
		int kk;
		for (ii = 0; ii < numOfData; ii++){
                	for (jj = ii + 1; jj < numOfData;){
                		if (data[jj] == data[ii]){
                			for (kk = jj; kk < numOfData; kk++){
                				data[kk] = data[kk + 1];
                			}
                			numOfData--;
                		}else {
                			jj++;
                		}
                	}
                }
		pushZerosToEnd(freq, n2);
		int cnt = 0;
		for (int x = 0; x < n2; x++){
			if (freq[x] != 0){
				cnt++;
			}
		}
               	int freqPairs[cnt*2];
		int q = 0;
		for (int p = 0; p < sizeof(freqPairs)/sizeof(*freqPairs); p+=2){
			freqPairs[p] = data[q];
			q++;
		}
		int s = 0;
		for (int r = 1; r < sizeof(freqPairs)/sizeof(*freqPairs); r+=2){
			freqPairs[r] = freq[s];
			s++;
		}
		int c, largest;
		largest = freq[0];
		for (c = 1; c < numOfData; c++){
			if (largest < freq[c]){
				largest = freq[c];
			}
		}
		int FoundIndex = 0; 
		for (int x = 0; x < sizeof(freqPairs)/sizeof(*freqPairs); x++){
			if (((x%2) != 0) && (freqPairs[x] == largest)){
				FoundIndex = x;
				break;
			}
		}
		printf("Mode: %d\n", freqPairs[FoundIndex-1]);
	}else if (strcmp(type, "range") == 0){
		while (1) {
			int swapped = 0;
			for (int x = 0; x < numOfData-1; x++){
				if (data[x] > data[x+1]){
					int temp = data[x];
					data[x] = temp;
					data[x+1] = temp;
					swapped = 1;
				}
			}
			if (swapped == 0){
				break;
			}
		}
		printf("Range: %d\n", data[numOfData-1]-data[0]);
	}
}
