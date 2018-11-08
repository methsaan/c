#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv){
	char command[100];
	system("echo \"welcome to bash.c\"");
	while (1){
		printf("Enter a bash command: ");
		fgets(command, 100, stdin);
		fputs(command, stdout);
		system(command);
	}
	return 0;
}
