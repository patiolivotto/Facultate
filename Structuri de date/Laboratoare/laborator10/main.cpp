#include<iostream>
#include "heap.h"


int main(void)
{

    Heap<int> heap(10);

    heap.insert(5);
    heap.insert(4);
    heap.insert(10);
    heap.insert(4);
    heap.insert(3);
    heap.insert(1);
    heap.insert(2); 
    heap.insert(7);
/*
    std::cout << heap.peek() << std::endl;
    std::cout << heap.extractMin() << std::endl;
    std::cout << heap.extractMin() << std::endl;
    std::cout << heap.peek() << std::endl;
    * 
  */
  
  for (int i = 0; i < 8; i++) {
	 // std::cout << heap.peek() << std::endl;
    std::cout << heap.extractMin() << std::endl;
  }
    return 0;
}
