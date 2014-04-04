#include "coada.h"
template <typename T, int N>
class Stack {
private:
    Queue <T,N> coada1,coada2;
public:
    Stack(){
        //constructor
    }

    T push(T x){
        if (coada1.size==N) {
            std::cout<<"Eroare 1:Stiva plina!\n";
            return 0;
        }
        coada1.enqueue(x);
    }
    T pop(){
        if (coada1.isEmpty()){
            std::cout<<"Eroare 2:Stiva goala!\n";
            return 0;
        }
        while ((!coada1.isEmpty())&&(coada1.head+1<coada1.tail)){
            coada2.enqueue(coada1.dequeue());
        }
        T x=coada1.dequeue();
        while (!coada2.isEmpty()){
            coada1.enqueue(coada2.dequeue());
        }
        return x;
    }
    T peek(){
        if (coada1.isEmpty()){
            std::cout<<"Eroare 3:Stiva goala!\n";
            return 0;
        }
       while ((!coada1.isEmpty())&&(coada1.head+1<coada1.tail)){
            coada2.enqueue(coada1.dequeue());
        }
        T x=coada1.front();
        coada2.enqueue(coada1.dequeue());
        while (!coada2.isEmpty()){
            coada1.enqueue(coada2.dequeue());
        }
        return x;
    }

};
