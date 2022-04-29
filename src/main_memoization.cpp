#include <iostream>
#include <vector>
#include <algorithm>

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

unsigned long long fib_memo[10000]={0,};
unsigned long long fib(int n){
    for(int i = 1; i <= n; ++i){
        if(i < 3) fib_memo[i] = 1;
        else fib_memo[i] = fib_memo[i-1] + fib_memo[i-2];
        std::cout << fib_memo[i] << std::endl;
    }
    return fib_memo[n];
};

int main(){
    std::cout << "Memo start.\n";

    timer::tic();
    std::cout << fib(33) << std::endl;
    timer::toc(true);

    int n = 10;
    std::vector<int> randnum = randGenerator(n);
    std::vector<std::pair<int,int>> matsize;
    for(int i = 0; i < n-1; ++i){
        matsize.push_back(std::make_pair(randnum[i],randnum[i+1]));
    }

    

    std::cout << "Memo ends.\n";
    return 0;
}