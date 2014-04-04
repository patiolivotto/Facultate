
class DisjointSets
{
private:
	int *parinte;	
	int n;			
	int *dim;		
	int *aux;	

public:
//Constructor
	DisjointSets(int n) {
		this->n = n;

		dim = new int [n + 1];
		parinte = new int [n + 1];
		aux = new int [n + 1];
		for(int i = 0; i < n + 1; i++) {
			parinte[i] = 0;
			dim[i] = 1;
		}
	}
//Destructor
	~DisjointSets() {
		delete [] parinte;
		delete [] dim;
	}
// functia UNION
	void Union(int x, int y) {
		if(x <= 0 || x > n || y <= 0 || y > n)
			return;
	
		int rx = Find(x);
		int ry = Find(y);
		if(rx == ry) return;
	
		if(dim[rx] >= dim[ry]) {
			dim[rx] += dim[ry];
			parinte[ry] = rx;
		} else {
			dim[ry] += dim[rx];
			parinte[rx] = ry;
		}
	
	}
//functia FIND
	int Find(int x) {
		if(x <= 0 || x > n)	return 0;

		int n = 0;
		while(parinte[x] > 0) {
			aux[n++] = x;
			x = parinte[x];
		}

		for(int i = 0; i < n; i++)
			parinte[aux[i]] = x;

return x;
	}


};


