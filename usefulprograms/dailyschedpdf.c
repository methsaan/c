#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(int argc, char *argv){
	srand(time(NULL));
	system("clear");
	if ((rand()%100)<60){
		printf("You are following the regular schedule\n");
	}else {
		printf("You are following the timed schedule\n");
	}
	printf("___________________________________________________________________________________________________________\n");
	printf("|________??____________REGULAR_SCHEDULE___________wake_up_5:20-6:00_sleep_8:10-9:20_________??____________|\n");
	printf("|_________________________________________________________________________________________________________|\n");
	printf("|  MONDAY  |  TUESDAY   |  WEDNESDAY |  THURSDAY  |  FRIDAY  |  SATURDAY  |  SUNDAY   |  PDs AND BREAKS   |\n");
	printf("|__________|____________|____________|____________|__________|____________|___________|___________________|\n");
	printf("|    Math  |    D       |  Python    |Program(sched)   D     |Read(sched) |    C      |      D/B/program  |\n");
	printf("|    Read  | SB (sched) |    SQL     |     JS     |  C++/SQL |     D      |  Java     |        PA         |\n");
	printf("|  Program |    Read    |     PA     |C/Smart books| Program |     PP     |    PA     |        PP         |\n");
	printf("|          |            |            |            |          |            |           |       Maths       |\n");
	printf("| AFTERNOON| AFTERNOON  | AFTERNOON  | AFTERNOON  | AFTERNOON|  AFTERNOON | AFTERNOON |   AFTERNOON       |\n");
	printf("|__________|____________|____________|____________|__________|____________|___________|___________________|\n");
	printf("|     D    |JavaScript/C| SB (sched) |     PT     |    D     |Read (sched)|  ft       |  _     PT         |\n");
	printf("|     PP   |  PT        |    ft      |     D      |    PP    |  C++       |  D        | |      ft         |\n");
	printf("|Python/Java| PP        |    PP      |     PP     |    C/Java|  PP        |  PP       | |   French study  |\n");
	printf("|  PT      |  PA        |    PT      | JavaScript |    PT    |  Python    |HTML/JS/C++| |       ft        |\n");
	printf("|  PA      |  FT        | HTML/C++   |     PA     |    PA    |  FT        | PT        | |    Smart books  |\n");
	printf("|__________|____________|____________|____________|__________|  Java      | FT        | |*1     FT        |\n");
	printf("                                                             |  PP        | PP        | |       PP        |\n");
	printf("                 Sinhala dictation/Triolingo 5:30pm          |Smart books | D         | |       D         |\n");
	printf("  B = Buddhism *3       PA = physical activity               |  FT        | FT        | | Python/Java/C++/|\n");
	printf("  SB = smart books      PT = piano theory                    |  ft        | PP        | |  C/JS/HTML *2   |\n");
	printf("                        PP = practical piano                 |            | C         | |_       FT       |\n");
	printf("                        D = duolingo                         |            |           |                   |\n");
	printf("                        FT = free time ft = family time      |____________|___________|___________________|\n");
	printf("                        PBT = Programming Blog tutorial                                                    \n");
	printf("*2: Choose at least 2\n");
	printf("*3: Namothassa, five precepts, ethipisso, meditation 1 minute\n");
	printf("|____________________________________________________________________________________________________________________________________________________|\n");
	printf("|______|____\u00Bf\u00Bf________TIMED_SCHEDULE____wake_up_5:20-5:40____________________________________\u00Bf\u00Bf______________________________________________________|\n");
	printf("|______|   MON   |______| TUE   |______| WED    |______| THU   |______| FRI  |______|  SAT   |______|  SUN   |______|  PD/BR   |______| FAILED DAYS  |\n");
	printf("|_6:00_|  Program|_5:50_|  D    |_5:50_|  PA    |_5:50_|  PA   |_5:50_| Read |_5:50_| Program|_5:50_| Java   |_5:50_|    C     |_5:50_|     D        |\n");
	printf("|_6:30_|   Read  |_6:05_| PA    |_6:00_| Read   |_6:00_|   C   |_6:10_| C++  |_6:30_|  PA    |_6:20_|  PA    |_6:20_|    D     |_6:10_|     PP       |\n");
	printf("|_6:50_|   PA    |_6:20_| Read  |_6:20_|Program |_6:20_|  SB   |_6:30_|Python|_6:50_|   D    |_6:35_|   B    |_6:40_|    FT    |_6:45_|     FT       |\n");
	printf("|_7:00_|Breakfast|_6:40_|Program|_6:40_|Python  |_6:40_|  JS   |_6:50_|  PA  |_7:15_|  PP    |_7:25_|Breakfa.|_7:00_|French st.|_7:05_|     PT       |\n");
	printf("|_7:12_|Pack Bag |_6:50_|Breakf.|_7:00_|Breakf. |_7:00_| pack  |_7:00_|break.|_7:45_| program|_7:40_|    C   |______|__________|______|______________|\n");
	printf("|_7:18_|  school |_7:05_|Pack b.|_7:12_| Pack.  |_7:06_| brea. |_7:12_|pack. |_9:00_| French |_8:15_|Swimming|______|__________|______|______________|\n");
	printf("|_3:50_|  shower |_7:18_|school |_7:18_|school  |_7:18_|school |_7:18_|school|_9:40_|   C++  |11:25_|   PP   |______|__________|______|______________|\n");
	printf("|_4:15_|  lunch  |_3:50_|shower |_3:50_| shower |_3:50_|shower |_3:50_|shower|10:20_|   FT   |12:00_| Lunch  |______|__________|______|______________|\n");
	printf("|_4:40_|  piano  |_4:15_| lunch |_4:15_|  lunch |_4:15_|lunch*1|_4:20_|lunch |10:30_|Pack up |12:35_|   ft   |______|__________|______|______________|\n");
	printf("|_5:10_|    D    |_4:40_|  FT   |_4:40_|C/Python|_4:40_|   D   |_5:00_|  PP  |10:40_| Tennis |_1:00_|   PT   |______|__________|______|______________|\n");
	printf("|_5:35_|   Java  |_5:20_|  PP   |_5:10_|   FT   |_5:10_|  PP   |_5:40_|   D  |12:20_| Lunch  |_1:30_| Program|______|__________|______|______________|\n");
	printf("|_6:00_|   ft    |_5:50_|PT/FRE.|_5:30_|Homework|_5:40_|  PT   |_6:20_|Homew.|_1:45_|   FT   |_3:00_|Fren. s.|______|__________|______|______________|\n");
	printf("|_6:30_|Homework |_6:10_|Homewo.|_6:00_|  Java  |_6:00_|Homewo.|_6:40_|Progr.|_2:20_|C/Python|_3:30_|    D   |______|__________|______|______________|\n");
	printf("|_7:10_|Fren. st.|_6:50_|Dinner |_6:25_| Dinner |_6:35_|Pack up|_7:20_|Sinha.|_2:50_|   SB   |_4:00_|   FT   |______|__________|______|______________|\n");
	printf("|_7:50_|  Dinner |_7:20_|   D   |_6:50_|   ft   |_6:45_| Music |_7:40_|Dinner|_3:30_|   PT   |_4:30_|   PA   |______|__________|______|______________|\n");
	printf("|_8:15_|   FT    |_7:50_|  ft   |_7:00_| Hom/FT |_7:50_| Dinner|_8:05_|  FT  |_4:00_| Program|_5:00_|  Bash  |______|__________|______|______________|\n");
	printf("|_8:25_|  Sleep  |_8:15_| sleep |_7:30_| sleep  |_8:15_| sleep |_8:15_|Sleep |_5:00_|   FT   |_5:30_|   C++  |______|__________|______|______________|\n");
	printf("|______|_________|______|_______|______|________|______|_______|______|______|_6:00_|  Java  |_6:00_|   PP   |______|__________|______|______________|\n");
	printf("|______|_________|______|_______|______|________|______|_______|______|______|_7:00_| Dinner |_6:30_| Dinner |______|__________|______|______________|\n");
	printf("|______|_________|______|_______|______|________|______|_______|______|______|_7:40_|   FT   |_7:00_| sleep  |______|__________|______|______________|\n");
	printf("|______|_________|______|_______|______|________|______|_______|______|______|_8:00_| sleep  |______|________|______|__________|______|______________|\n");
	printf("|______|_________|______|_______|______|________|______|_______|______|______|______|________|______|________|______|__________|______|______________|\n");
	printf("*1: Watch programming videos\n");
}
