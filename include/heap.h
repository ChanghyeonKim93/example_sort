#ifndef _HEAP_H_
#define _HEAP_H_

#include <iostream>

// class MyHeap{
// public:
//     MyHeap();
//     ~MyHeap();

//     void insert(int i);
//     int pop();
//     void showHeap();

// private:
//     unsigned long heap_size_;
//     unsigned long max_size_;    
//     int* data_;

//     inline unsigned long getIndexParent(unsigned long idx_now);
//     inline unsigned long getIndexLeftChild(unsigned long idx_now);
//     inline unsigned long getIndexRightChild(unsigned long idx_now);
// };

// Cache line size: 64 bytes
// L3 Cache size : 4 MB 
struct Node{ // 4 byte, 4 byte
    float key;
    int   id;
    Node(){
        key = -1;
        id  = -1;
    };
    Node(float key_){
        key = key_;
        id  = 0;
    };

};

class MyHeap{
public:
    MyHeap();
    ~MyHeap();

    void insert(const Node& input);
    Node pop();

    void showAll();

private:
    unsigned long heap_size_;
    unsigned long MAX_HEAP_SIZE_;
    Node* arr_;

};


#endif