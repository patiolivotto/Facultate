#include<iostream>
#include <stdio.h>
#include "heap.h"
Heap<int> heap(10);
template<class T>
void heapSort(T* array, int &n)
{
	// TODO 4
	for (int i=0;i<n;i++){
		heap.insert(array[i]);
		}
	for (int i=0;i<n;i++){
		array[i] = heap.extractMin();
		}
}

int main(void)
{
	int* v;
	int n;
	
	// TODO citire n
	scanf("%d",&n);
	// TODO alocare
	
	v = new int(n);
	// TODO citire vector
	for (int i=0;i<n;i++) {
		scanf("%d",&v[i]);
		}
	// sortare
	heapSort<int>(v, n);

	// Afisare
	for(int i = 0; i < n; ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
