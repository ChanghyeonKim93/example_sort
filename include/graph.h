#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <iostream>
#include <memory>
#include <queue>

/*
그래프 이용하는 경우.
- 하나의 정점 -> 다른 하나의 정점까지의 최단 경로 문제 ()
- 하나의 정점 -> 모든 정점까지의 최단 거리 (다익스트라)
- 하나의 목적지로가는 모든 최단 경로 (플로이드-워셜)
- 모든 최단경로 구하기 
*/

// 공부해야하는것.
// - 다익스트라 알고리즘
// - 플로이드-워셜 알고리즘

struct Node{
    float weight;
    unsigned long vertex;
    Node* next;
    Node(){weight=0; vertex = -1; next = nullptr;};
    Node(float weight_, unsigned long vertex_){ weight = weight_; vertex = vertex_; next = nullptr;};
};

struct AdjList {
    Node* head;
    unsigned long n_list;
    AdjList(){ head = nullptr; n_list = 0;};
};

struct AdjGraph {
    AdjList* vertices;
    unsigned long n_vertex;
    AdjGraph(int n) {
        n_vertex = n;
        vertices = new AdjList[n];
    }
};

class Graph{
public:
    Graph(int n);
    ~Graph();

    void insertEdge(int src, int dst, float weight);
    void showAllEdges();

    void Dijkstra(unsigned long n);

private:
    unsigned long n_vertex;
    AdjGraph* g;

};

#endif