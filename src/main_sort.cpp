#include <iostream>
#include <vector>
#include <algorithm>

#include "sorter.h"
#include "timer.h"

int myrandom(int i) {return rand()%i;};
std::vector<int> randGenerator(int n) {
    std::vector<int> v;
    srand(time(NULL));
    for(int i = 0; i <= n; ++i){
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end(), myrandom);
    return v;
};

int main(){
    std::cout << "Sorter start.\n";
    int n = 100000;
    std::vector<int> numbers = randGenerator(n);
    std::vector<int> numbers1; numbers1.resize(n); std::copy(numbers.begin(), numbers.end(), numbers1.begin());
    std::vector<int> numbers2; numbers2.resize(n); std::copy(numbers.begin(), numbers.end(), numbers2.begin());
    std::vector<int> numbers3; numbers3.resize(n); std::copy(numbers.begin(), numbers.end(), numbers3.begin());
    std::vector<int> numbers4; numbers4.resize(n); std::copy(numbers.begin(), numbers.end(), numbers4.begin());


    // for(auto it : numbers) std::cout << it << " ";
    // std::cout << std::endl;
    // std::cout << std::endl;

    Sorter sorter = Sorter();
    timer::tic();
    sorter.selectionSort(numbers1);    
    timer::toc(1);

    timer::tic();
    sorter.insertionSort(numbers2);    
    timer::toc(1);

    timer::tic();
    sorter.bubbleSort(numbers3);    
    timer::toc(1);

    timer::tic();
    sorter.mergeSort(numbers4);  
    timer::toc(1);

    // for(auto it : numbers) std::cout << it << " ";
    // std::cout << std::endl;
    // std::cout << std::endl;
    std::cout << "Sorter ends.\n";
    return 0;
}