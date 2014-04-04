template <typename T>
class Queue {
private:
	LinkedList<T> queueList;
public:
	//functia de adaugare elemente de tip `T` in coada
	void enqueue(T e){
		queueList.addLast(e);
		};
	//functia de a scoate elemente din coada	
	T dequeue(){
		if (isEmpty()) {
			std::cout<<"eroare 1.1: coada goala\n";
			T x;
			return x;
		}
		struct Node<T> *p;
		p = queueList.pFirst;
		T x=p->value;
		queueList.removeFirst();
		return x;
	};
	//functia de returnare a primului element din coada	
	T front(){
		if (isEmpty()) {
			std::cout<<"eroare 1.2: coada goala\n";
			T x;
			return x;
		}
		struct Node<T> *p;
		p = queueList.pFirst;
		return p->value;
	};
	//functia ce verifica starea cozii	
	int isEmpty(){
		return queueList.isEmpty();
	};
};
