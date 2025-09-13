/*
Djikstras wont work for negative weight cycles

Time complexity O(E*log(V))


Derivation of TC

while loop for priority queue/set runs for all vertices V in the worst cose
pop operation = log(size of heap)
iterating over neighbors = worst case V - 1 nodes 
push operation into queue = log(size of queue)

worst case heapsize = V^2 (each neighbor pushes everyone else as everyone is connected)
therefore O(V * (log(heapsize) + (V - 1)*log(heapsize)))

worst case heapsize = V^2
O(V * (log(V^2) * V))
=> O(V^2 * 2 * log(V))
V^2 = E
O(E*log(V))
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> dijkstraPriorityQueue(int V, vector<vector<int>> &edges, int src) {
    
    // build the adjacency list
    vector<vector<pair<int, int>>> adjList(V);
    for(auto edge : edges){
        int u = edge[0], v = edge[1], w = edge[2];
        adjList[u].push_back({v, w});
    }
    
    // initialize the result array
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    // min heap for obtaining the shortest distance node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});
    
    // start the djikstra algorithm
    while(!pq.empty()){
        auto [d, u] = pq.top();
        if(d == INT_MAX)
            break;
        pq.pop();
        
        for(auto [v, w] : adjList[u]){
            if(d + w < dist[v]){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    // return the result
    return dist;
}

// using sets ; this is slightly faster and more performant as it deletes unnecessary used states

vector<int> dijkstraSets(int V, vector<vector<int>> &edges, int src){

    // construct the adjList
    vector<vector<pair<int, int>>> adjList(V);

    for(auto edge : edges){
        int u = edge[0], v = edge[1], w = edge[2];
        
        adjList[u].push_back({v, w});
    }

    // initialize dijkstra conds, this time using a set
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    set<pair<int, int>> st;

    st.insert({0, src});

    // begin the alogrithm

    while(!st.empty()){
        auto [d, u] = *(st.begin());
        if(d == INT_MAX) // cannot travel any further
            break;
        st.erase({d, u});

        for(auto [v, w] : adjList[u]){
            if(d + w < dist[v]){
                if(dist[v] != INT_MAX){
                    st.erase({dist[v], v}); // this is the optimization; especially good for large graphs with several connected components
                }
                dist[v] = d + w;
                st.insert({dist[v], v});
            }
        }
    }
    // return the result
    return dist;
}
int main(){
    return 0;
}