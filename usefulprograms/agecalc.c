#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct date {
	int year;
	int month;
	int date;
};

int main(int argc, char *argv) {
	struct date birth;
	struct date current;
	double age;
	printf("Enter birth age (yyyy-mm-dd): ");
	scanf("%d-%d-%d", &birth.year, &birth.month, &birth.date);
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	current.year = tm.tm_year+1900;
	current.month = tm.tm_mon+1;
	current.date = tm.tm_mday;
	int days;
	int dayCarryover = 0;
	int months;
	int monthCarryover = 0;
	int years;
	int yearCarryover = 0;
	if (birth.date <= current.date) {
		days = current.date - birth.date;
	}else {
		days = (current.date+30) - birth.date;
		dayCarryover = 1;
	}
	if (birth.month <= current.month) {
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
	printf("%d years, %d months, %d days (approximate)\nAge: %.10f\n", years, months, days, age);
}
