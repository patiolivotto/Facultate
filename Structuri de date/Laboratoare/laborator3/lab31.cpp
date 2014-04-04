#include <iostream>
#include "code.h"

int main(){
Stack <int,100> a;
a.push(12);
a.push(9);
std::cout<<a.pop()<<"\n";
std::cout<<a.peek()<<"\n";
a.push(22);
std::cout<<a.pop()<<"\n";
std::cout<<a.pop()<<"\n";
std::cout<<a.pop()<<"\n";


return 0;
}
