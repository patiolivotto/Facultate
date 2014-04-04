#include <iostream>
#include <stdio.h>
#include <stdlib.h>

template <typename T>struct Node {

public:

	T value;
	Node<T> *next;
	Node<T> *prev;
};

template <typename T>class LinkedList{
private:

	Node<T> *pFirst, *pLast;

public:

	//Constructor
	LinkedList(){
	pFirst=NULL;
	pLast=NULL;
	};
	//Destructor
	~LinkedList();

	/*Adauga un nod cu valoarea == value la inceputul listei */
	void addFirst(T value){
	struct Node<T> *paux;

            paux = new struct Node<T>;
            paux->value = value;
            paux->prev = NULL;
            paux->next = pFirst;

            if (pFirst != NULL) pFirst->prev = paux;
            pFirst = paux;

            if (pLast==NULL) pLast=pFirst;

	}

	/*Adauga un nod cu valoarea == value la sfarsitul listei */
	void addLast(T value){
    struct Node<T> *paux;

            paux = new struct Node<T>;
            paux->value = value;
            paux->prev = pLast;
            paux->next = NULL;

            if (pLast != NULL) pLast->next = paux;
            pLast = paux;
            if (pFirst == NULL) pFirst = pLast;


	};

	/*Elimina elementul de la inceputul listei si intoarce valoarea acestuia*/
	T removeFirst(){
	            struct Node<T>* paux;

            if (pFirst != NULL) {
                paux = pFirst->next;
                if (pFirst == pLast) pLast = NULL;
                delete pFirst;
                pFirst = paux;
                if (pFirst != NULL) pFirst->prev = NULL;
            }
            else fprintf(stderr, “Error 101 - The list is empty\n”); }

	};

	/*Elimina elementul de la sfarsitul listei listei si intoarce valoarea acestuia*/
	T removeLast(){
	            struct Node<T> *paux;

            if (pLast != NULL) {
                paux = pLast->prev;
                if (pFirst == pLast) pFirst = NULL;
                delete pLast;
                pLast = paux;
                if (pLast != NULL) pLast->next = NULL;
            }
            else fprintf(stderr, “Error 102 - The list is empty\n”);

	};

	/*Elimina prima aparitie a elementului care are valoarea == value*/
	T removeFirstOccurrence(T value){
	            struct Node<T> *paux;

            paux = pFirst;
            while (paux != NULL) {
                if (paux->value == value)
                    return paux;
                paux = paux->next;
            }
            return NULL;
	};

	/*Elimina ultima aparitie a elementului care are valoarea == value*/
	T removeLastOccurrence(T value){
    struct Node<T> *paux;

            paux = pLast;
            while (paux != NULL) {
                if (paux->value == value)
                    return paux;
                paux = paux->prev;
            }

            return NULL;




	};

	/*Intoarce prima aparitie a elementului care are valoarea == value, NULL daca nu exista*/
	Node<T>* findFirstOccurrence(T value){

	};

	/*Intoarce ultima aparitie a elementului care are valoarea == value, NULL daca nu exista*/
	Node<T>* findLastOccurrence(T value){


	};

	/*Intoarce 1 daca lista este vida, 0 altfel*/
	int  isEmpty(){
	            return (pFirst == NULL);
	};
};

