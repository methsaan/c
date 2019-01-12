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
	if ((timea[0] == '0') && ((timea[1] == '4') || (timea[1] == '5') || (timea[1] == '6') || (timea[1] == '7'))) {
		FILE *fpw = fopen("schedfile", "w");
		fprintf(fpw, "%d\n", dayx);
		fprintf(fpw, "%d\n", rand()%3);
		fprintf(fpw, "%d\n", rand()%12);
		fclose(fpw);
	}	
	FILE *fp = fopen("schedfile", "r");
	if (strcmp(days_of_week[dayx], "Monday") == 0) {
		system("./weekTracker.py");
		char x;
		printf("Hit 'w' and Enter to see your progress: ");
		scanf("%c", &x);
		if (x == 'w') {
			system("cat weekTracker");
		}
		printf("Hit 's' and Enter to stop showing:\n");
		while (1) {
			x = getchar();
			if (x == 's'){
				break;
			}
		}
	}
	char one[200];
	char two[200];
	char three[200];
	fscanf(fp, "%s", one);
	fscanf(fp, "%s", two);
	fscanf(fp, "%s", three);
	int dayy = atoi(one);
	int randnum = atoi(two);
	int randday = atoi(three);
	system("git commit -a -m 'changing schedule information'");
	system("git push");
	system("clear");
	printf("Today is %s, %s %d, %d, %s.\n", days_of_week[dayx], months[tm.tm_mon], tm.tm_mday, tm.tm_year+1900, __TIME__);
	if (dayy == 0) {
		printf("Today you are following schedule %s or %s\n", (randnum==0 ? "SUN1" : "SUN2"), (randnum==0 ? "PDBR1" : "PDBR2"));
	}else if (dayy == 6) {
		printf("Today you are following schedule %s or %s\n", (randnum==0 ? "SAT1" : "SAT2"), (randnum==0 ? "PDBR1" : "PDBR2"));
	}else if (dayy == 4) {
		printf("Today you are following schedule %d or %s\n", (randnum==0 ? 7 : 8), (randnum==0 ? "PDBR1" : "PDBR2"));
	}else {
		int day_array[] = {1, 2, 3, 4, 5, 6, 9, 10, 2, 4, 6, 10};
		printf("Today you are following schedule %d or %s\n", day_array[randday], (randnum==0 ? "PDBR1" : "PDBR2"));
	}
	fclose(fp);
	printf("_____________________________________________________________________________________________________________\n");
	printf("|________??____________REGULAR_SCHEDULE_____________wake_up_5:20-6:00_sleep_8:10-8:40_________??____________|\n");
	printf("|___________________________________________________________________________________________________________|\n");
	printf("|     1    |      3     |      5     |     7      |     9      |     SAT1   |    SUN1   |       PDBR1       |\n");
	printf("|__________|____________|____________|____________|____________|____________|___________|___________________|\n");
	printf("|     D    |     SB3    |   Python   |     PA     |     D      |     R3     |    C      |      D/B/program  |\n");
	printf("|   Math   |      C     |     R1     |      C     |    C++     |     D      |  Java     |        PA         |\n");
	printf("|  Program |     PA     |     PA     |     SB     |  Program   |     PP     |    PA     |        PP         |\n");
	printf("|          |            |            |            |            |            |           |       Maths       |\n");
	printf("| AFTERNOON| AFTERNOON  | AFTERNOON  | AFTERNOON  | AFTERNOON  |  AFTERNOON | AFTERNOON |   AFTERNOON       |\n");
	printf("|__________|____________|____________|____________|____________|____________|___________|___________________|\n");
	printf("|    PP    |JavaScript/C|    SB2     |    Sinh.   |    D       |    Bash    |    ft     |        MT         |\n");
	printf("|    PA    |     MT     |    ft      |     D      |    PP      |     C++    |     D     |        ft         |\n");
	printf("|  C/Java  |     PP     |    PP      |     PP     | C/Python   |     PP     |    PP     |     French study  |\n");
	printf("|   Math   |     D      |    MT      | JavaScript |    MT      |    Sin.    |HTML/JS/C++|         ft        |\n");
	printf("|    FT    |   Program  | HTML/C++   |     PA     |    PA      |     FT     |    MT     |      Smart books  |\n");
	printf("|__________|____________|____________|____________|____________|    Java    |    FT     |         FT        |\n");
	printf("                                                               |     PP     |    Sci.   |         PP        |\n");
	printf("                 Sinhala dictation.translation 5:00pm          |     SB     |     D     |         D         |\n");
	printf("  B=Buddhism *1   | PA=physical activity| R1=read programming  |     FT     |    FT     |   Python/Java/C++/|\n");
	printf("  SB=smart books*2| MT=music theory     | R2=read classic      |     ft     |    PP     |    C/JS/HTML *3   |\n");
	printf("  FT=free time    | PP=piano practical  | R3=read sci./hist.   |            |     C     |          FT       |\n");
	printf("  ft=family time  | D=duolingo          | R4=read fre./sinh.   |____________|___________|___________________|\n\");
	printf("________________________________________________________________________________________________________________________________\n");
	printf("|______|____\u00Bf\u00Bf________TIMED_SCHEDULE____wake_up_5:20-5:40____________________________________\u00Bf\u00Bf________________________________|\n");
	printf("|______|    2    |______|   4   |______|    6   |______|   8   |______|   10 |______|  SAT2  |______|  SUN2  |______|  PD/BR2  |\n");
	printf("|_6:00_|  Program|_5:50_|  D    |_5:50_|  PA    |_5:50_|  PA   |_5:50_|  R1  |_5:50_|    D   |_5:50_| Java   |_5:50_|    C     |\n");
	printf("|_6:30_|   Read  |_6:05_| PA    |_6:00_| Read   |_6:00_|   C   |_6:10_| C++  |_6:10_|   PA   |_6:20_|  PA    |_6:20_|Science s.|\n");
	printf("|_6:50_|   PA    |_6:20_| R2    |_6:20_|Program |_6:20_|  SB   |_6:30_|Python|_6:35_| Program|_6:35_|   B    |_7:00_|Sinhala s.|\n");
	printf("|_7:00_|Breakfast|_6:40_|Program|_6:40_|Python  |_6:40_|  JS   |_6:50_|  PA  |_7:35_|   PP   |_7:25_|Breakfa.|_7:40_|    PP    |\n");
	printf("|_7:12_|Pack Bag |_6:50_|Breakf.|_7:00_|Breakf. |_7:00_| pack  |_7:00_|break.|_7:45_|HomWk/FT|_7:40_|    C   |_8:10_|     D    |\n");
	printf("|_7:18_|  school |_7:05_|Pack b.|_7:12_| Pack.  |_7:06_| brea. |_7:12_|pack. |_8:30_| French |_8:15_|Swimming|_8:30_| Breakfast|\n");
	printf("|_3:50_|  shower |_7:18_|school |_7:18_|school  |_7:18_|school |_7:18_|school|_9:10_|  Java  |11:25_|   PP   |_9:00_|  C++/Go  |\n");
	printf("|_4:15_|  lunch  |_3:50_|shower |_3:50_| shower |_3:50_|shower |_3:50_|shower|10:50_|   FT   |12:00_| Lunch  |10:00_|   Bash   |\n");
	printf("|_4:40_|  piano  |_4:15_| lunch |_4:15_| lunch*4|_4:15_| lunch |_4:20_|lunch |10:10_|Pack up |12:35_|   ft   |10:40_|   Java   |\n");
	printf("|_5:10_|    D    |_4:40_|  FT   |_4:40_|C/Python|_4:40_|   D   |_5:00_|  PP  |10:30_| Tennis |_1:00_|   MT   |11:30_|    PA    |\n");
	printf("|_5:35_|  Sinh.  |_5:20_|  PP   |_5:10_|   FT   |_5:10_|  PP   |_5:40_|   D  |_1:30_| Shower |_1:30_| Program|12:00_|  Lunch   |\n");
	printf("|_6:00_|   ft    |_5:50_|MT/FRE.|_5:30_|Homework|_5:40_|  Sci. |_6:20_|Homew.|_1:40_|WearClts|_3:00_|Fren. s.|12:40_|    SB    |\n");
	printf("|_6:30_|Homework |_6:10_|Homewo.|_6:00_|   D    |_6:00_|Homewo.|_6:40_|Progr.|_1:50_|  lunch |_3:30_|    D   |_1:10_|  Python  |\n");
	printf("|_7:10_|Fren. st.|_6:50_|Dinner |_6:25_| Dinner |_6:35_|Pack up|_7:20_|Sinha.|_2:30_|Sci/Math|_4:00_|   FT   |_2:00_|    JS    |\n");
	printf("|_7:50_|  Dinner |_7:20_|   D   |_6:50_|   ft   |_6:45_| Music |_7:40_|Dinner|_3:30_|Pick up |_4:30_|   PA   |_2:30_|    MT    |\n");
	printf("|_8:15_|   FT    |_7:50_|  ft   |_7:00_|   PP   |_7:50_| Dinner|_8:05_|  FT  |_5:00_|FT/Prgrm|_5:00_|  Bash  |_4:00_|     D    |\n");
	printf("|_8:25_|  Sleep  |_8:15_| sleep |_7:45_| sleep  |_8:15_| sleep |_8:15_|Sleep |_6:00_|C/C++/Go|_5:30_|   C++  |_5:00_|    FT    |\n");
	printf("|______|_________|______|_______|______|________|______|_______|______|______|_6:40_|Pyth./JS|_6:00_|   PP   |_6:00_|ft/Homewo.|\n");
	printf("|______|_________|______|_______|______|________|______|_______|______|______|_7:20_| Dinner |_6:30_| Dinner |_7:00_|    B     |\n");
	printf("|______|_________|______|_______|______|________|______|_______|______|______|_7:40_|   FT   |_7:00_|   FT   |_7:40_|  Program |\n");
	printf("|______|_________|______|_______|______|________|______|_______|______|______|_8:00_| sleep  |_7:30_|__sleep_|_8:00_|  Dinner  |\n");
	printf("|______|_________|______|_______|______|________|______|_______|______|______|______|________|______|________|_8:30_|  sleep   |\n");
	printf("|______|_________|______|_______|______|________|______|_______|______|______|______|________|______|________|______|__________|\n");
	printf("*1: Read buddhism books\n");
	printf("*2: SB1 = english/french, SB2 = history, SB3 = science/math, SB = any subject\n");
	printf("*3: Choose at least 1\n");
	printf("*4: Watch programming tutorials\n");
}
