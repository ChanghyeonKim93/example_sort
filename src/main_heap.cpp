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
    
    heap.insert(Node(1.42346));
    heap.insert(Node(2.12346));
    heap.insert(Node(1.76));
    heap.insert(Node(0.28));
    heap.insert(Node(9.11));
    heap.insert(Node(4.11));
    heap.insert(Node(7.11));
    heap.insert(Node(14.91));
    heap.insert(Node(14.21));
    heap.insert(Node(14.31));
    heap.insert(Node(14.71));
    heap.insert(Node(14.81));

    heap.showAll();
    std::cout <<"\n\n";

    std::cout << heap.pop().key <<std::endl;
    std::cout << heap.pop().key <<std::endl;
    std::cout << heap.pop().key <<std::endl;
    std::cout << heap.pop().key <<std::endl;
    std::cout << heap.pop().key <<std::endl;
    std::cout << heap.pop().key <<std::endl;
    std::cout << heap.pop().key <<std::endl;
    std::cout << heap.pop().key <<std::endl;
    std::cout << heap.pop().key <<std::endl;
    std::cout << heap.pop().key <<std::endl;
    std::cout << heap.pop().key <<std::endl;
    std::cout << heap.pop().key <<std::endl;
    heap.showAll();

    std::cout << "heap ends.\n";
    return 0;
};
