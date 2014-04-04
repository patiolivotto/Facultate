//declarare variabile globale, structuri si functii
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "linked_list.h"
#include "queue.h"
#include "stack.h"

	// variabile globale
	struct people{
		int id, w;
		};
	struct window{
		int wmin, wmax, qmax, kmax, sizeq, sizek;
		Queue <people> c;
		Stack <people> s;
		} a[500];
	int nr = -1;
	int v[500];
//aici sunt declarate functiile continute de programul principal
	//functie de sortare vector (`bubble sort`) 
int sort(int n) {
	int i, aux, ok = 0;
	do {
		ok = 0;
		for (i = 0;i < n;i++) {
			if (v[i] > v[i+1]) {
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				ok = 1;
				}
			}
		} 
		while (ok == 1);
return 0;
}
//functia de adaugare ghiseu
int add_window(int WINDOW_ID, int WHEIGHT_MIN, int WHEIGHT_MAX, int Q, int K) {
	nr++;
	v[nr] = WINDOW_ID;
	a[v[nr]].wmin = WHEIGHT_MIN;
	a[v[nr]].wmax = WHEIGHT_MAX;
	a[v[nr]].qmax = Q;
	a[v[nr]].kmax = K;
	a[v[nr]].sizeq = 0;
	a[v[nr]].sizek = 0;
	sort(nr);
	return 0;
}
//functia adaugare persoana 
int add_person(int PERSONAL_ID , int PACKAGE_WHEIGHT , int WINDOW_ID ) {
	people p;
	p.id=PERSONAL_ID;
	p.w=PACKAGE_WHEIGHT;
	a[WINDOW_ID].c.enqueue(p);
	return 0;
}
//functia golire stiva
int clean_stack(int W_ID){
	while (!a[W_ID].s.isEmpty()) {
		a[W_ID].s.pop();
		}		
	a[W_ID].sizek = 0;
	a[W_ID].sizeq = 0;
return 0;
}
//functia procesare ghiseu pentru N persoane
int process(int W_ID , int N_PEOPLE) {
	int i;
	int j = 0;
	int ok = 1;
	Queue <people> aux;
	for (i = 0;i < N_PEOPLE;i++) {
		if (!a[W_ID].c.isEmpty()) {
			if (( a[W_ID].c.front().w <= a[W_ID].wmax )&&
						( a[W_ID].c.front().w >= a[W_ID].wmin )){
				if ((a[W_ID].c.front().w + a[W_ID].sizek <= a[W_ID].kmax) && 
							(a[W_ID].sizeq < a[W_ID].qmax)) {
					a[W_ID].s.push(a[W_ID].c.dequeue());
					a[W_ID].sizek += a[W_ID].s.peek().w;
					a[W_ID].sizeq++;
					}
					else {
						clean_stack(W_ID);
						i--;
						}
				}
				else {
					if (nr > 0){
					while ((j < 500)&&(ok == 1)) {
						if (v[j] == W_ID) {
							ok = 0;
						}
						j++;
					}
					if (j <= nr) {					
						a[v[j]].c.enqueue(a[W_ID].c.dequeue());
					}
					else {
						a[v[0]].c.enqueue(a[W_ID].c.dequeue());
					}
				}
				else {
					aux.enqueue(a[W_ID].c.dequeue());
					}
				}
			}
		}
	if (nr == 0) {
		while (!aux.isEmpty()){
			a[W_ID].c.enqueue(aux.dequeue());
			}
		}
	return 0;
}
//functia procesare toate persoanele de la ghiseu
int process_all(int W_ID) {
	int j = 0;
	int ok = 1;
	Queue <people> aux;
	while (!a[W_ID].c.isEmpty()) {
		if (( a[W_ID].c.front().w <= a[W_ID].wmax ) && 
							( a[W_ID].c.front().w >= a[W_ID].wmin )) {							
			if ((a[W_ID].c.front().w + a[W_ID].sizek <= a[W_ID].kmax) 
							&& (a[W_ID].sizeq < a[W_ID].qmax)) {
				a[W_ID].s.push(a[W_ID].c.dequeue());
				a[W_ID].sizek += a[W_ID].s.peek().w;
				a[W_ID].sizeq++;
				}
				else {
					clean_stack(W_ID);
				}
			}
			else {
				if (nr > 0){
					while ((j<500)&&(ok == 1)) {
						if (v[j] == W_ID) {
							ok = 0;
						}
						j++;
					}
					if (j <= nr) {					
						a[v[j]].c.enqueue(a[W_ID].c.dequeue());
						}
						else {
							a[v[0]].c.enqueue(a[W_ID].c.dequeue());
							}
					}
					else {
						aux.enqueue(a[W_ID].c.dequeue());
						}
				}
		}
	if (nr == 0) {
		while (!aux.isEmpty()){
			a[W_ID].c.enqueue(aux.dequeue());
			}
		}
return 0;
}
//functia afisare stive de la fiecare ghiseu
int print_stacks() {
	int i = 0;
	Stack <people> aux;
	std::cout<<"STACKS:\n";
	for (i = 0;i <= nr;i++) {
		std::cout<<v[i]<<": ";
		while (!a[v[i]].s.isEmpty()){
			std::cout<<a[v[i]].s.peek().w;
			aux.push(a[v[i]].s.pop());
			if ( !a[v[i]].s.isEmpty() ) {
				std::cout<<", ";
				}
			}
		std::cout<<"\n";
		while (!aux.isEmpty()){
			a[v[i]].s.push(aux.pop());
			}
		}
return 0;
}
//functia afisare si golire stive
int flush_stacks() {
	int i = 0;
	std::cout<<"FLUSHING:\n";
	for (i = 0;i <= nr;i++) {
		std::cout<<v[i]<<": ";
		while (!a[v[i]].s.isEmpty()){
			std::cout<<a[v[i]].s.pop().w;
			if (!a[v[i]].s.isEmpty()) {
				std::cout<<", ";
				}
			}
		std::cout<<"\n";
		a[v[i]].sizeq = 0;
		a[v[i]].sizek = 0;
		}
	return 0;
}
//functia afisare cozi
int print_queues() {
	int i = 0;
	Queue <people> aux;
	std::cout<<"QUEUES:\n";
	for (i = 0;i <= nr;i++) {
		std::cout<<v[i]<<": ";
		while (!a[v[i]].c.isEmpty()){
			std::cout<<"("<<a[v[i]].c.front().id<<", "<<a[v[i]].c.front().w<<")";
			aux.enqueue(a[v[i]].c.dequeue());
			if (!a[v[i]].c.isEmpty()) {
				std::cout<<", ";
				}
			}
		std::cout<<"\n";
		while (!aux.isEmpty()){
			a[v[i]].c.enqueue(aux.dequeue());
			}
		}
	return 0;
};	
