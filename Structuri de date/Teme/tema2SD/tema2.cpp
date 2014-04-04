//Stanciu Catalin 312ca
#include "header.h"
int maxel;
int main() {
	char * s = (char *)malloc(32*sizeof(char));
	scanf("%d", &maxel);
	c_day = 0;
	maxdays = 30;
	//citirea si executarea fiecarei comenzi
	while (scanf("%s",s) == 1){
			if (strcmp(s,"DAY_PASSES") == 0){
				day_passes();
			}
		else {
			if (strcmp(s,"ACCESS_PAGE") == 0){
				char * pg =(char*)malloc(32*sizeof(char));
				scanf("%s",pg);
				access_page(pg);
			}
		else {
			if (strcmp(s,"CLEAR_RECENT_HISTORY") == 0){
				int nodays;
				scanf("%d",&nodays);
				clear_recent_history(nodays);
			}
		else {
			if (strcmp(s,"SET_MAX_DAYS") == 0){
				int max;
				scanf("%d",&max);
				set_max_days(max);
			}
		else {
			if (strcmp(s,"SHOW_ENTRY") == 0){
				int index;
				scanf("%d",&index);
				show_entry(index);
			}
		else {
			if (strcmp(s,"DELETE_ENTRY") == 0){
				int deleteindex;
				scanf("%d",&deleteindex);
				delete_entry(deleteindex);
			}
		else {
			if (strcmp(s,"SHOW_HISTORY") == 0){
				show_history();
			}
		else {
			if (strcmp(s,"RECOVER_HISTORY") == 0){
				char *c = (char*)malloc(15*sizeof(char));
				scanf("%s", c);
				//citirea din fisier si adugarea la inceputul listei
				FILE *f = fopen(c, "rt" );
				int nr,i,hday;
				fscanf(f ,"%d", &nr);
				for (i = 0;i < nr;i++) {
					char * l = (char*)malloc(32*sizeof(char));
					fscanf(f, "%d %s", &hday,l);
					if (hday >= c_day - maxdays){
						L.addFirst(hday,l);
					}
				}
			}
		}	}	}	}	}	}	}	}
return 0;
}

