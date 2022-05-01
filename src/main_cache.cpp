#include <iostream>
#include <vector>
#include <algorithm>
#include "timer.h"

int main(){
    std::cout << "cache start.\n";

    int data_size = 64*1024*1024;
    int max_test_step = 64;
    int* data = new int[data_size];

    for(int k = 1; k < max_test_step; ++k) {
        std::cout << k <<", ";
        float time_sum = 0;
        int trials = 0;
        for(int m = 0; m < 100; ++m){
            timer::tic();
            for(int i = 0; i < data_size; i += k){
                *(data+i) /= 3;

            }
            time_sum += timer::toc(0);
            ++ trials;
        }
        std::cout << time_sum/(float)trials <<std::endl;
    }

    delete[] data;

    
    std::cout << "cache ends.\n";
    return 0;
}
