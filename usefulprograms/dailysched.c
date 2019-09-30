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
		FILE *fpw = fopen("schedfile", "w");
		fprintf(fpw, "%d\n", dayx);
		fprintf(fpw, "%d\n", rand()%2);
		fprintf(fpw, "%d\n", rand()%12);
		fprintf(fpw, "%d\n", rand()%2);
		const char *studytypes[22] = {"Trignometry\n", "Algebra\n", "Computer hacking\n", "Astronomy\n", "Mixtures\n", "Human body\n", "Structures\n", "Country, city, province/State facts\n", "Ancient civilizations\n", "English writing\n", "English reading\n", "French writing\n", "French reading\n", "Sinhala reading\n", "Sinhala writing\n", "Buddha's teachings\n", "Life of the Buddha\n", "Government\n", "Economics terms\n", "Astronautics\n", "Electronics\n", "Physics\n"};
		fprintf(fpw, "%s\n", studytypes[rand()%22]);
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
	int essentActivity[] = {41, 35, 24, 63, 74, 24};
	int fail2list[6];
	int isUsed[] = {0, 0, 0, 0, 0, 0};
	for (int x = 0;; x++) {
		int randNum = rand()%6;
		if (!isUsed[randNum]) {
			fail2list[x] = essentActivity[randNum];
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
		for (int x = 0; x < 6; x++) {
			printf("%d ", isUsed[x]);
		}
		printf("\n");
	}
	printf("__________________________________________________________________________________________________________________________________________________________________________________________\n");
	printf("| REGULAR SCHEDULE     Wake up 4:40 AM      Sleep 8:40 PM         Workout:      Push ups:   3 sets of 10    Squats:   3 sets of 20    Plank: 1 min                   |     FAIL1  (timed)|\n");
	printf("|____________________________________________________________________________________________________________________________________________________________________|___________________|\n");
	printf("|_________1_________|_________3_________|_______MUS1_______|_______SAT1_______|______SUN1______|______PDBR1______|_____PDBR3_______|_____PDBR5_____|______PDBR7______|5-7:00| PA, PP, C  |\n");
	printf("|    Python/JS      |      Go/Java      |    Study + D     |       PA         |       PA       |       PA        |       PA        |      PA       |       PA        |7-9:00| D, MT, B   |\n");
	printf("|        PA         |        MT         |        PA        |     Breakfast    | Breakfast + FT |    Breakfast    |    Breakfast    |   Breakfast   |    Breakfast    |9-11:00|ST, (B/C++)|\n");
	printf("|        MT         |        PA         |        MT        |      C, C++      |  Java/Python   |     OA/C++      |    OA/Swimming  |       C       |       C++       |11-12:00|  Lunch   |\n");
	printf("|       Bash        |       Java        |         C        |       Go         |    JS + MT     |      Study      |    Java/JS      |    MT + OA    |   Python, Go    |12-1:00|    C/HW   |\n");
	printf("|    Breakfast      |     Breakfast     |    Breakfast     |     Tennis       |       D        |       Java      |     FT / D      |       FT      |       D         |1-4:00|(Java/PP)+FT|\n");
	printf("|     School        |      School       |      School      |      Lunch       |    Lunch       |        PA       |       PA        |       ST      |     Tennis      |4-5:30| ST, PA/C++ |\n");
	printf("|      Lunch        |       Lunch       |      Lunch       |     Swimming     |     Study      |        PP       |       PP        |       MT      |      Lunch      |5:30-7:30|  PP + D |\n");
	printf("|       HW          |   Study + HW      |        HW        |         D        |      FT        |      Lunch      |     Lunch       |     Lunch     |    Swimming     |7:30-8:00|    MT   |\n");
	printf("|       PP          |        PP         |        PA        | (HW/MT) / (HW+MT)|    HW/PP       |        MT       |     Tennis      |      Bash     |      FT         |8:00-10:00| PA,DN+D|\n");
	printf("|     Study + D     |        JS         |        PP        |        PA        |     PP/FT      |         D       |       ST        |       D       |      PA         |10-0:00|MT,ST,Sleep|\n");
	printf("|       PA          |        PA         |     Music Class  |        PP        |      PA        |      Python     |       MT        |      PA       |      ST         |_______|___________|\n");
	printf("|       FT          |      FT + D       |        FT        |       Study      |      Java      |        FT       |      Bash       |      PP       |       PA        |                   |\n");
	printf("|     Dinner        |      Dinner       |      Dinner      |      Dinner      |   Dinner       |      Dinner     |     Dinner      |  Music Class  |      MT         |                   |\n");
	printf("|     Sleep         |      Sleep        |      Sleep       |      Sleep       |   Sleep        |      Sleep      |      Sleep      |    Dinner     |    Dinner       |                   |\n");
	printf("|                   |                   |                  |                  |                |                 |                 |      Go       |    Sleep        |                   |\n");
	printf("|                   |                   |                  |                  |                |                 |                 |    Sleep      |                 |                   |\n");
	printf("|___________________|___________________|__________________|__________________|________________|_________________|_________________|_______________|_________________|___________________|_\n");
	printf("|                                                             TIMED SCHEDULE            Wake up 4:40 AM                                                               | FAIL2  (regular)   |\n");
	printf("|_____________________________________________________________________________________________________________________________________________________________________|____________________|\n");
	printf("|         2         |         4         |       MUS2       |       SAT2       |      SUN2      |      PDBR2      |      PDBR4      |     PDBR6      |    PDBR8        |                    |\n");
	printf("|___________________|___________________|__________________|__________________|________________|_________________|_________________|________________|_________________|                    |\n");
	printf("|5:10|   C/C++      |5:10|   C/Java     |5:10|   Python    |5:10|    PA       |5:10|   PA      |5:10|    PA      |5:10|    PA      |5:10|   PA      |5:10|    PA      |                    |\n");
	printf("|5:50|    PA        |6:00|    Study     |5:50|    Study    |5:40|  Breakfast  |5:40| Breakfast |5:40| Breakfast  |5:40| Breakfast  |5:40| Breakfast |5:40| Breakfast  |                    |\n");
	printf("|6:20|  Study       |6:30|     D        |6:05|    PA       |6:05|  Program    |6:10|   ST      |6:05| OA/PP/PR   |6:05|  OA/C/C++  |6:05|  OA/Java  |6:05|   Python   |                    |\n");
	printf("|6:50| Breakfast    |6:50|  Breakfast   |6:35|    MT       |9:20|    Study    |8:00|   JS      |9:00|    MT      |9:00|OA/Swim/Bash|9:30|    MT     |9:00|    Bash    |                    |\n");
	printf("|7:10|   School     |7:12|   School     |6:50|  Breakfast  |9:50|   Java,Pack |10:00|   PA     |10:00|  Python   |11:00|   PA      |10:00|   PP     |10:15|  Tennis   |                    |\n");
	printf("|4:00|   Lunch      |4:20|     PA       |7:12|   School    |10:30|  Tennis    |11:30|  Lunch   |10:45|   PA      |11:40|  Lunch    |11:00|   C      |2:30|   Lunch    |                    |\n");
	printf("|4:30|     HW       |4:50|   Lunch      |4:20|  HW+Lunch   |2:20|    Lunch    |12:30|   MT     |11:15|  JS/C++   |12:40|    D      |11:40| Lunch    |3:30| Swimming   |                    |\n");
	printf("|5:00|     PP       |5:25|     HW       |4:50|    PP       |3:30| Swimming    |1:00|  Java/C++ |11:40|  Lunch    |1:45|  Tennis    |12:40|   ST     |4:50|     D      |                    |\n");
	printf("|6:00|     PA       |6:15|     PP       |5:25|    PA       |5:00|   Study     |2:30|Py./Bash/Go|12:30|   PP      |2:40| JS/Python  |1:40|  Python   |2:40|    JS      |                    |\n");
	printf("|6:40|     MT       |7:15|     PA       |5:55|     D       |5:40|   Java      |5:20|   D       |1:20|     D      |3:40|  Bash      |2:40|    PA     |3:40|    ST      |                    |\n");
	printf("|7:20|   Python     |7:45|     MT       |6:10| Music Class |6:20|    PA       |6:00|   PP      |1:50|    FT      |4:40| Go/Java    |3:10|    C      |5:00|  Program   |                    |\n");
	printf("|7:40|     D        |8:30|   Dinner     |8:15|  Dinner     |6:50|    PP       |7:20|Study + C  |2:50|    JS      |5:40|   PP       |4:10|    D      |5:40|    PP      |                    |\n");
	printf("|8:00|   Dinner     |8:40|   Sleep      |8:50|   Sleep     |7:50|     D       |8:00| Dinner    |3:50|  Program   |6:40|   MT       |4:40|   C++     |6:40|    MT      |                    |\n");
	printf("|8:40|   Sleep      |____|______________|____|_____________|8:20|  Dinner     |8:40|  Sleep    |4:50|    FT      |7:10|   ST       |6:10|Music Class|7:10|    PA      |                    |\n");
	printf("|____|______________|                                      |8:55|    MT       |____|___________|5:50|     C      |7:50|   Dinner   |8:15|  Dinner   |7:50|  Dinner    |                    |\n");
	printf("Codes:                                                     |9:30|  Sleep      |                |6:50|   Study    |8:40|  Sleep     |8:50|  Sleep    |8:40|   Sleep    |____________________|\n");
	printf("                                                           |    |             |                |7:50| FT+Dinner  |____|____________|____|___________|____|____________|                     \n");
	printf("PA = Physical activity          B = Breakfast              |    |             |                |8:40|  Sleep     |                                                                          \n");
	printf("OA = Outdoor activity           PP = Piano practical       |____|_____________|                |____|____________|                                                                          \n");
	printf("PR = program\t\t\tST = Study\n");
	printf("MT = Music theory\t\t");
	printf("HW = Homework\t\t\tDN = Dinner\n");
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
