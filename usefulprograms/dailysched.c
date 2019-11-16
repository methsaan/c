#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char breaktype[80] = {0x0};
	strcpy(breaktype, argv[1]);
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
	if ((timea[0] == '0') && (timea[1] == '5' && (timea[3] == '1' || timea[3] == '0'))) {
		FILE *fpointer = fopen("schedfile", "r");
		char a[1];
		char b[1];
		char c[2];
		char d[1];
		char s1[20];
		char s2[20];
		char s3[20];
		char s4[20];
		fscanf(fpointer, "%s", a);
		fscanf(fpointer, "%s", b);
		fscanf(fpointer, "%s", c);
		fscanf(fpointer, "%s", d);
		fscanf(fpointer, "%s %s %s %s", s1, s2, s3, s4);
		fclose(fpointer);
		FILE *fpw = fopen("schedfile", "w");
		fprintf(fpw, "%d\n", dayx);
		fprintf(fpw, "%d\n", rand()%2);
		fprintf(fpw, "%d\n", rand()%12);
		fprintf(fpw, "%d\n", rand()%2);
		const char *studytypes[9] = {"Algebra\n", "Electronics\n", "Country locations\n", "Ancient civilizations\n", "English grammar\n", "Sinhala writing\n", "Buddha's teachings\n", "Government\n", "Economics\n"};
		if (tm.tm_mday%4 == 0) {
			fprintf(fpw, "%s\n", studytypes[rand()%9]);
		}else {
			fprintf(fpw, "%s %s %s %s\n", s1, s2, s3, s4);
		}
		fclose(fpw);
	}	
	FILE *fp = fopen("schedfile", "r");
	char one[1];
	char two[1];
	char three[2];
	char four[1];
	char study1[20];
	char study2[20];
	char study3[20];
	char study4[20];
	fscanf(fp, "%s", one);
	fscanf(fp, "%s", two);
	fscanf(fp, "%s", three);
	fscanf(fp, "%s", four);
	fscanf(fp, "%s %s %s %s", study1, study2, study3, study4);
	int dayy = atoi(one);
	int randnum = atoi(two);
	int randday = atoi(three);
	int randnum2 = atoi(four);
	system("git commit -a -m 'day tracker'");
	system("git push");
	int idx = 0;
	if (strcmp(breaktype, "free") == 0) {
		idx = 0;
	}else if (strcmp(breaktype, "tennis") == 0) {
		idx = 1;
	}else if (strcmp(breaktype, "music") == 0) {
		idx = 2;
	}else if (strcmp(breaktype, "swimming") == 0) {
		idx = 3;
	}
	system("clear");
	printf("Today is %s, %s %d, %d, %s.\n", days_of_week[dayx], months[tm.tm_mon], tm.tm_mday, tm.tm_year+1900, __TIME__);
	char *pdbr[4][2] = {{"PDBR1", "PDBR2"}, {"PDBR3", "PDBR4"}, {"PDBR5", "PDBR6"}, {"PDBR7", "PDBR8"}};
	if (dayy == 0) {
		printf("Today you are following schedule %s, FAIL%d or %s\n", (randnum2==0 ? "SUN1" : "SUN2"), randnum2+1, pdbr[idx][randnum]);
	}else if (dayy == 4) {
		printf("Today you are following schedule %s, FAIL%d or %s\n", (randnum2==0 ? "MUS1" : "MUS2"), randnum2+1, pdbr[idx][randnum]);
	}else if (dayy == 6) {
		printf("Today you are following schedule %s, FAIL%d or %s\n", (randnum2==0 ? "SAT1" : "SAT2"), randnum2+1, pdbr[idx][randnum]);
	}else {
		int day_array[] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
		printf("Today you are following schedule %d, FAIL%d or %s\n", day_array[randday], randnum2+1, pdbr[idx][randnum]);
	}
	printf("Study subject: %s %s %s %s\n", study1, study2, study3, study4);
	fclose(fp);
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
	printf("__________________________________________________________________________________________________________________________________________________________________________________________\n");
	printf("| REGULAR SCHEDULE     Wake up 4:40 AM      Sleep 8:40 PM         Workout:      Push ups:   3 sets of 10    Squats:   3 sets of 20    Plank: 1 min                   |     FAIL1  (timed)|\n");
	printf("|____________________________________________________________________________________________________________________________________________________________________|___________________|\n");
	printf("|_________1_________|_________3_________|_______MUS1_______|___SAT1__(4:10)___|___SUN1_(4:10)__|______PDBR1______|_____PDBR3_______|_____PDBR5_____|______PDBR7______|5-7:00| PA, PP, C  |\n");
	printf("|    Python/JS      |      Go/Java      |    Study + D     |       PA         |       HW       |       PA        |       PA        |      PA       |       PA        |7-9:00| D, MT, B   |\n");
	printf("|        PA         |        MT         |        PA        |     Breakfast    |    Python/JS   |    Breakfast    |    Breakfast    |   Breakfast   |    Breakfast    |9-11:00|ST, (B/C++)|\n");
	printf("|        MT         |        PA         |        MT        |    C/C++, Study  |  Exercise+B    |     OA/C++      |    OA/Swimming  |       C       |       C++       |11-12:00|  Lunch   |\n");
	printf("|       Bash        |       Java        |         C        |       Go         | Lunch,Computers|      Study      |    Java/JS      |    MT + OA    |   Python, Go    |12-1:00|    C/HW   |\n");
	printf("|    Breakfast      |     Breakfast     |    Breakfast     |     Tennis       |    Golang      |       Java      |     FT / D      |       FT      |       D         |1-4:00|(Java/PP)+FT|\n");
	printf("|     School        |      School       |      School      |      Lunch       |      PP        |        PA       |       PA        |       ST      |     Tennis      |4-5:30| ST, PA/C++ |\n");
	printf("|      Lunch        |       Lunch       |      Lunch       |     Swimming     |     Study      |        PP       |       PP        |       MT      |      Lunch      |5:30-7:30|  PP + D |\n");
	printf("|       HW          |   Study + HW      |        HW        |        PA        |      D         |      Lunch      |     Lunch       |     Lunch     |    Swimming     |7:30-8:00|    MT   |\n");
	printf("|       PP          |        PP         |        PA        |      Guitar      |    Dinner      |        MT       |     Tennis      |      Bash     |      FT         |8-10:00|PA/D,Dinner|\n");
	printf("|     Study + D     |        JS         |        PP        |      Dinner      |      MT        |         D       |       ST        |       D       |      PA         |10-0:00|MT,ST,Sleep|\n");
	printf("|       PA          |        PA         |     Music Class  |   Sleep (9:30)   | Sleep (<10:00) |      Python     |       MT        |      PA       |      ST         |_______|___________|\n");
	printf("|       FT          |      FT + D       |        FT        |                  |                |        FT       |      Bash       |      PP       |       PA        |                   |\n");
	printf("|     Dinner        |      Dinner       |      Dinner      |                  |                |      Dinner     |     Dinner      |  Music Class  |      MT         |                   |\n");
	printf("|     Sleep         |      Sleep        |      Sleep       |                  |                |      Sleep      |      Sleep      |    Dinner     |    Dinner       |                   |\n");
	printf("|                   |                   |                  |                  |                |                 |                 |      Go       |    Sleep        |                   |\n");
	printf("|                   |                   |                  |                  |                |                 |                 |    Sleep      |                 |                   |\n");
	printf("|___________________|___________________|__________________|__________________|________________|_________________|_________________|_______________|_________________|___________________|_\n");
	printf("|                                TIMED SCHEDULE              wake up 4:40 AM         RULE: Cannot do an activity more than half way through next activity             | FAIL2  (regular)   |\n");
	printf("|_____________________________________________________________________________________________________________________________________________________________________|____________________|\n");
	printf("|         2         |         4         |       MUS2       | SAT2 (4:10)      |      SUN2      |      PDBR2      |      PDBR4      |     PDBR6      |    PDBR8        |                    |\n");
	printf("|___________________|___________________|__________________|__________________|________________|_________________|_________________|________________|_________________|        %s          |\n", fail2list[2]);
	printf("|5:10|   C/C++      |5:10|   C/Java     |5:10|     D       |4:40|    PA       |5:10| Python/JS |5:10|    PA      |5:10|    PA      |5:10|   PA      |5:10|    PA      |        %s          |\n", fail2list[3]);
	printf("|5:50|    PA        |6:00|    Study     |5:50|    Study    |5:20|  Breakfast  |5:40|    D      |5:40| Breakfast  |5:40| Breakfast  |5:40| Breakfast |5:40| Breakfast  |OP  Go/JS/Bash      |\n");
	printf("|6:20|  Study       |6:30|     D        |6:05|    PA       |5:50|  Program    |6:10|   MT      |6:05| OA/PP/PR   |6:05|  OA/C/C++  |6:05|  OA/Java  |6:05|   Python   |        %s          |\n", fail2list[0]);
	printf("|6:50| Breakfast    |6:50|  Breakfast   |6:35|    MT       |6:20|    Study    |6:30|Exercise+B |9:00|    MT      |9:00|OA/Swim/Bash|9:30|    MT     |9:00|    Bash    |        %s          |\n", fail2list[4]);
	printf("|7:10|   School     |7:12|   School     |6:50|  Breakfast  |7:20|    PA       |12:30| Lunch    |10:00|  Python   |11:00|   PA      |10:00|   PP     |10:15|  Tennis   |OP    Python        |\n");
	printf("|4:00|   Lunch      |4:20|     PA       |7:12|   School    |8:20|    PP       |1:00| Computers |10:45|   PA      |11:40|  Lunch    |11:00|   C      |2:30|   Lunch    |        %s          |\n", fail2list[5]);
	printf("|4:30|     HW       |4:50|   Lunch      |4:10|    Lunch    |9:20|     D       |6:00|   ST      |11:15|  JS/C++   |12:40|    D      |11:40| Lunch    |3:30| Swimming   |        %s          |\n", fail2list[1]);
	printf("|5:00|     PP       |5:25|     HW       |4:40|    PP       |10:00|   FT       |6:40|   PP      |11:40|  Lunch    |1:45|  Tennis    |12:40|   ST     |4:50|     D      |OP  Java/C/C++      |\n");
	printf("|6:00|     PA       |6:15|     PP       |5:25|    PA       |10:30|Tennis/Swim |7:50|  Dinner   |12:30|   PP      |2:40| JS/Python  |1:40|  Python   |2:40|    JS      |                    |\n");
	printf("|6:40|     MT       |7:15|     PA       |5:45|    HW       |5:00|   Java      |8:40|  Sleep    |1:20|     D      |3:40|  Bash      |2:40|    PA     |3:40|    ST      |    Dinner/Sleep    |\n");
	printf("|7:20|   Python     |7:45|     MT       |6:15| Music Class |6:00|  Guitar     |    |           |1:50|    FT      |4:40| Go/Java    |3:10|    C      |5:00|  Program   |                    |\n");
	printf("|7:40|     D        |8:30|   Dinner     |8:15|  Dinner     |8:00|  Dinner     |    |           |2:50|    JS      |5:40|   PP       |4:10|    D      |5:40|    PP      |                    |\n");
	printf("|8:00|   Dinner     |8:40|   Sleep      |8:50|   Sleep     |8:30|    MT       |    |           |3:50|  Program   |6:40|   MT       |4:40|   C++     |6:40|    MT      |                    |\n");
	printf("|8:40|   Sleep      |____|______________|____|_____________|9:20|  Sleep      |    |           |4:50|    FT      |7:10|   ST       |6:10|Music Class|7:10|    PA      |                    |\n");
	printf("|____|______________|                                      |    |             |____|___________|5:50|     C      |7:50|   Dinner   |8:15|  Dinner   |7:50|  Dinner    |                    |\n");
	printf("Codes:                                                     |    |             |                |6:50|   Study    |8:40|  Sleep     |8:50|  Sleep    |8:40|   Sleep    |____________________|\n");
	printf("                                                           |    |             |                |7:50| FT+Dinner  |____|____________|____|___________|____|____________|                     \n");
	printf("PA = Physical activity          B = Breakfast              |    |             |                |8:40|  Sleep     |                                                                          \n");
	printf("OA = Outdoor activity           PP = Piano practical       |____|_____________|                |____|____________|                                                                          \n");
	printf("PR = program\t\t\tST = Study\t\t\tOP = Optional\n");
	printf("MT = Music theory\t\t");
	printf("HW = Homework\n");
	printf("FT = Free time\t\t\t");
	printf("/ = do either one\n");
	printf("+ = do both in any order\n");
	printf(", = do both in specific order\n\n");
	printf("Schedules:\n");
	printf("PDBR1/2: Free\t\t\t");
	printf("PDBR3/4: Tennis\t\t\t");
	printf("PDBR5/6: Music\t\t\t");
	printf("PDBR7/8: Swimming\n");
} 
