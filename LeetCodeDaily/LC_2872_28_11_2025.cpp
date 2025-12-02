#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ans = 0;
    long long dfs(vector<vector<int>> &g, int u, int k, vector<int> &val, int prev){
        long long total = val[u];
        for(int v : g[u]){
            if(v == prev)
                continue;
            total += dfs(g, v, k, val, u);
        }
        if(total%k == 0)
            ans++;
        return total;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> g(n);
        for(auto &e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(g, 0, k, values, -1);
        return ans;
    }
};