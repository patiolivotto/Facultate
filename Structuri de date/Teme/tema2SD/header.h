#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_list.h"
//definirea unor variabile globale 
int maxdays = 30, c_day = 0 ;
//definirea structurii de date ce continde ziua si url-ul pentru fiecare accesare
struct pages {
	int day;
	char * url;
};
//redenumirea tipului de date struct pages
typedef struct pages PG;
//Declarare lista dublu inlantuita de tip PG
LinkedList <PG> L;
//Functia CLEAR_OLD_HISTORY - sterge valorile din lista cu ziua mai veche decat
//ziua curent - numarul maxim de zile
void clean_old_history() {
	int oldest_day;
	if (L.pFirst != NULL) {
		if (c_day - maxdays >= L.pFirst->value.day ) {
			int i;
			oldest_day = L.pFirst->value.day;
			i = c_day - maxdays;
			while ((oldest_day <= i)&&(L.pFirst != NULL)) {
					if (L.pFirst->value.day > oldest_day ) {
							oldest_day = L.pFirst->value.day;
					}else L.removeFirst();		
			}
		}
	}
}
//Functia DAY_PASSES - incredmentare zi curenta
void day_passes(){
	c_day++;
	clean_old_history();
}
//Functia ACCESS_PAGE - adauga un nod in lista
void access_page(char *pg ) {
	PG page;
	page.day = c_day;
	page.url = strdup( pg );
	L.addLast(page);
}
//Functia CLEAR RECENT HISTORY - sterge ultimele 'nodays' emente din lista 
void clear_recent_history(int nodays ) {
	clean_old_history();
	int x = c_day-nodays + 1;
	while ((L.pLast != NULL) && (L.pLast->value.day >= x)) {
		L.removeLast();
	}
}
//Functia SET_MAX_DAYS seteaza numarul maxim de zile si sterege cele mai 
//vechi intrari
void set_max_days(int max ) {
	maxdays = max;
	clean_old_history();
}
//Functia SHOW_ENTRY - afiseaza un element din lista in functie de indexul ales
void show_entry(int index ) {
	clean_old_history();
	int p = -1;
	if (L.pLast != NULL) L.pdep = L.pLast;
	while (L.pdep != L.pFirst->prev) {
		p++;
		if (p == index){
			printf("\nENTRY %d:\n%d %s", index,
				L.pdep->value.day, L.pdep->value.url);
			return;
		}
		L.pdep = L.pdep->prev;
	} 
}
//Functia DELETE_ENTRY - sterge un element din lista in functie de indexul ales
int delete_entry(int index ) {
	clean_old_history();
	int p=0;
	if (L.pLast != NULL) L.pdep = L.pLast;
	while (L.pdep != L.pFirst->prev) {
		if (p == index){
			if (L.pdep->prev != NULL) {
				if (L.pdep->next != NULL) {
					L.pdep->prev->next = L.pdep->next;
					L.pdep->next->prev = L.pdep->prev;
					return 0;
				}
					else {
						L.removeLast();
						return 0;
					}
			}
			else {
					L.removeFirst();
					return 0;
			}
		}
		p++;
		L.pdep = L.pdep->prev;
	} 
return 0;
}
//Functia SHOW_HISTORY - afiseaza intreaga lista de elemente in ordine inversa
void show_history() {
	clean_old_history();
	printf("\nHISTORY:\n");
	printf("Current day: %d", c_day);
	if (L.pLast != NULL) L.pdep = L.pLast;
	while (L.pdep != L.pFirst->prev) {
		printf("\n%d %s",L.pdep->value.day, L.pdep->value.url);
		L.pdep = L.pdep->prev;
	}
};
//end//
