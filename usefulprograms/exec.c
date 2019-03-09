#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv) {
	FILE *fp;
	FILE *fp2;
	char code[500];
	char origCode[500];
	char mainCode[1000];
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
	int mainCodeIdx = 0;
	while (strcmp(code, "return 0;\n") != 0) {
		fp = fopen("execfile.c", "w+");
		printf("Enter code: ");
		fgets(code, 500, stdin);
		int hasDeclaration = 0;
		for (int x = 0; x < sizeof(code)/sizeof(*code); x++) {
			if (code[x] == '=') {
				hasDeclaration++;
				break;
			}
		}
		for (int x = 0; code[x] != '\0'; x++) {
			mainCode[mainCodeIdx] = code[x];
			mainCodeIdx++;
		}
		fprintf(fp, "#include <stdio.h>\n");
		fprintf(fp, "#include <stdlib.h>\n");
		fprintf(fp, "#include <math.h>\n");
		fprintf(fp, "#include <string.h>\n\n");
		fprintf(fp, "int main(int argc, char *argv) {\n");
		for (int x = 0; x < mainCodeIdx; x++) {
			fprintf(fp, "%c", mainCode[x]);
		}
		fprintf(fp, "}\n");
		fclose(fp);
		system("gcc execfile.c -lm -o a.out");
		system("./a.out");
	}
}
