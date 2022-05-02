#include "graph.h"


Graph::Graph(int n)
{
    n_vertex = n;
    g = new AdjGraph(n);
};
Graph::~Graph(){
    delete g;
};

void Graph::insertEdge(int src, int dst, float weight){
    if(src >= n_vertex || dst >= n_vertex) throw std::runtime_error("error!");

    Node* new_node = new Node(weight, dst);
    new_node->next = g->vertices[src].head;
    g->vertices[src].head = new_node;
    g->vertices[src].n_list += 1;
};

void Graph::showAllEdges(){
    std::cout << "Show all edges:\n";
    for(int i = 0; i < n_vertex; ++i){
        std::cout << "[" << i << "] : ";
        Node* ptr = g->vertices[i].head;
        for(int j = 0; j < g->vertices[i].n_list; ++j){
            std::cout << ptr->vertex << " ";
            ptr = ptr->next;
        }
        std::cout <<std::endl;
    }
    std::cout <<std::endl;
};


void Graph::Dijkstra(unsigned long n){
    float* min_dist_table = new float[n_vertex];

    float INF_NUM = 1000000.0;
    for(int i = 0; i < n_vertex; ++i){
        min_dist_table[i] = INF_NUM;
    }
    min_dist_table[n] = 0;

    // initialize dist_table
    for(Node* tmp = g->vertices[n].head; tmp != nullptr; tmp = tmp->next){
        min_dist_table[tmp->vertex] = tmp->weight;
    } 

    // Do while!
    bool* is_visited = new bool[n_vertex];
    for(int i = 0; i < n_vertex; ++i) is_visited[i] = false;
    
    std::cout << " vert : ";
    for(int i = 1; i < n_vertex;++i) std::cout << i << " ";
    std::cout <<std::endl;
    std::cout << " dist : ";
    for(int i = 1; i < n_vertex;++i) std::cout << min_dist_table[i] << " ";
    std::cout <<std::endl;
    std::cout <<std::endl;
    
    struct mycomp{
        bool operator()(std::pair<int,float>& lhs, std::pair<int,float>& rhs){
            return lhs.second > rhs.second;
        };
    };

    std::priority_queue<std::pair<int,float>, std::vector<std::pair<int,float>>, mycomp> pq;

    for(int i = 1; i < n_vertex; ++i){
        pq.push({i, min_dist_table[i]});
    }
    
    while(!pq.empty()){
        std::pair<int,float> node_now = pq.top();
        pq.pop();

        if(is_visited[node_now.first]) continue;
        std::cout <<" NOW position : " << node_now.first << std::endl;

        float dist_now = node_now.second;
        
        // 해당 노드의 인접 노드 중, 방문했던 노드의 기록된 거리보다 지금 + 방문시 거리 값이 낮으면 업데이트.
        // 방문하지 않았던 노드는 지금 노드의 거리 + 현재거리 

        for(Node* tmp = g->vertices[node_now.first].head; tmp != nullptr; tmp = tmp->next){
            if(tmp->weight+dist_now < min_dist_table[tmp->vertex]) 
                min_dist_table[tmp->vertex] = tmp->weight+dist_now;
        }
        is_visited[node_now.first] = true;

        std::cout << " vert : ";
        for(int i = 1; i < n_vertex;++i) std::cout << i << " ";
        std::cout <<std::endl;
        std::cout << " dist : ";
        for(int i = 1; i < n_vertex;++i) std::cout << min_dist_table[i] << " ";
        std::cout <<std::endl;
        std::cout <<std::endl;

        while(!pq.empty()) pq.pop();
        for(int i = 1; i < n_vertex; ++i){
            pq.push({i, min_dist_table[i]});
        }
    }
    

    
};