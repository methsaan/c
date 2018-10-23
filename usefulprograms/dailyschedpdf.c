#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(int argc, char *argv){
	char a[2];
	a[0] = __DATE__[4];
	a[1] = __DATE__[5];
	int b = atoi(a);
	int flag = 0;
	int i;
	for (i = 2; i <= b/2; ++i){
		if (b%i == 0){
			flag = 1;
			break;
		}
	}
	system("clear");
	if ((flag != 0) || (b == 1)) {
		printf("Today is %s. %d is a composite number. You are following the regular schedule\n", __DATE__, b);
	}else {
		printf("Today is %s. %d is a prime number. You are following the timed schedule\n", __DATE__, b);
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
	printf("|___________________________________________________________________________________________________________________________________________________|\n");
	printf("|______|____\u00Bf\u00Bf________TIMED_SCHEDULE____wake_up_5:20-5:40___________________________________\u00Bf\u00Bf______________________________________________________|\n");
	printf("|______|   MON   |______| TUE   |______| WED    |______| THU  |______| FRI  |______|  SAT   |______|  SUN   |______|  PD/BR   |______| FAILED DAYS  |\n");
	printf("|_6:00_|  Program|_5:50_|  D    |_5:50_|  PA    |_5:50_|  PA  |_5:50_| Read |_5:50_| Program|_5:50_| Java   |_5:50_|    C     |_5:50_|     D        |\n");
	printf("|_6:30_|   Read  |_6:05_| PA    |_6:00_| Read   |_6:00_|   D  |_6:10_| C++  |_6:30_|  PA    |_6:20_|  PA    |_6:20_|    D     |_6:10_|     PP       |\n");
	printf("|_6:50_|   PA    |_6:20_| Read  |_6:20_|Program |_6:20_|  SB  |_6:30_|Python|_6:50_|   D    |_6:35_|   C    |_6:40_|    FT    |_6:45_|     FT       |\n");
	printf("|_7:00_|Breakfast|_6:40_|Program|_6:40_|Python  |_6:40_|  JS  |_6:50_|  PA  |_7:15_|  PP    |_7:05_|   B    |_7:00_|French st.|_7:05_|     PT       |\n");
	printf("|_7:12_|Pack Bag |_6:50_|Breakf.|_7:00_|Breakf. |_7:00_| pack |_7:00_|break.|_7:45_| program|______|________|______|__________|______|______________|\n");
	printf("|_7:18_|  school |_7:05_|Pack b.|_7:12_| Pack.  |_7:06_| brea.|_7:12_|pack. |_9:00_| French |______|________|______|__________|______|______________|\n");
	printf("|_3:50_|  shower |_7:18_|school |_7:18_|school  |_7:18_|school|_7:18_|school|_9:40_|   C++  |______|________|______|__________|______|______________|\n");
	printf("|_4:10_|  lunch  |_3:50_|shower |______|________|______|______|______|______|______|________|______|________|______|__________|______|______________|\n");
	printf("|_4:30_|  piano  |_4:10_| lunch |______|________|______|______|______|______|______|________|______|________|______|__________|______|______________|\n");
	printf("|_4:50_|    D    |_4:50_|  FT   |______|________|______|______|______|______|______|________|______|________|______|__________|______|______________|\n");
	printf("|_5:10_|   Java  |_5:10_|  PP   |______|________|______|______|______|______|______|________|______|________|______|__________|______|______________|\n");
	printf("|_5:40_| Homework|_5:40_|   D   |______|________|___TO_BE_CONTINUED__|______|______|________|______|________|______|__________|______|______________|\n");
	printf("|_6:00_|   ft    |_6:00_|  ft   |______|________|______|______|______|______|______|________|______|________|______|__________|______|______________|\n");
	printf("|_6:20_|Fren. st.|_6:40_|Homewo.|______|________|______|______|______|______|______|________|______|________|______|__________|______|______________|\n");
	printf("|_6:50_|  Dinner |_7:00_| Dinner|______|________|______|______|______|______|______|________|______|________|______|__________|______|______________|\n");
	printf("|_7:15_|    FT   |_7:25_|   C   |______|________|______|______|______|______|______|________|______|________|______|__________|______|______________|\n");
	printf("|_7:40_| program |_7:45_|  Read |______|________|______|______|______|______|______|________|______|________|______|__________|______|______________|\n");
	printf("|_8:00_|    FT   |_8:10_| Python|______|________|______|______|______|______|______|________|______|________|______|__________|______|______________|\n");
	printf("|_8:15_|  sleep  |_8:30_|  sleep|______|________|______|______|______|______|______|________|______|________|______|__________|______|______________|\n");
	printf("|______|_________|______|_______|______|________|______|______|______|______|______|________|______|________|______|__________|______|______________|\n");
}
