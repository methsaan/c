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
	if ((timea[0] == '1') && (timea[1] == '3' && (timea[3] == '1' || timea[3] == '4'))) {
		FILE *fpw = fopen("schedfile", "w");
		fprintf(fpw, "%d\n", dayx);
		fprintf(fpw, "%d\n", rand()%2);
		fprintf(fpw, "%d\n", rand()%12);
		fprintf(fpw, "%d\n", rand()%2);
		const char *studytypes[11] = {"Math\n", "French\n", "Programming\n", "Science\n", "Geography\n", "History\n", "English\n", "Sinhala\n", "Buddhism\n", "Government\n", "Economics\n"};
		fprintf(fpw, "%s\n", studytypes[rand()%11]);
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
	printf("Study subject: %s\n", study);
	fclose(fp);
	if ((timea[0] == '0') && (timea[1] == '5' && (timea[3] == '3' || timea[3] == '4'))) {
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
	printf("_________________________________________________________________________________________________________________________________________________________________________________\n");
	printf("| REGULAR SCHEDULE     Wake up 5:10 AM      Sleep 8:40-9:20 PM        Workout:      Push ups:   3 sets of 12    Squats:   3 sets of 25    Plank: 1:15 min   |     FAIL1  (timed)|\n");
	printf("|___________________________________________________________________________________________________________________________________________________________|___________________|\n");
	printf("|_________1_________|_________3_________|_______MUS1_______|_______SAT1_______|_______SUN1_____|______PDBR1______|_____SWIM1_______|                        |5-7:00| PA, PP, C  |\n");
	printf("|        PA         |     JS/Go/Java    |        PA        |     Study + MT   |      HW+FT     |       PA        |       PA        |                        |7-9:00| D, MT, B   |\n");
	printf("|   Python/JS/Bash  |        PA         |        FT        |        D         |    Breakfast   |    Breakfast    |  JS/Bash/Python |                        |9-11:00|ST, (B/C++)|\n");
	printf("|        MT         |        MT         |        MT        |        FT        |       FT       |     OA/C++      |       D         |                        |11-12:00|  Lunch   |\n");
	printf("|    Breakfast      |        FT         |       Study      |     Breakfast    |    Exercise    |      Study      |    Breakfast    |                        |12-1:00|    C/HW   |\n");
	printf("|     School        |     Breakfast     |    Breakfast     |        FT        |       FT       |       Java      |     School      |                        |1-4:00|(Java/PP)+FT|\n");
	printf("|      Lunch        |      School       |   School/Study   |     Exercise     |      Lunch     |        PA       |      Lunch      |                        |4-5:30| ST, PA/C++ |\n");
	printf("|       PP          |       Lunch       |      Lunch       |        FT        |    Programming |        PP       |       PA        |                        |5:30-7:30|  PP + D |\n");
	printf("|       HW          |        HW         |      HW + C      |      Lunch       |     Guitar     |      Lunch      |       HW        |     No schedule yet    |7:30-8:00|    MT   |\n");
	printf("|       PA          |        PP         |        PA        |    Programing    |       PP       |        MT       |       PP        |                        |8-10:00|PA/D,Dinner|\n");
	printf("|      Study        |        PA         |        PP        |      Guitar      |     Dinner     |         D       |    Swimming     |                        |10-0:00|MT,ST,Sleep|\n");
	printf("|        D          |         D         |     Music Class  |       PP         |      Study     |      Python     |     Dinner      |                        |_______|___________|\n");
	printf("|     Dinner        |       Study       |      Dinner      |       Study      |       MT       |        FT       |       MT        |                        |                   |\n");
	printf("|     Sleep         |      Dinner       |         D        |       Dinner     |        D       |      Dinner     |       ST        |                        |                   |\n");
	printf("|                   |      Sleep        |      Sleep       |        MT        |     Sleep      |      Sleep      |      Sleep      |                        |                   |\n");
	printf("|                   |                   |                  |      Sleep       |                |                 |                 |                        |                   |\n");
	printf("|                   |                   |                  |                  |                |                 |                 |                        |                   |\n");
	printf("|___________________|___________________|__________________|__________________|________________|_________________|_________________|________________________|___________________|_\n");
	printf("|                                TIMED SCHEDULE              wake up 5:10 AM         RULE: Cannot do an activity more than half way through next activity    | FAIL2  (regular)   |\n");
	printf("|____________________________________________________________________________________________________________________________________________________________|____________________|\n");
	printf("|         2         |         4         |       MUS2       |       SAT2       |      SUN2      |      PDBR2      |      SWIM2      |                         |                    |\n");
	printf("|___________________|___________________|__________________|__________________|________________|_________________|_________________|                         |        %s          |\n", fail2list3);
	printf("|5:40|   C/C++      |5:40|     PA       |5:40|     D       |5:40|  D+MT       |5:40|  HW+FT    |5:10|    PA      |5:40|    PA      |                         |        %s           |\n", fail2list4);
	printf("|6:15|    PA        |6:20|    Study     |6:10|    Study    |6:20|   Study     |7:30| Breakfast |5:40| Breakfast  |6:10| C/C++/Java |                         |OP  Go/JS/Bash      |\n");
	printf("|6:45|  Study       |6:40|     D        |6:30|    PA       |6:50|    FT       |8:00|   FT      |6:05| OA/PP/PR   |6:40| Breakfast  |                         |        %s          |\n", fail2list1);
	printf("|7:00| Breakfast    |7:00|  Breakfast   |7:00|  Breakfast  |7:30| Breakfast   |8:30| Exercise  |9:00|    MT      |7:12|  School    |                         |        %s          |\n", fail2list5);
	printf("|7:15|   School     |7:15|   School     |7:12|School/Study |8:00|    FT       |12:15|   FT     |10:00|  Python   |4:10|  Lunch     |                         |OP    Python        |\n");
	printf("|4:00|   Lunch      |4:00|   Lunch      |4:00|   Lunch     |8:30|  Exercise   |12:30|  Lunch   |10:45|   PA      |4:40|    HW      |                         |        %s          |\n", fail2list6);
	printf("|4:30|     HW       |4:30|     HW       |4:35|    PP       |12:15|   FT       |1:00|  Computer |11:15|  JS/C++   |5:30|    PP      |    No schedule yet      |        %s          |\n", fail2list2);
	printf("|5:30|     PP       |5:15|     PP       |5:35|    PA       |12:30|  Lunch     |7:30|    PP     |11:40|  Lunch    |6:00|    PA      |                         |OP  Java/C/C++      |\n");
	printf("|6:30|     PA       |6:30|     PA       |6:05|    HW       |1:00| Programming |8:30|  Dinner   |12:30|   PP      |6:30|   Study    |                         |                    |\n");
	printf("|7:10|     MT       |7:15|     MT       |6:30| Music Class |6:00|  Guitar     |9:00|   Study   |1:20|     D      |7:00| Swimming   |                         |    Dinner/Sleep    |\n");
	printf("|7:40|   Python     |7:45|   Dinner     |8:30|    MT       |7:30|    PP       |9:30|    MT     |1:50|    FT      |8:40|  Dinner    |                         |                    |\n");
	printf("|8:10|     D        |8:40|   Sleep      |8:50|  Dinner     |8:30|   Dinner    |10:00|     D    |2:50|    JS      |9:10|     D      |                         |                    |\n");
	printf("|8:40|   Dinner     |    |              |9:30|   Sleep     |9:10|   Sleep     |10:25|  Sleep   |3:50|  Program   |9:25|    MT      |                         |                    |\n");
	printf("|9:10|   Sleep      |____|______________|____|_____________|____|_____________|____|___________|4:50|    FT      |9:40|  Sleep     |                         |                    |\n");
	printf("|____|______________|                                                                          |5:50|     C      |    |            |                         |                    |\n");
	printf("Codes:                                                                                         |6:50|   Study    |    |            |                         |____________________|\n");
	printf("                                                                                               |7:50| FT+Dinner  |____|____________|_________________________|                     \n");
	printf("PA = Physical activity          B = Breakfast                                                  |8:40|  Sleep     |                                                                          \n");
	printf("OA = Outdoor activity           PP = Piano practical                                           |____|____________|                                                                          \n");
	printf("PR = program\t\t\tST = Study\t\t\tOP = Optional\n");
	printf("MT = Music theory\t\t");
	printf("HW = Homework\n");
	printf("FT = Free time\t\t\t");
	printf("/ = do either one\n");
	printf("+ = do both in any order\n");
	printf(", = do both in specific order\n\n");
}
