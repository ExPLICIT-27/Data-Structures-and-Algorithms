#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        /*
        each node has a weight
        0(1) -> 1(0) -> 2(1)

        okay understood the qn
        wtf, <= 13 nodes i can 2^13
        2^13 will generate each subset
        can i just bruteforce??
        */

        
        int n = nums.size();
        int ans = 0;
        for(int i = 1; i < (1 << n); i++){
            vector<bool> vis(n, false);
            int tot = 0, src;
            for(int j = 0; j < n; j++){
                if((i >> j) & 1){
                    tot++;
                    src = j;
                    vis[j] = true;
                }
            }

            vector<vector<int>> G(n);
            for(auto &e : edges){
                if(vis[e[0]] && vis[e[1]]){
                    G[e[0]].push_back(e[1]);
                    G[e[1]].push_back(e[0]);
                }
            }
            
            
            
            vis.assign(n, false);
            queue<int> q;
            q.push(src);
            vis[src] = 1;
            int cnt = 1, par = nums[src];
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v : G[u]){
                    if(!vis[v]){
                        cnt++;
                        par ^= nums[v];
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }

            if(cnt == tot && par == 0)
                ans++;
        }

        return ans;
        
        
    }
};