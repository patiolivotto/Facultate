#include <iostream>
#include "DisjointSets.h"
#include <stdio.h>
#include <fstream>


using namespace std;

struct edge {
	int n1, n2;
	int cost;
};

int main()
{
	FILE *f = fopen("graph.in", "r");

	int i, n, m;
//	int v[20];
	edge g[20];
	fscanf(f, "%d %d ", &n, &m);

	DisjointSets dis(n);

	for (i = 0; i < m; i++) {
		fscanf(f, "%d %d", &g[i].n1, &g[i].n2);
		dis.Union(g[i].n1, g[i].n2);
	}

	for (i = 0; i < m; i++) {
		if (dis.Find(g[i].n1) == dis.Find(g[i].n2)) {
			cout << dis.Find(g[i].n1) << " " << g[i].n1 << " " << g[i].n2 << endl;
		}
	}

	fclose(f);
	return 0;
}
