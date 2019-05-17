#include <stdio.h>
#include <string.h>

struct date {
	int year;
	char *month = "";
	int date;
};

int main(int argc, char *argv) {
	struct date birth;
	struct date current;
	double age;
	char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	printf("When were you born (y-m-d): ");
	scanf("%d-%s-%d", &birth.year, birth.month, &birth.date);
	printf("What is the current date (y-m-d): ");
	scanf("%d-%s-%d", &current.year, current.month, &current.date);
	int currentmon;
	int birthmon;
	for (int x = 0; x < 12; x++) {
		if (strcmp(months[x], birth.month) == 0) {
			birthmon = x;
		}
	}
	for (int x = 0; x < 12; x++) {
		if (strcmp(months[x], current.month) == 0) {
			currentmon = x;
		}
	}
	printf("%d\n", current.year);
	printf("%s\n", currentmon);
	printf("%d\n", current.date);
	printf("%d\n", birth.year);
	printf("%s\n", birthmon);
	printf("%d\n", birth.date);
}
