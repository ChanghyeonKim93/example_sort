#include "heap.h"

MyHeap::MyHeap() : heap_size_(0) 
{
    max_size_ = 1024;
    data_ = new int[max_size_];
};
MyHeap::~MyHeap(){
    delete[] data_;
};

// max heap
// 자식보다 부모가 항상 크다. 
// 삽입 시, 맨 뒤에 넣고, 부모랑 비교하며 부모보다 내가 크면 바꾸면서 올라감.
// 팝 시, 루트를 빼고, 맨 뒤의 원소를 빼서 루트에서 시작. 
// 자식 중 더 큰 놈을 찾는다. 더큰놈보다 내가 작으면 더큰놈을 올려주고 나는 내려감. 아니면 멈춤.
// idx*2 left child, idx*2+1 right child. idx/2 parent
// 완전 이진트리임. 배열로 구현.

void MyHeap::insert(int i){
    // 맨 뒤에 넣고, 부모노드로 올라가면서 비교해서 교환하며 올라감.
    unsigned long idx_cur = ++heap_size_;
    data_[idx_cur] = i;
    while(idx_cur != 1 && i > data_[idx_cur /2]){
        data_[idx_cur] = data_[idx_cur/2];
        idx_cur /= 2;
    }
    data_[idx_cur] = i;
};  

int MyHeap::pop(){
    // 루트를 삭제하고, 맨 끝 원소를 가져와서 루트에 넣음.
    // 그리고는 더 큰 자식과 비교해서 들어감.
    int res = data_[1];
    int key = data_[heap_size_--];
    int parent = 1;
    int child  = 2;
    while(child <= heap_size_){
        // 더 큰 자식을 찾자.
        if(child < heap_size_ && data_[child] < data_[child+1]){
            ++child;
        }
        // 더 큰 자식보다 key가 크면 중지
        if(key >= data_[child]) break;
        
        //아니라면, 자식을 올려줌
        data_[parent] = data_[child];
        parent= child;
        child *= 2; // 좌측자식으로
    }
    data_[parent] = key;
    
    return res;
};

void MyHeap::showHeap(){
    for(int i = 1; i <= heap_size_; ++i){
        std::cout << "idx:" << i <<", " << data_[i] << "\n";
    }
};

unsigned long MyHeap::getIndexParent(unsigned long idx_now){
    return idx_now/2;
}
unsigned long MyHeap::getIndexLeftChild(unsigned long idx_now){
    return (idx_now << 1);
}
unsigned long MyHeap::getIndexRightChild(unsigned long idx_now){
    return (idx_now >> 1);
}