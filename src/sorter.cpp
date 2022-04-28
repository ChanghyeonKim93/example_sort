#include "sorter.h"

Sorter::Sorter(){

};

Sorter::~Sorter(){

};

void Sorter::selectSort(std::vector<int>& numbers){
    int n = numbers.size();
    
    for(int i = 0; i < n; ++i) {
        int& cur_num = numbers[i];

        for(int j = i+1; j < n; ++j) {
            if(cur_num > numbers[j]) {
                int tmp      = numbers[j];
                numbers[j] = cur_num;
                cur_num    = tmp;
            }
        }
    }
};

void Sorter::insertSort(std::vector<int>& numbers){
    int n = numbers.size();
    
    for(int i = 1; i < n; ++i) {
        int cur_num = numbers[i];

        for(int j = 0; j < i; ++j) {
            if(cur_num < numbers[j]) {
                while(j < i){
                    numbers[j+1] = numbers[j];
                }
                numbers[j] = cur_num;
            }
        }
    }
};