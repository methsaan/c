#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv) {
	FILE *fp;
	FILE *fp2;
	char code[500];
	char origCode[500];
	fp2 = fopen("execfile.c" , "r");
	int c,nl=0,nc=0;
	c=getc(fp2);
	origCode[0] = c;
	int idx = 1;
	int lines = 0;
	while(c!=EOF){
		if(c=='\n')
		nl++;
		nc++;
		c=getc(fp2);
		origCode[idx] = c;
		idx++;
		if (c == '\n') {
			lines++;
		}
		
	}
	fp = fopen("execfile.c", "w+");
	while (strcmp(code, "return 0;\n") != 0) {
		printf("Enter code: ");
		fgets(code, 500, stdin);
		fprintf(fp, code);
	}
}
