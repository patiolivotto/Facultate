template <typename T, int N>
class Queue {
private:
	int head;
	int tail;
	int size;
	T queueArray[N];

public:
	// Constructor
	Queue() {
		// TODO:
		head=0;
		tail=0;
		size=0;
	}

	// Destructor
	~Queue() {
		// TODO:
	}

	// Adauga la coada
	void enqueue(T e) {
		// TODO
		if (size==N) {
			std::cout<<"Eroare 1:Coada este plina!";
			return;
			}
		queueArray[tail]=e;
		tail = (tail + 1) % N;
		size++;
	}

	// Extrage din coada
	T dequeue() {
		// TODO:
		if (isEmpty()) {
			std::cout<<"Eroare 2:coada este goala!";
			return 0;
			}
		T x=queueArray[head];
		size--;
		head = ( head + 1 ) % N;
	}

	// Afla primul element
	T front() {
		// TODO:
		if (isEmpty()) {
			std::cout<<"Eroare 3:coada este goala!";
			return 0;
			}
		T x=queueArray[head];
		return x;
	}

	bool isEmpty() {
		// TODO:
		return ( size == 0 );
	}
};
