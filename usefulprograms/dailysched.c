#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]) {
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
	if ((timea[0] == '0') && (timea[1]-'0' == '5' && (timea[3] == '4' || timea[3] == '3'))) {
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
		const char *studytypes[9] = {"Math\n", "Programming\n", "Geography\n", "History\n", "English\n", "Sinhala\n", "Buddhism\n", "Government\n", "Economics\n"};
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
	system("clear");
	printf("Today is %s, %s %d, %d, %s.\n", days_of_week[dayx], months[tm.tm_mon], tm.tm_mday, tm.tm_year+1900, __TIME__);
	char *pdbr[2] = {"PDBR1", "PDBR2"};
	if (dayy == 0) {
		printf("Today you are following schedule %s, FAIL%d or %s\n", (randnum2==0 ? "SUN1" : "SUN2"), randnum2+1, pdbr[randnum]);
	}else if (dayy == 4) {
		printf("Today you are following schedule %s, FAIL%d or %s\n", (randnum2==0 ? "MUS1" : "MUS2"), randnum2+1, pdbr[randnum]);
	}else if (dayy == 6) {
		printf("Today you are following schedule %s, FAIL%d or %s\n", (randnum2==0 ? "SAT1" : "SAT2"), randnum2+1, pdbr[randnum]);
	}else if (dayy == 1) {
		printf("Today you are following schedule %s, FAIL%d or %s\n", (randnum2==0 ? "SWIM1" : "SWIM2"), randnum2+1, pdbr[randnum]);
	}else {
		int day_array[] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
		printf("Today you are following schedule %d, FAIL%d or %s\n", day_array[randday], randnum2+1, pdbr[randnum]);
	}
	printf("Study subject: %s %s %s %s\n", study1, study2, study3, study4);
	fclose(fp);
	if ((timea[0] == '0') && (timea[1]-'0' == '5' && (timea[3] == '4' || timea[3] == '3'))) {
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
	FILE *fp2 = fopen("schedfile2", "r");
	char *fail2list[6];
	printf("fdfdefds\n\n");
	fscanf(fp2, "%s", fail2list[0]);
	fscanf(fp2, "%s", fail2list[1]);
	fscanf(fp2, "%s", fail2list[2]);
	fscanf(fp2, "%s", fail2list[3]);
	fscanf(fp2, "%s", fail2list[4]);
	fscanf(fp2, "%s", fail2list[5]);
	printf("__________________________________________________________________________________________________________________________________________________________________________________________\n");
	printf("| REGULAR SCHEDULE     Wake up 5:10 AM      Sleep 8:40-9:30 PM        Workout:      Push ups:   3 sets of 12    Squats:   3 sets of 25    Plank: 1:15 min   |     FAIL1  (timed)|\n");
	printf("|___________________________________________________________________________________________________________________________________________________________|___________________|\n");
	printf("|_________1_________|_________3_________|_______MUS1_______|_______SAT1_______|_______SUN1_____|______PDBR1______|_____SWIM1_______|                        |5-7:00| PA, PP, C  |\n");
	printf("|        PA         |     JS/Go/Java    |        PA        |       PA         |       HW       |       PA        |       PA        |                        |7-9:00| D, MT, B   |\n");
	printf("|   Python/JS/Bash  |        PA         |        FT        |    C/C++/Java    |    Python/JS   |    Breakfast    |    Breakfast    |                        |9-11:00|ST, (B/C++)|\n");
	printf("|        MT         |        MT         |        MT        |      Bash        |       PA       |     OA/C++      |    OA/Swimming  |                        |11-12:00|  Lunch   |\n");
	printf("|    Breakfast      |        FT         |       Study      |     Breakfast    |     Golang     |      Study      |    Java/JS      |                        |12-1:00|    C/HW   |\n");
	printf("|     School        |     Breakfast     |    Breakfast     |     Python/Go    |    Breakfast   |       Java      |     FT / D      |                        |1-4:00|(Java/PP)+FT|\n");
	printf("|      Lunch        |      School       |   School/Study   |     JavaScript   |       PP       |        PA       |       PA        |                        |4-5:30| ST, PA/C++ |\n");
	printf("|       PP          |       Lunch       |      Lunch       |        D         |       PA       |        PP       |       PP        |                        |5:30-7:30|  PP + D |\n");
	printf("|       HW          |        HW         |      HW + C      |      Lunch       |       D        |      Lunch      |     Lunch       |                        |7:30-8:00|    MT   |\n");
	printf("|       PA          |        PP         |        PA        |       PP         |      Lunch     |        MT       |     Tennis      |                        |8-10:00|PA/D,Dinner|\n");
	printf("|      Study        |        PA         |        PP        |       PA         |       MT       |         D       |       ST        |                        |10-0:00|MT,ST,Sleep|\n");
	printf("|        D          |         D         |     Music Class  |       HW         |     Study      |      Python     |       MT        |                        |_______|___________|\n");
	printf("|     Dinner        |       Study       |      Dinner      |       Study      |      PP        |        FT       |      Bash       |                        |                   |\n");
	printf("|     Sleep         |      Dinner       |         D        |       Dinner     |       C        |      Dinner     |     Dinner      |                        |                   |\n");
	printf("|                   |      Sleep        |      Sleep       |        MT        |     Dinner     |      Sleep      |      Sleep      |                        |                   |\n");
	printf("|                   |                   |                  |      Sleep       |      Sleep     |                 |                 |                        |                   |\n");
	printf("|                   |                   |                  |                  |                |                 |                 |                        |                   |\n");
	printf("|___________________|___________________|__________________|__________________|________________|_________________|_________________|________________________|___________________|_\n");
	printf("|                                TIMED SCHEDULE              wake up 5:10 AM         RULE: Cannot do an activity more than half way through next activity    | FAIL2  (regular)   |\n");
	printf("|____________________________________________________________________________________________________________________________________________________________|____________________|\n");
	printf("|         2         |         4         |       MUS2       |       SAT2       |      SUN2      |      PDBR2      |      SWIM2      |                         |                    |\n");
	printf("|___________________|___________________|__________________|__________________|________________|_________________|_________________|                         |        %s          |\n", fail2list[2]);
	printf("|5:40|   C/C++      |5:40|     PA       |5:40|     D       |5:40|    PA       |5:40| Python/JS |5:10|    PA      |5:10|    PA      |                         |        %s          |\n", fail2list[3]);
	printf("|6:15|    PA        |6:20|    Study     |6:10|    Study    |6:20|  Breakfast  |6:40|    D      |5:40| Breakfast  |5:40| Breakfast  |                         |OP  Go/JS/Bash      |\n");
	printf("|6:45|  Study       |6:40|     D        |6:30|    PA       |6:50|  Program    |7:30|   MT      |6:05| OA/PP/PR   |6:05|  OA/C/C++  |                         |        %s          |\n", fail2list[0]);
	printf("|7:00| Breakfast    |7:00|  Breakfast   |7:00|  Breakfast  |7:20|    Study    |8:10| Breakfast |9:00|    MT      |9:00|OA/Swim/Bash|                         |        %s          |\n", fail2list[4]);
	printf("|7:15|   School     |7:15|   School     |7:12|School/Study |8:20|    PA       |8:40|    PP     |10:00|  Python   |11:00|   PA      |                         |OP    Python        |\n");
	printf("|4:00|   Lunch      |4:00|   Lunch      |4:00|   Lunch     |9:20|    PP       |10:00| Java/Go  |10:45|   PA      |11:40|  Lunch    |                         |        %s          |\n", fail2list[5]);
	printf("|4:30|     HW       |4:30|     HW       |4:35|    PP       |10:20|    D       |10:50|   PA     |11:15|  JS/C++   |12:40|    D      |                         |        %s          |\n", fail2list[1]);
	printf("|5:30|     PP       |5:15|     PP       |5:35|    PA       |11:00|   FT       |11:30| Lunch    |11:40|  Lunch    |1:45|  Tennis    |                         |OP  Java/C/C++      |\n");
	printf("|6:30|     PA       |6:30|     PA       |6:05|    HW       |11:30|   PP       |12:30| Python/JS|12:30|   PP      |2:40| JS/Python  |                         |                    |\n");
	printf("|7:10|     MT       |7:15|     MT       |6:30| Music Class |12:30|  Lunch     |2:30|  C/C++    |1:20|     D      |3:40|  Bash      |                         |    Dinner/Sleep    |\n");
	printf("|7:40|   Python     |7:45|   Dinner     |8:30|    MT       |1:50|    MT       |4:30|   Bash    |1:50|    FT      |4:40| Go/Java    |                         |                    |\n");
	printf("|8:10|     D        |8:40|   Sleep      |8:50|  Dinner     |2:50|  HW/FT      |5:30|    FT     |2:50|    JS      |5:40|   PP       |                         |                    |\n");
	printf("|8:40|   Dinner     |    |              |9:30|   Sleep     |5:50|     D       |7:00|    HW     |3:50|  Program   |6:40|   MT       |                         |                    |\n");
	printf("|9:10|   Sleep      |____|______________|____|_____________|6:50|  Dinner     |8:00|  Dinner   |4:50|    FT      |7:10|   ST       |                         |                    |\n");
	printf("|____|______________|                                      |8:00|  Sleep      |8:50|  Sleep    |5:50|     C      |7:50|   Dinner   |                         |                    |\n");
	printf("Codes:                                                     |    |             |    |           |6:50|   Study    |8:40|  Sleep     |                         |____________________|\n");
	printf("                                                           |    |             |    |           |7:50| FT+Dinner  |____|____________|_________________________|                     \n");
	printf("PA = Physical activity          B = Breakfast              |    |             |____|___________|8:40|  Sleep     |                                                                          \n");
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
