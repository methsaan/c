#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(int argc, char *argv){
	system("clear");
	system("./dayTracker.py");
	srand(time(NULL));
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int dayx = tm.tm_wday;
	char *days_of_week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	char *timea = __TIME__;
	if ((timea[0] == '1') && (timea[1] == '0')) {
		FILE *fpw = fopen("schedfile", "w");
		fprintf(fpw, "%d\n", dayx);
		fprintf(fpw, "%d\n", rand()%4);
		fprintf(fpw, "%d\n", rand()%12);
		fprintf(fpw, "%d\n", rand()%2);
		fclose(fpw);
	}	
	FILE *fp = fopen("schedfile", "r");
	char one[200];
	char two[200];
	char three[200];
	char four[200];
	fscanf(fp, "%s", one);
	fscanf(fp, "%s", two);
	fscanf(fp, "%s", three);
	fscanf(fp, "%s", four);
	int dayy = atoi(one);
	int randnum = atoi(two);
	int randday = atoi(three);
	int randnum2 = atoi(four);
	system("git commit -a -m 'changing schedule information'");
	system("git push");
	system("clear");
	printf("Today is %s, %s %d, %d, %s.\n", days_of_week[dayx], months[tm.tm_mon], tm.tm_mday, tm.tm_year+1900, __TIME__);
	char *pdbr[4] = {"PDBR1", "PDBR2", "PDBR3", "PDBR4"};
	if (dayy == 0) {
		printf("Today you are following schedule %s or %s\n", (randnum2==0 ? "SUN1" : "SUN2"), pdbr[randnum]);
	}else if (dayy == 6) {
		printf("Today you are following schedule %s or %s\n", (randnum2==0 ? "SAT1" : "SAT2"), pdbr[randnum]);
	}else if (dayy == 4) {
		printf("Today you are following schedule %d or %s\n", (randnum2==0 ? "MUS1" : "MUS2"), pdbr[randnum]);
	}else {
		int day_array[] = {1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6};
		printf("Today you are following schedule %d or %s\n", day_array[randday], pdbr[randnum]);
	}
	fclose(fp);
	printf("_________________________________________________________________________________________________________________________________________________________\n");
	printf("|                            REGULAR SCHEDULE    Wake up 5:20 AM       Sleep 8:40 PM      Workout: Push up: 3 sets of 8, Squats: 2 sets of 20           |\n");
	printf("|_______________________________________________________________________________________________________________________________________________________|\n");
	printf("|        1        |       2       |        3        |       MUS1       |        SAT1       |        SUN1        |       PDBR1       |       PDBR3       |\n");
	printf("|_________________|_______________|_________________|__________________|___________________|____________________|___________________|___________________|\n");
	printf("|____BREAKFAST____|__BREAKFAST____|_______PA________|_______PA_________|___________________|____________________|___________________|___________________|\n");
	printf("|______C++________|_______C_______|____BREAKFAST____|_____BREAKFAST____|___________________|____________________|___________________|___________________|\n");
	printf("|_______D_________|_____FR/S______|_____JAVA/GO_____|_______PP_________|___________________|____________________|___________________|___________________|\n");
	printf("|______MATH_______|_____D/SB______|_______R1________|______JAVA________|___________________|____________________|___________________|___________________|\n");
	printf("|__SCHOOL/LUNCH___|__SCHOOL/LUNCH_|_____SCHOOL______|_____SCHOOL_______|___________________|____________________|___________________|___________________|\n");
	printf("|_____GOLANG______|____JS/GO______|_______R2________|______PYTHON______|___________________|____________________|___________________|___________________|\n");
	printf("|_____PYTHON______|_____R1________|_______R3________|_______R2_________|___________________|____________________|___________________|___________________|\n");
	printf("|______R1/R2______|_____FT________|____SINH/R4______|_______HW_________|___________________|____________________|___________________|___________________|\n");
	printf("|_______HW________|______D________|_______MT________|____MUSIC_CLASS___|___________________|____________________|___________________|___________________|\n");
	printf("|_______PP________|_____PP________|_______PP________|_____DINNER_______|___________________|____________________|___________________|___________________|\n");
	printf("|______D/MT_______|______PA_______|_______FT________|_______D__________|___________________|____________________|___________________|___________________|\n");
	printf("|_______FT________|______MT_______|_______D_________|______SLEEP_______|___________________|____________________|___________________|___________________|\n");
	printf("|___PA/DINNER_____|___DINNER______|_____DINNER______|__________________|___________________|____________________|___________________|___________________|\n");
	printf("|_____SLEEP_______|____SLEEP______|_____SLEEP_______|__________________|___________________|____________________|___________________|___________________|\n");
	printf("|_________________|_______________|_________________|__________________|___________________|____________________|___________________|___________________|\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
	printf("                                                                                                                                                           ");
}
