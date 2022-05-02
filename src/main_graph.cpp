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

    int N = 7;
    Graph g(N);
    g.insertEdge(1,2, 2);
    g.insertEdge(1,3, 5);
    g.insertEdge(1,4, 1);
    g.insertEdge(2,4, 2);
    g.insertEdge(2,3, 3);
    g.insertEdge(3,6, 5);
    g.insertEdge(4,3, 3);
    g.insertEdge(4,5, 1);
    g.insertEdge(5,6, 2);
    g.insertEdge(5,3, 1);
    g.showAllEdges();

    //https://hongl.tistory.com/48 문제...
    g.Dijkstra(1);

    std::cout << "Graph ends.\n";
    return 0;
}