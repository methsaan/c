#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int temp;
	printf("Enter number of required activities: ");
	scanf("%d", &temp);
	const int numOfReq = temp;
	printf("Enter number of optional activities: ");
	scanf("%d", &temp);
	const int numOfOp = temp;
	char *activitiesReq[numOfReq];
	char *reqTime1[numOfReq];
	char *reqTime2[numOfReq];
	int opTime[numOfOp];
	char *schedTime[2];
	printf("Enter wake up time: ");
	schedTime[0] = malloc(100 * sizeof(char));
	schedTime[1] = malloc(100 * sizeof(char));
	scanf("%99s", schedTime[0]);
	printf("Enter sleep time: ");
	scanf("%99s", schedTime[1]);
	char *activitiesOp[numOfOp];
	for (int x = 0; x < numOfOp; x++) {
		activitiesOp[x] = malloc(100 * sizeof(char));
		printf("Enter optional activity %d and number of minutes: ", x+1);
		scanf("%99s %d", activitiesOp[x], &opTime[x]);
	}
	for (int x = 0; x < numOfReq; x++) {
		activitiesReq[x] = malloc(100 * sizeof(char));
		reqTime1[x] = malloc(100 * sizeof(char));
		reqTime2[x] = malloc(100 * sizeof(char));
		printf("Enter required activity %d, beginning time and end time: ", x+1);
		scanf("%99s %99s %99s", activitiesReq[x], reqTime1[x], reqTime2[x]);
	}
	int reqTimeLen[numOfReq];
	int reqTimeLen2[numOfReq];
	int opTimeLen[numOfOp];
	int opTimeLen2[numOfOp];
	int ftMin1[numOfReq-1];
	int ftMin2[numOfReq-1];
	for (int x = 0; x < numOfReq; x++) {
		reqTimeLen[x] = ((reqTime1[x][0]-'0')*10 + (reqTime1[x][1]-'0')) * 60 + (reqTime1[x][3]-'0')*10 + (reqTime1[x][4]-'0');
		reqTimeLen2[x] = ((reqTime2[x][0]-'0')*10 + (reqTime2[x][1]-'0')) * 60 + (reqTime2[x][3]-'0')*10 + (reqTime2[x][4]-'0');
	}
	for (int x = 0; x < numOfReq-1; x++) {
		for (int y = 1; y < numOfReq; y++) {
			if (reqTimeLen[x] > reqTimeLen[y]) {
				int tempY = reqTimeLen[y];
				reqTimeLen[y] = reqTimeLen[x];
				reqTimeLen[x] = tempY;
				tempY = reqTimeLen2[y];
				reqTimeLen2[y] = reqTimeLen2[x];
				reqTimeLen2[x] = tempY;
			}
		}
	}
	for (int x = 0; x < numOfReq-1; x++) {
		ftMin1[x] = reqTimeLen2[x];
		ftMin2[x] = reqTimeLen[x+1];
	}
	int inFT = 0;
	for (int x = 0; x < numOfOp; x++) {
		while (!inFT) {
			opTimeLen[x] = (rand() % (((schedTime[1][0]-'0')*10 + (schedTime[1][1]-'0'))*60 + (schedTime[1][3]-'0')*10 + (schedTime[1][4]-'0')) - (((schedTime[0][0]-'0')*10 + (schedTime[0][1]-'0'))*60 + (schedTime[0][3]-'0')*10 + (schedTime[0][4]-'0'))) + (((schedTime[0][0]-'0')*10 + (schedTime[0][1]-'0'))*60 + (schedTime[0][3]-'0')*10 + (schedTime[0][4]-'0'));
			opTimeLen2[x] = opTimeLen[x] + opTime[x];
			for (int y = 0; y < numOfReq-1; y++) {
				if (opTimeLen[y] < ftMin1[x] || opTimeLen2[y] > ftMin2[x]) {
					inFT = 1;
				}
			}
			x++;
		}
	}
	for (int x = 0; x < sizeof(opTimeLen)/sizeof(*opTimeLen); x++) {
		printf("%d - %d\n", opTimeLen[x], opTimeLen2[x]);
	}
	for (int x = 0; x < sizeof(opTimeLen)/sizeof(*opTimeLen); x++) {
		printf("%d - %d\n", opTimeLen[x], opTimeLen2[x]);
	}
}
