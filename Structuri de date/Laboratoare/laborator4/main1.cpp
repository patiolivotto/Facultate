#include <stdio.h>
#include <iostream>
#include "coada.h"
//program verificare clasa coada

int main(){
Queue <int,100> coada;
coada.enqueue(4);
coada.enqueue(6);
coada.enqueue(129);
std::cout<<coada.dequeue()<<"\n";
std::cout<<coada.front()<<"\n";
std::cout<<coada.dequeue()<<"\n";
std::cout<<coada.dequeue()<<"\n";
std::cout<<coada.dequeue()<<"\n";


return 0;
}
