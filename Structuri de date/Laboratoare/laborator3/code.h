    #include <iostream>
    #ifndef __STACK__H
    #define __STACK__H
    #define nr 100
    // Primul argument al template-ului este tipul de date T
    // Al doilea argument este dimensiunea maxim a stivei N
    template<typename T, int N>
    class Stack {
         	public:
    		// constructor
    		Stack() {
    			// TODO: initializari
    			m = -1;
    		}

    		// destructor
    		~Stack() {
    			// TODO: eliberare resurse, daca este cazul
    		}

    		// operator de adaugare
    		void push(T x) {
    			// TODO: verificari, implementare
    			if (m >= nr - 1) {
                std::cout<<"Eroare, stiva plina.\n";
                return;
            }
            m++;
            v[m] = x;

    		}

    		// operatorul de stergere
    		T pop() {
    			// TODO: verificari, implementare
    			if (isEmpty()) {
                std::cout<<"Eroare,stiva goala.\n";
                T x;
                return x;
            }
            T x = v[m];
            m--;
            return x;
    		}

    		// operatorul de consultare
    		T peek() {
    			// TODO: verificari, implementare
    			  if (isEmpty()) {
                std::cout<<"Eroare , stiva goala.\n";
                T x;
                return x;
            }
            return v[m];
    		}

    		// operatorul de verificare dimensiune
    		int isEmpty() {
    			// TODO: implementare
    			return (m < 0);
    		}

    	private:
    		// vectorul de stocare
    		T v[nr];

    		// pozitia in vector a varfului stivei
    		int m;
    };

    #endif // __STACK__H

