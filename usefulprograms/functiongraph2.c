#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char function[20];
	printf("Enter function to graph: ");
	fgets(function, 20, stdin);
	FILE *fp = fopen("functionvariable2.c", "w");
	fprintf(fp, "#include <math.h>\n");
	fprintf(fp, "#include <stdio.h>\n");
	fprintf(fp, "#include <stdlib.h>\n\n");
	fprintf(fp, "int main(int argc, char *argv[]) {\n");
	fprintf(fp, "\tsystem(\"clear\");\n");
	fprintf(fp, "\tfor (int x = 0; x < 40; x++) {\n");
	fprintf(fp, "\t\tint %s;\n", function);
	fprintf(fp, "\t\tif (y < 46 && y > 0 && x < 46) {\n");
	fprintf(fp, "\t\t\tprintf(\"\\033[%%d;%%dHx\", y+23, (46-x)+23);\n");
	fprintf(fp, "\t\t}\n");
	fprintf(fp, "\t}\n");
	fprintf(fp, "}");
	fclose(fp);
	system("gcc functionvariable2.c -lm -o a.out");
	system("./a.out");
	system("gcc functiongraph2.c");
}
