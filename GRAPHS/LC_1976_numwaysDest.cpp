/*
keep track of number of ways to reach each node, finally return the number of ways to reach the destination node
*/
#include <bits/stdc++.h>
using namespace std;

int mod = int(1e9 + 7); // handle overflow
int countPaths(int n, vector<vector<int>>& roads){

    // construct the adjacency list
    vector<vector<pair<int, long long>>> adjList(n);
    for(auto &road : roads){
        adjList[road[0]].push_back({road[1], road[2]*1LL});
        adjList[road[1]].push_back({road[0], road[2]*1LL}); // undirected graph, bidirectional edge
    }

    // dijkstras condition initialization
    vector<long long> dist(n, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, 0});

    vector<int> numWays(n, 0); // main logic
    numWays[0] = 1;

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();

        for(auto &[v, w] : adjList[u]){
            if(d + w < dist[v]){
                dist[v] = d + w;
                numWays[v] = numWays[u];
                pq.push({dist[v], v});
            }
            else if(d + w == dist[v]){
                numWays[v] = (numWays[v] + numWays[u])%mod;
            }
        }
    }

    return numWays[n - 1];
}
int main(){
    return 0;
}