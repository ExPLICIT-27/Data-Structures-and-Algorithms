/*
Approach
- Contrary to applying djikstra by prioritizing the distances, here i'll have to prioritize 
the number of stops (k) and then update distances accordingly
- since im prioritizing the stops, it increases by 1 each time, hence i will only have
to use a queue for the dijkstra's algorithm
*/
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int u, k, d;
    Node(int u, int k, int d){
        this->u = u, this->k = k, this->d = d;
    }
};
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
    // construct the adjacency list
    vector<vector<pair<int, int>>> adjList(n);
    for(auto flight : flights){
        adjList[flight[0]].push_back({flight[1], flight[2]});
    }

    // initialize dijkstra conditions
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    queue<Node> q;
    q.push({src, 0, 0});

    // start the dijkstra's algorithm
    while(!q.empty()){
        auto node = q.front();
        q.pop();

        if(node.k > k || node.d == INT_MAX) // max stops exceeded or not possible to reach curr node
            continue;
        for(auto [v, d] : adjList[node.u]){
            if(dist[v] > d + node.d){
                dist[v] = d + node.d;
                q.push({v, node.k + 1, dist[v]});
            }
        }
    }
    // return -1 if impossible to reach
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}
int main(){
    return 0;
}