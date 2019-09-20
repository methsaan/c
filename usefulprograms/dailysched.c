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
		const char *studytypes[19] = {"Trignometry\n", "Algebra\n", "Computer hacking\n", "Astronomy\n", "Mixtures\n", "Human Body\n", "Structures\n", "Country, City, Province/State Facts\n", "Ancient Civilizations\n", "English writing\n", "English reading\n", "French writing\n", "French reading\n", "Sinhala reading\n", "Sinhala writing\n", "Buddha's teachings\n", "Life of the Buddha\n", "Government\n", "Economics terms\n"};
		fprintf(fpw, "%s\n", studytypes[rand()%19]);
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
	printf("__________________________________________________________________________________________________________________________________________________________________________________________\n");
	printf("| REGULAR SCHEDULE     Wake up 4:40 AM      Sleep 8:40 PM         Workout:      Push ups:   3 sets of 10    Squats:   3 sets of 20    Plank: 1 min                   |     FAIL1         |\n");
	printf("|____________________________________________________________________________________________________________________________________________________________________|___________________|\n");
	printf("|_________1_________|_________3_________|_______MUS1_______|_______SAT1_______|______SUN1______|______PDBR1______|_____PDBR3_______|_____PDBR5_____|______PDBR7______|5-12:00AM __1___   |\n");
	printf("|    Python/JS      |      Go/Java      |    Study + D    |(PA+Breakfast+OA)/PA|      PA       |       PA        |       PA        |      PA       |       PA        |            C      |\n");
	printf("|        PA         |        MT         |        PA        |   C / Breakfast |(Breakfast+OA)/FT|    Breakfast    |    Breakfast    |   Breakfast   |    Breakfast    |           C++     |\n");
	printf("|        MT         |        PA         |        MT        |       C++        |  Java/Python   |     OA/C++      |    OA/Swimming  |       C       |   Swimming/OA   |2-3:00PM  __2___   |\n");
	printf("|       Bash        |       Java        |         C        |       Go         |    JS + MT     |      Study      |    Java/JS      |    MT + OA    |     C/JS        |           Java    |\n");
	printf("|    Breakfast      |     Breakfast     |    Breakfast     |      Study       |       D        |       Java      |     FT / D      |       FT      |       D         |            JS     |\n");
	printf("|     School        |      School       |      School      |      Lunch       |    Lunch       |        PA       |       PA        |       ST      |      PP         |3-4:00PM  __3___   |\n");
	printf("|      Lunch        |       Lunch       |      Lunch       |        D         |     Study      |        PP       |       PP        |       MT      |      Lunch      |          Python   |\n");
	printf("|       HW          |   Study + HW      |        HW        |        FT        |      FT        |      Lunch      |     Lunch       |     Lunch     |    Tennis       |           C++     |\n");
	printf("|       PP          |        PP         |        PA        | (HW/MT) / (HW+MT)|    HW/PP       |        MT       |     Tennis      |      Bash     |      FT         |4-6:00PM  __4___   |\n");
	printf("|     Study + D     |        JS         |        PP        |        PA        |     PP/FT      |         D       |       ST        |       D       |      PA         |     PA+PP+D+ST+MT |\n");
	printf("|       PA          |        PA         |     Music Class  |        PP        |      PA        |      Python     |       MT        |      PA       |      ST         |           C++     |\n");
	printf("|       FT          |      FT + D       |        FT        |        FT        |      Java      |        FT       |      Bash       |      PP       |      C++        |6-8:00PM  __5___   |\n");
	printf("|     Dinner        |      Dinner       |      Dinner      |      Dinner      |   Dinner       |      Dinner     |     Dinner      |  Music Class  |      MT         |           C++     |\n");
	printf("|     Sleep         |      Sleep        |      Sleep       |      Sleep       |   Sleep        |      Sleep      |      Sleep      |    Dinner     |    Dinner       |         Bash/Go   |\n");
	printf("|                   |                   |                  |                  |                |                 |                 |      Go       |    Sleep        |8-11:00PM __6___   |\n");
	printf("|                   |                   |                  |                  |                |                 |                 |    Sleep      |                 |     Dinner + Sleep|\n");
	printf("|___________________|___________________|__________________|__________________|________________|_________________|_________________|_______________|_________________|___________________|_\n");
	printf("|                                                             TIMED SCHEDULE            Wake up 4:40 AM                                                               |      FAIL2         |\n");
	printf("|_____________________________________________________________________________________________________________________________________________________________________|____________________|\n");
	printf("|         2         |         4         |       MUS2       |       SAT2       |      SUN2      |      PDBR2      |      PDBR4      |     PDBR6      |    PDBR8        |5-12:00AM  __1___   |\n");
	printf("|___________________|___________________|__________________|__________________|________________|_________________|_________________|________________|_________________|        Bash/Go/ST  |\n");
	printf("|5:10|   C/C++      |5:10|   C/Java     |5:10|   Python    |5:10|    PA       |5:10|   PA      |5:10|    PA      |5:10|    PA      |5:10|   PA      |5:10|    PA      |             C      |\n");
	printf("|5:50|    PA        |6:00|    Study     |5:50|    Study    |5:40|  Breakfast  |5:40| Breakfast |5:40| Breakfast  |5:40| Breakfast  |5:40| Breakfast |5:40| Breakfast  |2-3:00PM   __2___   |\n");
	printf("|6:20|  Study       |6:30|     D        |6:05|    PA       |6:05|OA+Program+ST|6:05|OA+ST/Swim |6:05| OA/PP/PR   |6:05|  OA/C/C++  |6:05|  OA/Java  |6:05|  OA/Python |            C++     |\n");
	printf("|6:50| Breakfast    |6:50|  Breakfast   |6:35|    MT       |9:20|    FT       |9:00|  Swim/C++ |9:00|    MT      |9:00|OA/Swim/Bash|9:30|    MT     |9:00|OA/Swim/Bash|            Java    |\n");
	printf("|7:10|   School     |7:12|   School     |6:50|  Breakfast  |9:50|    C        |11:00|   PA     |10:00|  Python   |11:00|   PA      |10:00|   PP     |11:00|   ST      |3-4:00PM   __3___   |\n");
	printf("|4:00|   Lunch      |4:20|     PA       |7:12|   School    |10:30|   C++      |11:40|  Lunch   |10:45|   PA      |11:40|  Lunch    |11:00|   C      |11:40|  Lunch    |            JS      |\n");
	printf("|4:30|     HW       |4:50|   Lunch      |4:20|  HW+Lunch   |11:10|   PA       |1:00|    MT     |11:15|  JS/C++   |12:40|    D      |11:40| Lunch    |12:40|    D      |             C      |\n");
	printf("|5:00|     PP       |5:25|     HW       |4:50|    PP       |11:40| Lunch      |1:40|  Java/C++ |11:40|  Lunch    |1:45|  Tennis    |12:40|   ST     |1:45|  Tennis    |4-6:00PM   __4___   |\n");
	printf("|6:00|     PA       |6:15|     PP       |5:25|    PA       |1:00|    FT       |3:00|Py./Bash/Go|12:30|   PP      |2:40| JS/Python  |1:40|  Python   |2:40|    JS      |      PA+PP+D+ST+MT |\n");
	printf("|6:40|     MT       |7:15|     PA       |5:55|     D       |1:40|   Java      |6:00|   D       |1:20|     D      |3:40|  Bash      |2:40|    PA     |3:40|    FT      |             PA     |\n");
	printf("|7:20|   Python     |7:45|     MT       |6:10| Music Class |2:40|   C/C++     |6:40|   PP      |1:50|    FT      |4:40| Go/Java    |3:10|    C      |4:40|  Program   |6-8:00PM   __5___   |\n");
	printf("|7:40|     D        |8:30|   Dinner     |8:15|  Dinner     |3:40|    PP       |7:20|Study+Java |2:50|    JS      |5:40|   PP       |4:10|    D      |5:40|    PP      |      PA+PP+D+ST+MT |\n");
	printf("|8:00|   Dinner     |8:40|   Sleep      |8:50|   Sleep     |4:40|   Python    |8:00| Dinner    |3:50|  Program   |6:40|   MT       |4:40|   C++     |6:40|    MT      |            Bash    |\n");
	printf("|8:40|   Sleep      |____|______________|____|_____________|5:40|    MT       |8:40|  Sleep    |4:50|    FT      |7:10|   ST       |6:10|Music Class|7:10|    PA      |8-11:00PM  __6___   |\n");
	printf("|____|______________|                                      |6:20|     D       |____|___________|5:50|     C      |7:50|   Dinner   |8:15|  Dinner   |7:50|  Dinner    |    Dinner + Sleep  |\n");
	printf("Codes:                                                     |7:10|    ST       |                |6:50|   Study    |8:40|  Sleep     |8:50|  Sleep    |8:40|   Sleep    |____________________|\n");
	printf("                                                           |7:50|  Dinner     |                |7:50| FT+Dinner  |____|____________|____|___________|____|____________|                     \n");
	printf("PA = Physical activity          B = Breakfast              |8:40|   Sleep     |                |8:40|  Sleep     |                                                                          \n");
	printf("OA = Outdoor activity           PP = Piano practical       |____|_____________|                |____|____________|                                                                          \n");
	printf("PR = program\t\t\tST = Study\n");
	printf("MT = Music theory\t\t");
	printf("HW = Homework\n");
	printf("FT = Free time\t\t\t");
	printf("/ = do either one\n");
	printf("+ = do both in any order\n\n");
	printf("Schedules:\n\n");
	printf("PDBR1/2: Free\t\t\t");
	printf("PDBR3/4: Tennis\t\t\t");
	printf("PDBR5/6: Music\t\t\t");
	printf("PDBR7/8: Swimming\n");
}
