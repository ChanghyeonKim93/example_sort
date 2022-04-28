#include <iostream>
#include <vector>
#include <algorithm>
#include "sorter.h"

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
    std::vector<int> numbers = randGenerator(100);


    Sorter sorter = Sorter();
    // sorter.selectSort(numbers);
    sorter.insertSort(numbers);

    for(auto it : numbers) std::cout << it << std::endl;
    std::cout << "Sorter ends.\n";
    return 0;
}