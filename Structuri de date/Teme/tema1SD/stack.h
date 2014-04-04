template <typename T>
class Stack {
	public:
	//functia de adugare elemente in stiva 
		void push(T x){
			stackList.addFirst(x);
			};
	//functia de a scoate elemente din stiva prin returnarea valorii si stergere	
		T pop(){
			if (isEmpty()) {
				std::cout<<"Eroare 1.1: stiva goala!\n";
				T x;
				return x;
				}
			T x=stackList.pFirst->value;
			stackList.removeFirst();
			return x;
			};
	//functia ce returneaza primul element din stiva
		T peek(){
			if (isEmpty()) {
				std::cout<<"Eroare 1.2: stiva goala!\n";
				T x;
				return x;
				}
			T x=stackList.pFirst->value;
			return x;
			};
	//functia ce verifica starea stivei
		int isEmpty(){
			return stackList.isEmpty();
			};
			 
	private:
	// vectorul de stocare
		LinkedList<T> stackList;
};
