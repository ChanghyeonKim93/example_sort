#ifndef _HEAP_H_
#define _HEAP_H_

#include <iostream>

class MyHeap{
public:
    MyHeap();
    ~MyHeap();

    void insert(int i);
    int pop();
    void showHeap();

private:
    unsigned long heap_size_;
    unsigned long max_size_;    
    int* data_;

    inline unsigned long getIndexParent(unsigned long idx_now);
    inline unsigned long getIndexLeftChild(unsigned long idx_now);
    inline unsigned long getIndexRightChild(unsigned long idx_now);
};
#endif