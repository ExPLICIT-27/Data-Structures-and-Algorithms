#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int src, int tar, int k) {
        /*
        feels like binary search on weight
        */
        vector<vector<pair<int, int>>> G(n);

        for(auto &e : edges){
            int u = e[0], v = e[1], w = e[2];

            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }

        // if(src == tar)
        //     return 0;
        /*
        find a path such that the maximum weight in that path is minimum
        */

        // check if src is connected to tar
        vector<bool> vis(n, false);
        int M = 1e9 + 1;
        auto dfs = [&](auto &&self, int u) -> void {
            vis[u] = true;
            for(auto &p : G[u]){
                if(!vis[p.first] && p.second <= M)
                    self(self, p.first);
            }
        };

        dfs(dfs, src);
        
        if(!vis[tar])
            return -1;

        
        int L = 0, R = 1e9;
        int ans = -1;
        while(L <= R){
            M = L + (R - L)/2;
            
            vector<int> heavy(n, INT_MAX);
            heavy[src] = 0;

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            pq.push({0, src});

            while(!pq.empty()){
                auto [d, u] = pq.top();
                pq.pop();

                if(heavy[u] < d)
                    continue;
                
                for(auto &[v, w] : G[u]){
                    int adder = 0;
                    if(w > M)
                        adder++;

                    if(heavy[v] > d + adder){
                        heavy[v] = d + adder;
                        pq.push({heavy[v], v});
                    }
                } 
            }

            if(heavy[tar] <= k){
                R = M - 1;
                ans = M;
            }
            else
                L = M + 1;
        }

        return ans;
    }
};