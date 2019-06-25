#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv) {
	DIR *dp;
	struct dirent *dirp;
	if (argc != 2) {
		err_quit("a single argument (the directory name) is required");
	}
	if ((dp = opendir(argv[1])) == NULL) {
		err_sys("Can't open %s", argv[1]);
	}
	if ((dirp = readdir(dp)) != NULL) {
		printf("%s\n", dirp->d_name);
	}
	closedir(dp);
	exit(0);
}
