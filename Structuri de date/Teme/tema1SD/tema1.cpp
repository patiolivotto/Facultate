#include "header.h"
int main(int argc, char *argv[]) {
	//declarare variabile
	int WINDOW_ID, WEIGHT_MIN, WEIGHT_MAX, Q, K, PERSONAL_ID, PACKAGE_WEIGHT;
	int N_PEOPLE;
	FILE *f = fopen(argv[1], "r");
	char * s = (char *)malloc(20*sizeof(char));
	while (fscanf(f, "%s", s) == 1) {
		if (strcmp(s, "OPEN_WINDOW") == 0){
			fscanf(f, "%d %d %d %d %d"
					, &WINDOW_ID, &WEIGHT_MIN, &WEIGHT_MAX, &Q, &K);
			add_window(WINDOW_ID, WEIGHT_MIN, WEIGHT_MAX, Q, K);
			}
			else
				if (strcmp(s, "ADD_PERSON") == 0) {
					fscanf(f, "%d %d %d"
						, &PERSONAL_ID, &PACKAGE_WEIGHT, &WINDOW_ID);
					add_person(PERSONAL_ID, PACKAGE_WEIGHT, WINDOW_ID);
					}
					else
						if (strcmp(s, "PROCESS") == 0) {
							fscanf(f, "%d %d", &WINDOW_ID, &N_PEOPLE);
							process(WINDOW_ID, N_PEOPLE);
							}
							else
								if (strcmp(s, "PROCESS_ALL") == 0) {
									fscanf(f, "%d", &WINDOW_ID);
									process_all(WINDOW_ID);
								}
								else
									if (strcmp(s, "PRINT_STACKS") == 0) {
										print_stacks();									
										}
									else
							if (strcmp(s, "FLUSH_STACKS") == 0) {
											flush_stacks();								
								}
							else 
								if (strcmp(s, "PRINT_QUEUES") == 0) {
									print_queues();
								}
		}
	return 0;
}
