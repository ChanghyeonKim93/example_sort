#include <iostream>
#include <vector>
#include <algorithm>

#include "graph.h"
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
    std::cout << "Graph start.\n";
    std::cout << "Graph ends.\n";
    return 0;
}