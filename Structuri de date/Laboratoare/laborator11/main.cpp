#include <iostream>
#include "DisjointSets.h"
#include <fstream>
#include <stdio.h>
using namespace std;

struct edge {
	int n1, n2;
	int cost;
};

int main()
{
	ifstream in;
	FILE *f=fopen("kruskal.in","r");
	in.open("kruskal.in");
	int i, n, m, cost = 0;
	edge g[20];
	fscanf(f,"%d %d" , &n, &m);

	DisjointSets dis(n);

	for (i = 0; i < m; i++) {
		fscanf(f, "%d %d %d", &g[i].n1 , &g[i].n2, &g[i].cost);
	}

	for (i= 0; i < m; i++) {
		if (dis.Find(g[i].n1) != dis.Find(g[i].n2)) {
			dis.Union(g[i].n1, g[i].n2);
			cout << g[i].n1 << " " << g[i].n2 << g[i].cost<< endl;
			cost += g[i].cost;
		}
	}

	fclose(f);
	return 0;
}
