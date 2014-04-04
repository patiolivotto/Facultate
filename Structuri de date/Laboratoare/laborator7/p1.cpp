#include "Maze.h"
#include <queue>
#include <iostream>
using namespace std;

#define INF 2345
static int dx[4] = {-1, 0, 1, 0};
static int dy[4] = {0, -1, 0, 1};

static Maze* maze;

void bfs(int x, int y)
{
	int i, j;
	// alocare si initializare matrice de distante
	int** dist = new int*[maze->get_height()];
	for (i = 0; i < maze->get_height(); i++) {
		dist[i] = new int[maze->get_width()];
		for (j = 0; j < maze->get_width(); j++)
			dist[i][j] = INF;
	}
	dist[x][y] = 0;
	
	int** c = new int*[maze->get_height()];
	for (i = 0; i < maze->get_height(); i++) {
		c[i] = new int[maze->get_width()];
		for (j = 0; j < maze->get_width(); j++)
			c[i][j] = 0;
	}
	c[x][y] = 1;
	
	//declarare si initializare coada
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	//TODO: completati BFS
	pair<int, int> temp;
	
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		
		x = temp.first;
		y = temp.second;
		
		for (i = 0; i < 4; i++)
			if (c[x + dx[i]][y + dy[i]] == 0 && 
						(*maze).is_walkable(x + dx[i], y + dy[i]) ) {
				c[x + dx[i]][y + dy[i]] = 1;
				dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
				q.push(make_pair(x + dx[i], y + dy[i]));
			}
			
			c[x][y] = -1;
	}

	// afisare matrice distanta
	for (int i = 0; i < maze->get_height(); i++) {
		for (int j = 0; j < maze->get_width(); j++)
			if (dist[i][j] == INF)
				cout<<"#"<<" ";
			else
				cout<<dist[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	std::ifstream in("robot.in");
	int m, n;
	in >> m >> n;

	maze = new Maze(m, n);
	in >> *maze;

	int x, y;
	in >> x >> y;
	bfs(x, y);

	delete maze;
	return 0;
}
