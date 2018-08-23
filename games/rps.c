#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int main(int argc, char *argv) {
	int x = (rand()%3)+1;
	char *arr1 = "sc";
	char *arr2 = "pa";
	char *arr3 = "ro";
	char arr[20] = {&arr1, &pa, &ro};
	char *CMPchoice = arr[x];
	puts(CMPchoice);
}
