#include "Node.h"
#include <fstream>
#include <iostream>

using namespace std;

static int t;
static Node** nodes;

void dfs(int u)
{
	//TODO: completati DFS
}

int main()
{
	std::ifstream in("sortare.in");
	int n, m;
	in >> n >> m;

	// alocare memorie noduri
	nodes = new Node*[n];
	for (int i = 0; i < n; i++) {
		nodes[i] = new Node();
		nodes[i]->color = WHITE;
		nodes[i]->tDesc = 0;
		nodes[i]->tFin = 0;
	}

	// citire muchii
	for (int i = 0; i < m; i++) {
		int a, b;
		in >> a >> b;
		nodes[a]->neigh.push_back(b);
	}

	// apelare DFS
	t = 0;
	for (int i = 0; i < n; i++) {
		if (nodes[i]->color == WHITE)
			dfs(i);
	}

	// TODO: sortati nodes in functie de tFin

	// dezalocare memorie
	for (int i = 0; i < n; i++)
		delete nodes[i];
	delete[] nodes;

	return 0;
}