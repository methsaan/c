#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main(int argc, char *argv){
	int numOfData;
	scanf("%d", &numOfData);
	int data[numOfData];
	int freqPairs[numOfData*2];
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
        for (i = 0; i<numOfData; i++){
        	if (freq[i] != 0){
        		printf("%d occurs %d times\n", data[i], freq[i]);
        		freqPairs[i] = data[i];
        		printf("freqPairs[%d] = %d\n", i, freqPairs[i]);
        		freqPairs[i+1] = freq[i];
        		printf("freqPairs[%d] = %d\n", i+1, freqPairs[i+1]);
        	}
        }
        for (int b = 0; b < numOfData*2;b++){
        	printf("%d ", freqPairs[b]);
        }
        printf("\n");
        printf("freq: ");
        for (int x = 0; x < numOfData; x++){
        	printf("%d ", freq[x]);
        }
        printf("\n");
        int c, largest;
        largest = freq[0];
        for (c = 1; c < numOfData; c++){
        	if (largest < freq[c]){
        		largest = freq[c];
        	}
        }
        printf("Mode: %d\n", freqPairs[largest+1]);
}
