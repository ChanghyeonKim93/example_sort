#ifndef _SORTER_H_
#define _SORTER_H_
#include <iostream>
#include <vector>

class Sorter{
public:
    Sorter();
    ~Sorter();

    void selectSort(std::vector<int>& numbers);
    void insertSort(std::vector<int>& numbers);

};

#endif