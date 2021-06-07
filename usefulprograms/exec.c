#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv) {
	FILE *fp;
	char inputCode[50];
	char code[1500];
	int codeIdx = 0;
	int lineLengths[50];
	int lineIdx = 0;

	while (strcmp(code, "return 0;\n") != 0) {
		fp = fopen("execfile.c", "w");
		printf("Enter command: ");
		fgets(inputCode, 50, stdin);
		for (int x = 0; inputCode[x-1] != '\n'; x++) {
			code[codeIdx] = inputCode[x];
			codeIdx++;
		}
		lineLengths[lineIdx] = codeIdx;
		lineIdx++;
		for (int x = 0; x < 50; x++) {
			inputCode[x] = '\0';
		}
		fprintf(fp, "#include <stdio.h>\n");
		fprintf(fp, "#include <stdlib.h>\n");
		fprintf(fp, "#include <math.h>\n");
		fprintf(fp, "#include <string.h>\n");
		fprintf(fp, "#include <stdbool.h>\n");
		fprintf(fp, "#include <ctype.h>\n\n");
		fprintf(fp, "int main(int argc, char *argv) {\n");
		for (int x = 0; x < codeIdx; x++) {
			fprintf(fp, "%c", code[x]);
		}
		fprintf(fp, "}\n");
		fclose(fp);
		// access execrun.h header
		system("gcc execrun.c");
		system("./a.out");
		system("cat errors.txt");
	}
	system("gcc exec.c");
}
