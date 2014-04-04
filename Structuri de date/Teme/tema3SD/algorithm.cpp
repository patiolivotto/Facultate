//Stanciu Catalin 312CA
// algorithm.cpp : 
// Schelet cod Tema 3 SD - Inverted index
// Autor: octavian.rinciog@gmail.com
#include <string>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "algorithm.h"
#include <stdio.h>
#include "hashtb.h"

using namespace std;
//declarare hashtable 
Hashclass < char* > tabel_H(20000);

Algorithm::Algorithm(void)
{

}

Algorithm::~Algorithm(void)
{

}


void Algorithm::indexSite(const std::string &row)
{
	char *row_tok = strdup(row.c_str());
	char *command = strtok(row_tok," ");
	if (strcmp(command,"PUT") != 0)
	{
		free(row_tok);
		return;
	}
	
	char *site = strtok(NULL," ");
	char *word = strtok(NULL," ");
	
	while(word)
	{
		//adaugarea site-ului la cheia cuvant
		tabel_H.put(word, site);
		word = strtok(NULL, " ");
	}

	free(row_tok);
}

void Algorithm::getSites(const std::string &row)
{
	char *row_tok = strdup(row.c_str());
	char *command = strtok(row_tok, " ");
	int inc = -1;//retine numarul de cuvinte comune la un moment dat
	int nrc = -1;//retine numarul de cuvinte din vector la un moment dat
	char * vaux[20000];//vector site-uri folosit la interclasare
	char * v_site[20000];//vector de site-uri folosit pt a pastra rezultatul interclasarii 
	if (strcmp(command,"GET") != 0)
	{
		free(row_tok);
		return;
	}
	char *word = strtok(NULL," ");
	while(word)
	{
		int ok = 1;
		int nrw = tabel_H.get(word);
		if (nrw == -1) {
			inc = -1;
			break;
		}
		if (inc == -1) {
			inc = nrw;
			memcpy(&v_site, v, (inc+1) * sizeof(char*) );
		}
		else
			if (nrw > -1) {//interclasarea a 2 vectori
				for (int i = 0; i <= nrw; i++) {
					for (int j = 0;j <= inc;j++)
						if (strcmp(v_site[j], v[i]) == 0) {
							nrc++;
							ok=0;
							vaux[nrc] = strdup(v_site[j]);
						}
				}
				if (ok == 1) {
					inc = -1;
					break;
					}
				inc = nrc;
				memcpy(&v_site, vaux, (nrc + 1) * sizeof(char *) );
				nrc = -1;
				nrw = -1;
		}	else {
			inc = -1;
			break;
			}
		word = strtok(NULL, " ");
	}
	//afisare
	if (inc > -1) {
		for (int i = 0;i <= inc;i++){
			cout<<v_site[i]<<" ";
		}
	}
	else std::cout<<"SITE_NOT_FOUND";
	cout<<endl;
	free(row_tok);
}

void Algorithm::wordInSite(const std::string &row)
{
	char *row_tok = strdup(row.c_str());
	char *command = strtok(row_tok, " ");
	if (strcmp(command,"SITE") != 0)
	{
		free(row_tok);
		return;
	}
	
	char *site = strtok(NULL, " ");
	char *word = strtok(NULL, " ");
	int ok = 0;
	while(word)
	{
		ok = 0;
		int nr = -1;
		nr = tabel_H.get(word);
		for (int i = 0;i <= nr;i++) {
			if (strcmp(site, v[i]) == 0) {
				ok = 1;
				break;
			}
		}
		if (ok == 0) {
			std::cout<<"WORD_NOT_FOUND\n";
			return;
		}
		
		word = strtok(NULL, " ");
	}
	if (ok == 1) std::cout<<"WORD_FOUND\n";
	free(row_tok);
}

void Algorithm::resolve()
{
	string row;
	while ( std::cin.good() )
	{
		std::getline(std::cin,row);
		//nu iau in considerare linii cu mai putin de 3 caractere
		if (row.size()<3)
			continue;
		switch(row[0])
		{
		//PUT
			case 'P':
			indexSite(row);
			break;
		//GET
		case 'G':
			getSites(row);
			break;
		//SITE
		case 'S':
			wordInSite(row);
			break;
		default:
			cout<<"Invalid option"<<endl;
		}
	}
}


