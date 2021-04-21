#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char defaultType[5] = "free";
	char breaktype[9];
	strcpy(breaktype, argc >= 2 ? argv[1] : defaultType);
	system("clear");
	system("./dayTracker.py");
	system("clear");
	system("./requirementAvg.py");
	srand(time(NULL));
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int dayx = tm.tm_wday;
	char *days_of_week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	char *timea = __TIME__;
	if (((timea[0] == '0') && (timea[1] == '5' && (timea[3] == '3' || timea[3] == '4'))) || (argc == 3)) {
		FILE *fpw = fopen("schedfile", "w");
		fprintf(fpw, "%d\n", dayx);
		fprintf(fpw, "%d\n", rand()%2);
		fprintf(fpw, "%d\n", rand()%12);
		fprintf(fpw, "%d\n", rand()%2);
		fclose(fpw);
	}	
	FILE *fp = fopen("schedfile", "r");
	char one[1];
	char two[1];
	char three[2];
	char four[1];
	char study[13];
	fscanf(fp, "%s", one);
	fscanf(fp, "%s", two);
	fscanf(fp, "%s", three);
	fscanf(fp, "%s", four);
	fscanf(fp, "%s", study);
	int dayy = atoi(one);
	int randnum = atoi(two);
	int randday = atoi(three);
	int randnum2 = atoi(four);
	system("git commit -a -m 'day tracker'");
	system("git push");
	system("clear");
	printf("Today is %s, %s %d, %d, %s.\n", days_of_week[dayx], months[tm.tm_mon], tm.tm_mday, tm.tm_year+1900, __TIME__);
	int breakidx = 0;
	if (breaktype[0] == 't' /*tennis*/) {
		breakidx = 1;
	} else if (breaktype[0] == 's' /*swimming*/) {
		breakidx = 2;
	} else if (breaktype[0] == 'b' /*both*/) {
		breakidx = 3;
	} else if (breaktype[0] == 'm' /*music*/) {
		breakidx = 4;
	} else {
		breakidx = 0;
	}
	char *pdbr[5][2] = {{"PDBR1", "PDBR2"}, {"PDBR3", "PDBR4"}, {"PDBR5", "PDBR6"}, {"PDBR7", "PDBR8"}, {"PDBR9", "PDBR10"}};
	if (breaktype[0] == 'i' /*inner*/) {
		printf("Today you are following inner schedule IS\n");
	} else if (dayy == 4) {
		printf("Today you are following schedule %s, FAIL%d or %s\n", (randnum2==0 ? "MUS1" : "MUS2"), randnum2+1, pdbr[breakidx][randnum]);
	} else if (dayy == 6) {
		printf("Today you are following schedule FAIL%d or %s\n", randnum2+1, pdbr[breakidx][randnum]);
	} else if (dayy == 1) {
		printf("Today you are following schedule %s, FAIL%d or %s\n", (randnum2==0 ? "SWIM1" : "SWIM2"), randnum2+1, pdbr[breakidx][randnum]);
	} else {
		int day_array[] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
		printf("Today you are following schedule %d, FAIL%d or %s\n", day_array[randday], randnum2+1, pdbr[breakidx][randnum]);
	}
	fclose(fp);
	printf("____________________________________________________________________________________________Daily_Schedule___________________________________________________________________________________________________________________\n");
	printf("|            REGULAR SCHEDULE            Wake up 5:10 AM           Sleep 8:40-9:30 PM             Workout:  Push ups: 3 sets of 15, Squats: 3 sets of 28, Plank: 1:20 min                   |          FAIL1  (timed)       |\n");
	printf("|___________________________________________________________________________________________________________________________________________________________________________________________|_______________________________|\n");
	printf("|_________1_________|_________3_________|_______MUS1_______|______PDBR1______|_____SWIM1_______|____TENNIS1_______|______PDBR3_____|____PDBR5_____|_____PDBR7_______|_________PDBR9_________|___________1_(Wake up)_________|\n");
	printf("|        PA         |     JS/Go/Java    |        PA        |       PA        |       PA        |                  |                |              |                 |        Study          |           PA (45 min)         |\n");
	printf("|       Study       |        PA         |        FT        |    Breakfast    |  JS/Bash/Python |                  |                |              |                 |C/C++/Java/Python/sh/JS|           D (30 min)          |\n");
	printf("|        HW         |        MT         |        MT        |        C++      |       D         |                  |                |              |                 |          PA           |       C++/Java (45 min)       |\n");
	printf("|    Breakfast      |        FT         |       Study      |      Study      |    Breakfast    |                  |                |              |                 |           D           |_________2_(Breakfast)_________|\n");
	printf("|       C++         |     Breakfast     |    Breakfast     |       Java      |     School      |                  |                |              |                 |       Breakfast       |       PA / PA #2 (1 hr)       |\n");
	printf("|      School       |      School       |      School      |        PA       |      Lunch      |                  |                |              |                 |    MT (Wed. + Fri.)   |        C (1 hr 15 min)        |\n");
	printf("|      Lunch        |       Lunch       |      Lunch       |        PP       |      Study      |                  |                |              |                 | C/C++/Java/Go/Bash/JS |_______________3_______________|\n");
	printf("|       HW          |       Study       |        PA        |      Lunch      |       PA        | TENNIS + SCHOOL  |      TENNIS    |   SWIMMING   |TENNIS & SWIMMING|         PA            |           FT (1 hr)           |\n");
	printf("|       PA          |        PA         |        PP        |        MT       |       PP        |                  |                |              |                 |         HW            |          MT (45 min)          |\n");
	printf("|       MT          |        PP         |     Music Class  |        HW       |    Swimming     |                  |                |              |                 |       Lunch           |___________4_(Lunch)___________|\n");
	printf("|       Go          |         D         |      Dinner      |         D       |     Dinner      |                  |                |              |                 |         C++           |        PA / PA #2 (1 hr)      |\n");
	printf("|       PP          |       Study       |        HW        |        FT       |       MT        |                  |                |              |                 |      PP (Full)        | Python/sh/JS/Go (1 hr 15 min) |\n");
	printf("|      Dinner       |      Dinner       |         D        |      Dinner     |       HW        |                  |                |              |                 |        Bash           |________________5______________|\n");
	printf("|        D          |      Sleep        |      Sleep       |      Sleep      |      Sleep      |                  |                |              |                 |     Music Class       |       D,PP,(ST+MT) (2 hrs)    |\n");
	printf("|        C          |                   |                  |                 |                 |                  |                |              |                 |        Dinner         |        PA #2 / FT (45 min)    |\n");
	printf("|      Sleep        |                   |                  |                 |                 |                  |                |              |                 |        Sleep          |____________6_(Dinner)_________|\n");
	printf("|                   |                   |                  |                 |                 |                  |                |              |                 |                       |       ST,D,MT (1 hr 15 min)   |\n");
	printf("|                   |                   |                  |                 |                 |                  |                |              |                 |                       |              Sleep            |\n");
	printf("|___________________|___________________|__________________|_________________|_________________|__________________|________________|______________|_________________|_______________________|_______________________________|________\n");
	printf("|                                TIMED SCHEDULE                    wake up 5:10 AM                 TIME RULE: Cannot continue an activity more than 15 minutes through next activity                                                 |\n");
	printf("|____________________________________________________________________________________________________________________________________________________________________________________________________________________________________|\n");
	printf("|         2         |         4         |       MUS2       |      PDBR2      |      SWIM2      |     TENNIS2     |     PDBR4      |    PDBR6     |     PDBR8       |       PDBR10          |  FAIL2 (regular)  |          IS         |\n");
	printf("|___________________|___________________|__________________|_________________|_________________|_________________|________________|______________|_________________|_______________________|___________________|_____________________|\n");
	printf("|5:40|   Study      |5:40|     PA       |5:40|     D       |5:40|    PA      |5:40|    PA      |                 |                |              |                 |5:40|    Study         |    Breakfast      |5:10  |FT + schedule |\n");
	printf("|6:10|    PA        |6:20| Python/Bash  |6:05|    Study    |6:20| Breakfast  |6:20|  Program   |                 |                |              |                 |6:40| C++/Java/C/Bash  |___________________|6:30PM|   FT         |\n");
	printf("|6:45|    HW        |7:00|     D        |7:00|    PA       |6:50|   Study    |7:30| Breakfast  |                 |                |              |                 |7:40|     PA           |       MT          |9:20  |   Sleep      |\n");
	printf("|7:20|  Breakfast   |7:25|  Breakfast   |7:35|  Breakfast  |7:40|    PP      |8:00|  School    |                 |                |              |                 |8:20|      D           |       D           |      |              |\n");
	printf("|7:35|   Python     |8:00|   School     |8:00|   School    |9:00|    PA      |4:10|  Lunch     |                 |                |              |                 |9:00|  Breakfast       |___________________|      |              |\n");
	printf("|8:00|   School     |3:40|   Lunch      |3:40|   Lunch     |9:50|  Program   |4:40|    HW      |                 |                |              |                 |9:30| MT (Sun. + Thu.) |       PA          |      |              |\n");
	printf("|3:40|    Lunch     |4:20|     HW       |4:10|    PP       |12:00|    FT     |5:30|    PP      |                 |                |              |                 |10:00|  Python/JS/Go   |        D          |      |              |\n");
	printf("|4:10|     PP       |5:10|     PP       |5:20|    PA       |1:40|    Lunch   |6:00|    PA      |                 |      TENNIS    |   SWIMMING   |TENNIS & SWIMMING|10:30|     PA          |_______Lunch_______|      |              |\n");
	printf("|5:30|     PA       |6:30|     PA       |6:00| Music Class |2:30|     D      |6:30|   Study    | TENNIS + SCHOOL |                |              |                 |11:10|     HW          |       MT          |      |              |\n");
	printf("|6:00|      D       |7:10|     MT       |8:00|  Dinner     |3:20|    HW      |7:00| Swimming   |                 |                |              |                 |1:40|    Lunch         |       PA          |      |              |\n");
	printf("|6:30|     HW       |7:45|   Dinner     |8:30|    HW       |6:00|    FT      |8:40|  Dinner    |                 |                |              |                 |2:40|      FT          |___________________|      |              |\n");
	printf("|7:10|   Dinner     |8:20|   Study      |9:00|    MT       |7:50|   Dinner   |9:10|     D      |                 |                |              |                 |3:00|   PP (Full)      |       PA          |      |              |\n");
	printf("|7:50|     MT       |9:00|   Sleep      |9:30|   Sleep     |8:30|    MT      |9:25|    MT      |                 |                |              |                 |5:40|  FT, Music Class |       PP          |      |              |\n");
	printf("|8:20|      C       |____|______________|____|_____________|9:00|   Sleep    |9:40|  Sleep     |                 |                |              |                 |8:30|  Dinner + Sleep  |_____Dinner________|      |              |\n");
	printf("|9:00|     Go       |                                      |    |            |    |            |                 |                |              |                 |    |                  |    MT+D+Study     |      |              |\n");
	printf("|9:30|   Sleep      |                                      |    |            |    |            |                 |                |              |                 |    |                  |     Sleep         |      |              |\n");
	printf("|    |              |                                      |    |            |    |            |                 |                |              |                 |____|__________________|___________________|______|______________|\n");
	printf("|____|______________|                                      |    |            |____|____________|_________________|________________|______________|_________________|\n");
	printf("PA = Physical activity          B = Breakfast              |    |            |\n");
	printf("OA = Outdoor activity           PP = Piano practical       |____|____________| %d\n", (rand()%13)+1);
	printf("PR = program\t\t\tST = Study\t\t\tOP = Optional\t\tI = if possible\n");
	printf("MT = Music theory\t\t");
	printf("HW = Homework\n");
	printf("FT = Free time\t\t\t");
	printf("/ = do either one\n");
	printf("+ = do both in any order\n");
	printf(", = do both in specific order\n\n");
}
