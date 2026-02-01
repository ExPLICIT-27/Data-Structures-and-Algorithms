#include <bits/stdc++.h>

using namespace std;


// class Node{
//     public:
//         int u, v, w;

//         Node(int u, int v, int w){
//             this->u = u;
//             this->v = v;
//             this->w = w;
//         }
// };
// struct Comparator{
//     bool operator()(const Node &a, const Node &b) const {
//         return a.w < b.w;
//     }
// };
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> G(n);

        for(auto &e : edges){
            G[e[0]].push_back({e[1], e[2]});
            G[e[1]].push_back({e[0], 2*e[2]});
        }
    
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        pq.push({0, 0});
        while(!pq.empty()){
            auto [t, u] = pq.top();
            pq.pop();

            for(auto &[v, w] : G[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};