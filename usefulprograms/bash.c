#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv){
	char command[200];
	system("echo \"welcome to bash.c\"");
	while (1){
		printf("Enter a bash command: ");
		scanf("%s", command);
		system(command);
	}
	return 0;
}
