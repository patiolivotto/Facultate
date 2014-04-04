#ifndef HEAP_H
#define HEAP_H

#include<iostream>
 
template <typename T>
class Heap
{ 
private:
    T* values;
    int dimVect;
    int capVect;
public:
    Heap(int capVect);
    ~Heap();
 
    int parent(int poz);
 
    int leftSubtree(int poz);
 
    int rightSubtree(int poz);
 
    void pushUp(int poz);
 
    void pushDown(int poz);
 
    void insert(T x);
 
    T peek();
 
    T extractMin();
};



template <typename T>
Heap<T>::Heap(int capVect)
{
    // TODO 1.1
    
		dimVect=-1;
		capVect=0;
		values=new T;
}

template <typename T>
Heap<T>::~Heap()
{
    // TODO 1.2
    //delete values;
}

/* TODO Exercitiul 2 */

template <typename T>
int Heap<T>::parent(int poz)
{
    // TODO 2.1
    if ((poz-1)/2 >-1) {
		return (poz-1)/2;
		}
	else 
		return -1;
return 0;
}

template <typename T>
int Heap<T>::leftSubtree(int poz)
{
    // TODO 2.1
    if (dimVect>=poz*2+1) {
		return poz*2+1;
		}
		else 
			return -1;
return 0;
}

template <typename T>
int Heap<T>::rightSubtree(int poz)
{
    // TODO 2.1
    if (dimVect>=poz*2+2) {
		return poz*2+2;
		}
		else 
			return -1;
return 0;    
}

template <typename T>
void Heap<T>::pushUp(int poz)
{
    // TODO 2.2
    T aux;
    if (poz > 0) {
		if (values[parent(poz)] < values[poz]) {
			aux = values[parent(poz)];
			values[parent(poz)] = values[poz];
			values[poz] = aux;
			return pushUp(parent(poz));
			}
	}
	else return;
 
}

template <typename T>
void Heap<T>::pushDown(int poz)
{
    // TODO 2.2
        int aux;
    if (poz <= dimVect) {
		if (leftSubtree(poz)<=dimVect)
			if (leftSubtree(poz)>0)
		if (values[leftSubtree(poz)] > values[poz]) {
			aux = values[leftSubtree(poz)];
			values[leftSubtree(poz)] = values[poz];
			values[poz] = aux;
			return pushDown(leftSubtree(poz));
			}
		if (rightSubtree(poz)<=dimVect)
		 if (rightSubtree(poz)>0)
		if (values[rightSubtree(poz)] > values[poz]) {
			aux = values[rightSubtree(poz)];
			values[rightSubtree(poz)] = values[poz];
			values[poz] = aux;
			return pushDown(rightSubtree(poz));
			}
		}
	else return;
 
}

/* TODO Exercitiul 3 */

template <typename T>
void Heap<T>::insert(T x)
{
    // TODO 3
    dimVect++;
    values[dimVect] = x;
    pushDown(0);
    pushUp(dimVect);
}

template <typename T>
T Heap<T>::peek()
{
    // TODO 3
    return (values[0]);
    
}

template <typename T>
T Heap<T>::extractMin()
{	
	T aux ;
    // TODO 3
    aux = values[0];
    values[0] = values[dimVect];
    dimVect--; 
    pushDown(0);
    pushDown(0);
    return aux;
}

#endif // HEAP_H
