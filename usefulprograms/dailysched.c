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
	if ((timea[0] == '1') && (timea[1] == '8')) {
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
	dayy = 2;
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
	}else if (dayy == 4) {
		printf("Today you are following schedule %s or %s\n", (randnum2==0 ? "MUS1" : "MUS2"), pdbr[randnum]);
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
	printf("|____BREAKFAST____|__BREAKFAST____|_______PA________|_______PA_________|________PA_________|_________C__________|_________C_________|______Go/Python____|\n");
	printf("|______C++________|_______C_______|____BREAKFAST____|BREAKFAST_+_BANANA|_____BREAKFAST_____|________C++_________|______Breakfast____|______Breakfast____|\n");
	printf("|_______PA________|_____FR/S______|_____JAVA/GO_____|_______PP_________|_____C++/Java/c____|_____SWIMMING_______|______Tennis/ft____|______Tennis/ft____|\n");
	printf("|______MATH_______|_____D/SB______|_______R1________|______JAVA________|________PP_________|____Laundry/MT______|________Java_______|_________C++_______|\n");
	printf("|__SCHOOL/LUNCH___|__SCHOOL/LUNCH_|_____SCHOOL______|_____SCHOOL_______|_____FT_+ BANANA___|_____LUNCH/Java_____|_________C++_______|________JS/C_______|\n");
	printf("|_____GOLANG______|____JS/GO______|_______R2________|______PYTHON______|_______HW/FT_______|_______TENNIS_______|_________PA________|__________PA_______|\n");
	printf("|_____PYTHON______|_____R1________|______Bash_______|_______R2_________|_________D_________|_________Go_________|_________PP________|_______Lunch_______|\n");
	printf("|______R1/R2______|__FT_+_BANANA__|_SINH/R4_+ BANANA|____HW_+_PA_______|________MT_________|_________PP_________|________Lunch______|__________D________|\n");
	printf("|_______HW________|______D________|_______MT________|____MUSIC_CLASS___|_________R1________|_________PA_________|_______D/Python____|_________MT________|\n");
	printf("|_______PP________|_____PP________|_______PP________|_____DINNER_______|________R2_________|_______DINNER_______|_________C++_______|_________PP________|\n");
	printf("|______D/MT_______|______PA_______|_______FT________|_______D__________|________R3_________|_______SLEEP________|__________Go_______|_________S_________|\n");
	printf("|____FT_+_BANANA__|______MT_______|_______D_________|______SLEEP_______|________R4_________|____________________|___________B_______|_______R3/R2_______|\n");
	printf("|___PA/DINNER_____|___DINNER______|_____DINNER______|__________________|________PA_________|____________________|________DINNER_____|______Bash/C_______|\n");
	printf("|_____SLEEP_______|____SLEEP______|_____SLEEP_______|__________________|_______DINNER______|____________________|________SLEEP______|___________________|\n");
	printf("|_________________|_______________|_________________|__________________|_______SLEEP_______|____________________|___________________|___________________|\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("_________________________________________________________________________________________________________________________________________________________\n");
	printf("|                                                            TIMED SCHEDULE                 Wake up 5:20 AM                                             |\n"); 
	printf("|_______________________________________________________________________________________________________________________________________________________|\n");
	printf("|________4________|________5________|________6________|_______MUS2_______|_______SAT2_______|_______SUN2_______|_______PDBR3_______|_______PDBR4________|\n");
	printf("|5:50____PA_______|5:50____PA_______|5:50_C/Python/Go_|__________________|__________________|__________________|___________________|____________________|\n");
	printf("|6:10__Breakfast__|6:10__3_Bananas__|6:40__Breakfast__|__________________|__________________|__________________|___________________|____________________|\n");
	printf("|6:30____Java_____|6:25__Breakfast__|7:00____Pack_____|__________________|__________________|__________________|___________________|____________________|\n");
	printf("|6:50___Banana____|6:45_____FT______|7:12___School____|__________________|__________________|__________________|___________________|____________________|\n");
	printf("|6:55___Pack______|7:05____Pack_____|3:55___Shower____|__________________|__________________|__________________|___________________|____________________|\n");
	printf("|7:00_____D_______|7:10___SCHOOL____|4:15_____PA______|__________________|__________________|__________________|___________________|____________________|\n");
	printf("|7:12___SCHOOL____|3:55___Shower____|4:35____Lunch____|__________________|__________________|__________________|___________________|____________________|\n");
	printf("|4:45_____Go______|4:15___LUNCH_____|5:00__4_bananas__|__________________|__________________|__________________|___________________|____________________|\n");
	printf("|5:10_____PA______|4:50___JS/C++____|5:30_____PP______|__________________|__________________|__________________|___________________|____________________|\n");
	printf("|5:30____Egg______|5:20___French____|6:15_____D_______|__________________|__________________|__________________|___________________|____________________|\n");
	printf("|5:50____Java_____|5:40____Go_______|_________________|__________________|__________________|__________________|___________________|____________________|\n");
	printf("|6:15_____PP______|6:20____PP_______|_________________|__________________|__________________|__________________|___________________|____________________|\n");
	printf("|7:00___Dinner____|6:55____MT_______|_________________|__________________|__________________|__________________|___________________|____________________|\n");
	printf("|7:45___Sleep_____|7:25___DINNER____|_________________|__________________|__________________|__________________|___________________|____________________|\n");
	printf("|_________________|8:10___Sleep_____|_________________|__________________|__________________|__________________|___________________|____________________|\n");
}
