#include <stdio.h>
#include <string.h>

struct date {
	int year;
	int month;
	int date;
};

int main(int argc, char *argv) {
	struct date birth;
	struct date current;
	double age;
	printf("When were you born (yyyy-mm-dd): ");
	scanf("%d-%d-%d", &birth.year, &birth.month, &birth.date);
	printf("What is the current date (yyyy-mm-dd): ");
	scanf("%d-%d-%d", &current.year, &current.month, &current.date);
	printf("%d\n", current.year);
	printf("%d\n", current.month);
	printf("%d\n", current.date);
	printf("%d\n", birth.year);
	printf("%d\n", birth.month);
	printf("%d\n", birth.date);
	int days;
	int dayCarryover = 0;
	int months;
	int monthCarryover = 0;
	int years;
	int yearCarryover = 0;
	if (birth.date < current.date) {
		days = current.date - birth.date;
	}else {
		days = (current.date+30) - birth.date;
		dayCarryover = 1;
	}
	if (birth.month < current.month) {
		if (dayCarryover) {
			months = (current.month-1) - birth.month;
		}else {
			months = current.month - birth.month;
		}
	}else {
		if (dayCarryover) {
			months = ((current.month-1)+12) - birth.month;
		}else {
			months = (current.month+12) - birth.month;
		}
		monthCarryover = 1;
	}
	if (monthCarryover) {
		years = (current.year-1) - birth.year;
	}else {
		years = current.year - birth.year;
	}
	age = years + ((1.0/12.0)*months) + ((1.0/365.0)*days);
	printf("%d years, %d months, %d days\nage: %.10f\n", years, months, days, age);
}
