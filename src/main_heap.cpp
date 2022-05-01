#include <iostream>
#include <vector>
#include <algorithm>
#include "timer.h"
#include "heap.h"

int main(){
    std::cout << "heap start.\n";
    // 루트힙은 1, 왼쪽자식 2 오른쪽자식 3
    // 부모 인덱스 * 2 + 1 오른쪽
    // 부모 인덱스 * 2 왼쪽
    // 자식 인덱스 / 2 부모

    // 힙 원소삽입 : 

    MyHeap heap;
    heap.insert(1);
    heap.insert(5);
    heap.insert(2);
    heap.insert(6);
    heap.insert(9);
    heap.insert(15);
    heap.insert(3);
    heap.insert(111);
    heap.insert(45);

    heap.showHeap();
    std::cout << "pop! : "<< heap.pop() <<std::endl;
    std::cout << "pop! : "<< heap.pop() <<std::endl;
    std::cout << "pop! : "<< heap.pop() <<std::endl;
    std::cout << "pop! : "<< heap.pop() <<std::endl;
    std::cout << "pop! : "<< heap.pop() <<std::endl;
    std::cout << "pop! : "<< heap.pop() <<std::endl;
    std::cout << "pop! : "<< heap.pop() <<std::endl;
    heap.showHeap();


    
    std::cout << "heap ends.\n";
    return 0;
}
