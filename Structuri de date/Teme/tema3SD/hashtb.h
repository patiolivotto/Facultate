//Stanciu Catalin 312CA
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
char* v[20000] ;
template <typename T>
class Hashclass {
private:
    // declararea vectorului de liste
    LinkedList<T>* datalist;
    
    // hash table size
    unsigned int hash_size;
    
    // HashFunction=functia de hash putin modificta pentru a-mi returna 
    //o valoare in intervalul dmensiunii maxime a vectorului
    unsigned int HashFunction(const char* key) {
        unsigned int hash = 5381;
        for (unsigned int i = 0; i < strlen(key); i++)
            hash = ((hash << 5) + hash) + (unsigned int)key[i];
        return hash % hash_size;
    }
    
public:
    Hashclass(unsigned int size): hash_size(size) {
        // initializarea vectorului de liste cu dimensiunea 'hash_size'
        datalist = new LinkedList<T>[hash_size];
    }

    ~Hashclass() {
        delete[] datalist;
    }
//functia PUT
    void put(const char* key, const T& value) {
        unsigned int hash = HashFunction(key);
        datalist[hash].addElement(value);
    }
//functia GET   
    int get(const char* key) {
		unsigned int hash = HashFunction(key);
		struct Node<T> *p = datalist[hash].pFirst;
		int i = -1;
		while (p != NULL) {
			i++;
			v[i] = strdup(p->value);
			p = p->next;
		}
		return i;
	}
};


