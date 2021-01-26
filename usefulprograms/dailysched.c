#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char defaultType[5] = "free";
	char breaktype[9];
	strcpy(breaktype, argc >= 2 ? argv[1] : defaultType);
	printf("%s\n", breaktype);
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
	if (((timea[0] == '0') && (timea[1] == '5' && (timea[3] == '3' || timea[3] == '4'))) || (argc == 3)) {
		char* essentActivity[] = {"PP", "PA", "D ", "MT", "ST", "PA"};
		char* fail2list[6];
		int isUsed[] = {0, 0, 0, 0, 0, 0};
		int cnt = 0;
		for (int x = 0;; x++) {
			int randNum = rand()%6;
			if (!isUsed[randNum]) {
				fail2list[cnt++] = essentActivity[randNum];
			}
			isUsed[randNum] = 1;
			int exitCondition = 1;
			for (int y = 0; y < 6; y++) {
				if (isUsed[y] == 0) {
					exitCondition = 0;
				}
			}
			if (exitCondition) {
				break;
			}
		}
		FILE *fpw = fopen("schedfile2", "w");
		fprintf(fpw, "%s\n", fail2list[0]);
		fprintf(fpw, "%s\n", fail2list[1]);
		fprintf(fpw, "%s\n", fail2list[2]);
		fprintf(fpw, "%s\n", fail2list[3]);
		fprintf(fpw, "%s\n", fail2list[4]);
		fprintf(fpw, "%s\n", fail2list[5]);
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
	if (dayy == 0) {
		printf("Today you are following schedule FAIL%d or %s\n", randnum2+1, pdbr[breakidx][randnum]);
	} else if (breaktype[0] == 'i' /*inner*/) {
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
	FILE *fp2 = fopen("schedfile2", "r");
	char fail2list1[3];
	char fail2list2[3];
	char fail2list3[3];
	char fail2list4[3];
	char fail2list5[3];
	char fail2list6[3];
	fscanf(fp2, "%s", fail2list1);
	fscanf(fp2, "%s", fail2list2);
	fscanf(fp2, "%s", fail2list3);
	fscanf(fp2, "%s", fail2list4);
	fscanf(fp2, "%s", fail2list5);
	fscanf(fp2, "%s", fail2list6);
	printf("____________________________________________________________________________________________Daily_Schedule_______________________________________________________________________________________________________\n");
	printf("|            REGULAR SCHEDULE            Wake up 5:10 AM           Sleep 8:40-9:30 PM             Workout:  Push ups: 3 sets of 12, Squats: 3 sets of 25, Plank: 1:15 min                   |     FAIL1  (timed)|\n");
	printf("|___________________________________________________________________________________________________________________________________________________________________________________________|___________________|\n");
	printf("|_________1_________|_________3_________|_______MUS1_______|______PDBR1______|_____SWIM1_______|____TENNIS1_______|______PDBR3_____|____PDBR5_____|_____PDBR7_______|_________PDBR9_________|5-7:00| PA, PP, C  |\n");
	printf("|        PA         |     JS/Go/Java    |        PA        |       PA        |       PA        |                  |                |              |                 |        Study          |7-9:00| D, MT, B   |\n");
	printf("|       Study       |        PA         |        FT        |    Breakfast    |  JS/Bash/Python |                  |                |              |                 |C/C++/Java/Python/sh/JS|9-11:00|ST, (B/C++)|\n");
	printf("|        HW         |        MT         |        MT        |        C++      |       D         |                  |                |              |                 |          PA           |11-12:00|  Lunch   |\n");
	printf("|    Breakfast      |        FT         |       Study      |      Study      |    Breakfast    |                  |                |              |                 |           D           |12-1:00|    C/HW   |\n");
	printf("|       C++         |     Breakfast     |    Breakfast     |       Java      |     School      |                  |                |              |                 |       Breakfast       |1-4:00|(Java/PP)+FT|\n");
	printf("|      School       |      School       |      School      |        PA       |      Lunch      |                  |                |              |                 |    MT (Wed. + Fri.)   |4-5:30| ST, PA/C++ |\n");
	printf("|      Lunch        |       Lunch       |      Lunch       |        PP       |      Study      |                  |                |              |                 | C/C++/Java/Go/Bash/JS |5:30-7:30|  PP + D |\n");
	printf("|       HW          |       Study       |        PA        |      Lunch      |       PA        | TENNIS + SCHOOL  |      TENNIS    |   SWIMMING   |TENNIS & SWIMMING|         PA            |7:30-8:00|    MT   |\n");
	printf("|       PA          |        PA         |        PP        |        MT       |       PP        |                  |                |              |                 |         HW            |8-10:00|PA/D,Dinner|\n");
	printf("|       MT          |        PP         |     Music Class  |        HW       |    Swimming     |                  |                |              |                 |       Lunch           |10-0:00|MT,ST,Sleep|\n");
	printf("|       Go          |         D         |      Dinner      |         D       |     Dinner      |                  |                |              |                 |         C++           |_______|___________|\n");
	printf("|       PP          |       Study       |        HW        |        FT       |       MT        |                  |                |              |                 |      PP (Full)        |                   |\n");
	printf("|      Dinner       |      Dinner       |         D        |      Dinner     |       HW        |                  |                |              |                 |        Bash           |                   |\n");
	printf("|        D          |      Sleep        |      Sleep       |      Sleep      |      Sleep      |                  |                |              |                 |    Music Class        |                   |\n");
	printf("|        C          |                   |                  |                 |                 |                  |                |              |                 |     Dinner            |                   |\n");
	printf("|      Sleep        |                   |                  |                 |                 |                  |                |              |                 |         Sleep         |                   |\n");
	printf("|___________________|___________________|__________________|_________________|_________________|__________________|________________|______________|_________________|_______________________|___________________|\n");
	printf("|                                TIMED SCHEDULE                    wake up 5:10 AM                 TIME RULE: Cannot continue an activity more than 15 minutes through next activity        | FAIL2  (regular)  |\n");
	printf("|___________________________________________________________________________________________________________________________________________________________________________________________|___________________|_____________________\n");
	printf("|         2         |         4         |       MUS2       |      PDBR2      |      SWIM2      |     TENNIS2     |     PDBR4      |    PDBR6     |     PDBR8       |       PDBR10          |  *                |          IS         |\n");
	printf("|___________________|___________________|__________________|_________________|_________________|_________________|________________|______________|_________________|_______________________| I      %s         |_____________________|\n", fail2list3);
	printf("|5:40|   Study      |5:40|     PA       |5:40|     D       |5:40|    PA      |5:40|    PA      |                 |                |              |                 |5:40|    Study         | I      %s         |5:10| FT + schedule  |\n", fail2list4);
	printf("|6:10|    PA        |6:20| Python/Bash  |6:05|    Study    |6:20| Breakfast  |6:10| C/C++/Java |                 |                |              |                 |6:40| C++/Java/C/Bash  |OP  Go/JS/Bash     |6:30PM|   FT         |\n");
	printf("|6:45|    HW        |7:00|     D        |7:00|    PA       |6:50|   Study    |6:40| Breakfast  |                 |                |              |                 |7:40|     PA           | I      %s         |9:20|     Sleep      |\n", fail2list1);
	printf("|7:20|  Breakfast   |7:25|  Breakfast   |7:35|  Breakfast  |7:40|    PP      |7:12|  School    |                 |                |              |                 |8:20|      D           | I      %s         |____|________________|\n", fail2list5);
	printf("|7:35|   Python     |8:00|   School     |8:00|   School    |9:00|    PA      |4:10|  Lunch     |                 |                |              |                 |9:00|  Breakfast       |OP    Python       |                     |\n");
	printf("|8:00|   School     |3:40|   Lunch      |3:40|   Lunch     |9:50|  Program   |4:40|    HW      |                 |                |              |                 |9:30| MT (Sun. + Thu.) | I      %s         |                     |\n", fail2list6);
	printf("|3:40|    Lunch     |4:20|     HW       |4:10|    PP       |12:00|    FT     |5:30|    PP      |                 |                |              |                 |10:00|  Python/JS/Go   | I      %s         |                     |\n", fail2list2);
	printf("|4:10|     PP       |5:10|     PP       |5:20|    PA       |1:40|    Lunch   |6:00|    PA      |                 |      TENNIS    |   SWIMMING   |TENNIS & SWIMMING|10:30|     PA          |OP  Java/C/C++     |                     |\n");
	printf("|5:30|     PA       |6:30|     PA       |6:00| Music Class |2:30|     D      |6:30|   Study    | TENNIS + SCHOOL |                |              |                 |11:10|     HW          |                   |                     |\n");
	printf("|6:00|      D       |7:10|     MT       |8:00|  Dinner     |3:20|    HW      |7:00| Swimming   |                 |                |              |                 |1:40|    Lunch         |                   |                     |\n");
	printf("|6:30|     HW       |7:45|   Dinner     |8:30|    HW       |6:00|    FT      |8:40|  Dinner    |                 |                |              |                 |2:40|      FT          |                   |                     |\n");
	printf("|7:10|   Dinner     |8:20|   Study      |9:00|    MT       |7:50|   Dinner   |9:10|     D      |                 |                |              |                 |3:00|   PP (Full)      |                   |                     |\n");
	printf("|7:50|     MT       |9:00|   Sleep      |9:30|   Sleep     |8:30|    MT      |9:25|    MT      |                 |                |              |                 |5:40|  FT, Music Class | * Stop following  |                     |\n");
	printf("|8:20|      C       |____|______________|____|_____________|9:00|   Sleep    |9:40|  Sleep     |                 |                |              |                 |8:30|  Dinner + Sleep  | if past 11:00PM   |                     |\n");
	printf("|9:00|     Go       |                                      |    |            |    |            |                 |                |              |                 |                       |                   |                     |\n");
	printf("|9:30|   Sleep      |                                      |    |            |    |            |                 |                |              |                 |_______________________|___________________|_____________________|\n");
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
