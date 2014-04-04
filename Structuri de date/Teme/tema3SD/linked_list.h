//Stanciu Catalin 312CA
template <typename T>struct Node {
public:
	T value;
	Node<T> *next;
	Node<T> *prev;
};
 
template <typename T>class LinkedList{
public: 
	Node<T> *pFirst, *pLast;
	//Constructor
	LinkedList(){
		 pFirst = NULL;
		 pLast = NULL;
	};
	//Destructor
	~LinkedList(){};
	/*Adauga un nod cu valoarea == value la inceputul listei */
	void addFirst(T value){
		 struct Node<T> *paux;
         paux = new struct Node<T>;
         paux->value =strdup( value);
         paux->prev = NULL;
         paux->next = pFirst;
         if (pFirst != NULL) pFirst->prev = paux;
         pFirst = paux;
         if (pLast==NULL) pLast=pFirst;
	};
	/*Adauga un nod cu valoarea == value la sfarsitul listei */
	void addLast(T value){
		struct Node<T> *paux;
        paux = new struct Node<T>;
        paux->value = strdup(value);
        paux->prev = pLast;
        paux->next = NULL;
        if (pLast != NULL) pLast->next = paux;
        pLast = paux;
        if (pFirst == NULL) pFirst = pLast;
    }

	/*Adaugare cu pastrarea listei sortate*/
	    void addElement(T x) {
            struct Node<T> *p;
            p = pFirst;
            if (p == NULL) {
				addFirst(x);
				return;
			} 
			else {
				while ((strcmp(x, p->value) > 0)&&(p->next != NULL)){
					p = p->next;
				}
				if (p->prev != NULL){
					if ((strcmp(p->prev->value, x) == 0)) return;
				}
				if (p->next != NULL){
					if ((strcmp(p->next->value, x) == 0)) return;
				}
				if (p != NULL){
					if ((strcmp(p->value, x) == 0)) return;
				}
				if ((p->prev == NULL) && (strcmp(x, p->value) < 0)) addFirst(x);
				else
					if ((p->next == NULL) && (strcmp(x,p->value) > 0)) addLast(x);
					else {
						struct Node<T> *cp;
						cp = new struct Node<T>;
						cp->value = strdup(x);
						cp->next = p;
						cp->prev = p->prev;
						p->prev->next = cp;
						p->prev = cp;
					
				}
            }
        }
};
 
