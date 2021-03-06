#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv) {
	char function[50];
	printf("Enter function to graph: ");
	fgets(function, 50, stdin);
	printf("%s\n", function);
	int functionlen;
	for (functionlen = 0; functionlen < 50; functionlen++) {
		if (function[functionlen] == '\n') {
			function[functionlen] = ';';
		}
	}
	FILE *fp = fopen("functionvariable.c", "w");
	fprintf(fp, "#include <stdio.h>\n");
	fprintf(fp, "#include <stdlib.h>\n");
	fprintf(fp, "#include <math.h>\n\n");
	fprintf(fp, "struct coord {\n");
	fprintf(fp, "\tint x;\n");
	fprintf(fp, "\tint y;\n");
	fprintf(fp, "};\n\n");
	fprintf(fp, "void convertToComputer(int *x, int *y) {\n");
	fprintf(fp, "\t*x += 40;\n");
	fprintf(fp, "\t*x *= 2;\n");
	fprintf(fp, "\t*y = -(*y);\n");
	fprintf(fp, "\t*y += 40;\n");
	fprintf(fp, "}\n\n");
	fprintf(fp, "int main(int argc, char *argv) {\n");
	fprintf(fp, "\tstruct coord coords[40];\n");
	fprintf(fp, "\tfor (int x = -20; x < 20; x++) {\n");
	fprintf(fp, "\t\tint %s\n", function);
	fprintf(fp, "\t\tcoords[x+20].x = x;\n");
	fprintf(fp, "\t\tcoords[x+20].y = y;\n");
	fprintf(fp, "\t\tconvertToComputer(&coords[x+20].x, &coords[x+20].y);\n");
	fprintf(fp, "\t}\n");
	fprintf(fp, "\tfor (int i = 0; i < 40; i++) {\n");
	fprintf(fp, "\t\tsystem(\"clear\");\n");
	fprintf(fp, "\t\tprintf(\"(%%d, %%d)\\n\", coords[i].x/2-40, -(coords[i].y-40));\n");
	fprintf(fp, "\t\tfor (int j = 0; j < coords[i].y-10; j++) {\n");
	fprintf(fp, "\t\t\tprintf(\"\\n\");\n");
	fprintf(fp, "\t\t}\n");
	fprintf(fp, "\t\tfor (int j = 0; j < coords[i].x-1; j++) {\n");
	fprintf(fp, "\t\t\tprintf(\" \");\n");
	fprintf(fp, "\t\t}\n");
	fprintf(fp, "\t\tprintf(\"X\\n\");\n");
	fprintf(fp, "\t\tfor (long int j = 0; j < 4000000; j++) {\n");
	fprintf(fp, "\t\t\t;\n");
	fprintf(fp, "\t\t}\n");
	fprintf(fp, "\t}\n");
	fprintf(fp, "}\n");
	fclose(fp);
	system("gcc functionvariable.c -lm -o a.out");
	system("./a.out");
	system("gcc functiongraph.c");
}
