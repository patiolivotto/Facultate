#include <iostream>
#include "coada.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
FILE * f=fopen("numere.in","rt");
Queue <int,100> c0,c1,c2,c3,c4,c5,c6,c7,c8,c9,coada;
int x,p,t;
fscanf(f,"%d",&x);
while (x!=0){
    coada.enqueue(x);
    fscanf(f,"%d",&x);
}
p=10;
t=1;
do {
while (!coada.isEmpty()) {
    if ((coada.front()/t%p)==0) { c0.enqueue(coada.dequeue()); }
    if ((coada.front()/t%p)==1) { c1.enqueue(coada.dequeue()); }
    if ((coada.front()/t%p)==2) { c2.enqueue(coada.dequeue()); }
    if ((coada.front()/t%p)==3) { c3.enqueue(coada.dequeue()); }
    if ((coada.front()/t%p)==4) { c4.enqueue(coada.dequeue()); }
    if ((coada.front()/t%p)==5) { c5.enqueue(coada.dequeue()); }
    if ((coada.front()/t%p)==6) { c6.enqueue(coada.dequeue()); }
    if ((coada.front()/t%p)==7) { c7.enqueue(coada.dequeue()); }
    if ((coada.front()/t%p)==8) { c8.enqueue(coada.dequeue()); }
    if ((coada.front()/t%p)==9) { c9.enqueue(coada.dequeue()); }
}
while (!c0.isEmpty()){coada.enqueue(c0);}
while (!c1.isEmpty()){coada.enqueue(c1);}
while (!c2.isEmpty()){coada.enqueue(c2);}
while (!c3.isEmpty()){coada.enqueue(c3);}
while (!c4.isEmpty()){coada.enqueue(c4);}
while (!c5.isEmpty()){coada.enqueue(c5);}
while (!c6.isEmpty()){coada.enqueue(c6);}
while (!c7.isEmpty()){coada.enqueue(c7);}
while (!c8.isEmpty()){coada.enqueue(c8);}
while (!c9.isEmpty()){coada.enqueue(c9);}
t=t*10;
}while (!(c0.isEmpty()&&c1.isEmpty()&&c2.isEmpty()&&c3.isEmpty()&&
c4.isEmpty()&&c5.isEmpty()&&c6.isEmpty()&&c7.isEmpty()&&c8.isEmpty()&&c9.isEmpty()));


return 0;
}
