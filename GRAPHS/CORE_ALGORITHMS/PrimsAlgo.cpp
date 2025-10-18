#include <bits/stdc++.h>

using namespace std;


// minimum spanning tree using priority queues -> O((E + V)*LOG(V))

int PrimsMinimumSum(int V, vector<vector<int>> &edges){
    vector<vector<pair<int, int>>> adjList(V);

    // make adjacency list out of edge list
    for(auto &edge : edges){
        int u = edge[0],  v = edge[1], w = edge[2];
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    
    // set up priority queue = {weight, node} : min heap for weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, 
    greater<pair<int, int>>> pq;
    pq.push({0, 0});
    
    // core algorithm
    int msum = 0;
    vector<bool> vis(V, false);
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        // if already included in MST, continue
        if(vis[it.second]) continue;
        vis[it.second] = true;
        msum += it.first;
        for(auto &v : adjList[it.second]){
            if(!vis[v.first]){
                pq.push({v.second, v.first});
            }
        }
    }
    return msum;
}
// same code, with added MST construction
int PrimsMST(int V, vector<vector<int>> &edges){
    vector<vector<pair<int, int>>> adjList(V);
    for(auto &edge : edges){
        int u = edge[0],  v = edge[1], w = edge[2];
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    
    priority_queue<vector<int>, vector<vector<int>>, 
    greater<vector<int>>> pq;
    pq.push({0, 0, -1});
    
    vector<vector<int>> MST;
    vector<bool> vis(V, false);
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        if(vis[it[1]]) continue;
        vis[it[1]] = true;
        MST.push_back({it[2], it[1], it[0]});
        for(auto &v : adjList[it[1]]){
            if(!vis[v.first]){
                pq.push({v.second, v.first, it[1]});
            }
        }
    }

    int msum = 0;
    for(auto &mst : MST){
        if(mst[0] == -1)
            continue;
        msum += mst[2];
        cout << mst[0] << " -> " << mst[1] << " : " << mst[2] << endl;
    }
    
    return msum;
}


int main(){
    vector<vector<int>> edges = {{0, 1, 5},
                      			{1, 2, 3},
                      			{0, 2, 1}};
    int sm = PrimsMST(3, edges);
    cout << sm << endl;
    return 0;
}