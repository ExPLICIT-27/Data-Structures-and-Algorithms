#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Node{

    public:
    
    int u, cost, tax;
    Node(int u, int cost, int tax) : u(u), cost(cost), tax(tax) {}
};
class Solution {
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        
        /*
        roads -> undirected graph
        */

        vector<int> ans(n);


        vector<vector<Node>> G(n);

        for(auto &r : roads){
            int u = r[0], v = r[1], cost = r[2], tax = r[3];

            G[u].push_back(Node(v, cost, tax));
            G[v].push_back(Node(u, cost, tax));
        }
        
        vector<vector<ll>> bestgo(n), bestcome(n);

        auto djikstras = [&](int src, bool reversed) -> vector<ll> {
            vector<ll> dist(n, LLONG_MAX);

            priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
            pq.push({0, src});


            while(!pq.empty()){
                auto [d, u] = pq.top();
                pq.pop();

                if(dist[u] < d)
                    continue;

                for(auto &v : G[u]){
                    ll tcost = d + ((reversed)? 1ll*v.cost*v.tax : v.cost);
                    if(dist[v.u] > tcost){
                        dist[v.u] = tcost;
                        pq.push({dist[v.u], v.u});
                    }
                }
            }

            return dist;
        };

       
        for(int u = 0; u < n; u++){
            bestgo[u] = djikstras(u, false);
            bestcome[u] = djikstras(u, true);
        }

        for(int u = 0; u < n; u++){
            ans[u] = prices[u];
            for(int v = 0; v < n; v++){
                if(u == v)
                    continue;
                ll gocost = bestgo[u][v];
                if(gocost == LLONG_MAX)
                    continue;

                ll comecost = bestcome[v][u];
                

                if(gocost + comecost + prices[v] < ans[u])
                    ans[u] = gocost + comecost + prices[v];
            }
        }
        
        return ans;
    }
};