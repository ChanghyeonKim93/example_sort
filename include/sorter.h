#ifndef _SORTER_H_
#define _SORTER_H_
#include <iostream>
#include <vector>

#define SWAP(a,b,temp) {temp=a;a=b;b=temp;}
class Sorter{
public:
    Sorter();
    ~Sorter();

    void selectionSort(std::vector<int>& numbers);
    void insertionSort(std::vector<int>& numbers);
    void bubbleSort(std::vector<int>& numbers);
    void mergeSort(std::vector<int>& numbers);

private:
    void mergeSortSubRoutine(std::vector<int>& numbers, int idx_start, int idx_end);

};

#endif