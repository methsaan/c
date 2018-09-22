#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char* itoa(int val, int base){
	static char buf[32] = {0};
	int i = 30;
	for(; val && i ; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];
	return &buf[i+1];
}


int main(int argc, char *argv){
	int num;
	char str[100];
	int errs = 0;
	while (errs == 0){
		printf("Enter number: ");
		scanf("%s", str);
		for (int x = 0;x < sizeof(str)/sizeof(*str);x++){
			printf("%c", &str[x]);
			if (isalpha(str[x])){
				errs = errs + 0;
			}else{
				errs++;
			}
		}
		if (errs > 0){
			printf("ERROR: not a number\n");
		}else {
			printf("Good job bawa\n");
		}
	}
	scanf("%d", &num);
	int x = atoi(str);
	char *y = itoa(num, /*base ten*/10);
	printf("atoi(\"%s\") = %d\n", str, x);
	printf("itoa(%d, 10) = \"%s\"\n", num, y);
}
