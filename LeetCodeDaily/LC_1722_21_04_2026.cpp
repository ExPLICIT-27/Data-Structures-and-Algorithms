#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumHammingDistance(vector<int>& src, vector<int>& tar, vector<vector<int>>& swp) {
        /*
        I can reorder all the elements within each connected component as i please
        gather them and see what i can do
        
        now how do i do it prettily
        */
        int n = src.size();
        
        vector<vector<int>> G(n);

        for(auto &e : swp){
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);

        auto dfs = [&](auto &&self, int u, vector<int> &cmp) -> void {
            vis[u] = true;
            cmp.push_back(u);

            for(int v : G[u]){
                if(!vis[v])
                    self(self, v, cmp);
            }
        };


        int dist = n;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                vector<int> cmp;
                dfs(dfs, i, cmp);
                // I have a component with me
                /*
                extract the nodes present in those components, compare it with what should be there
                */

                unordered_map<int, int> mp;
                for(int u : cmp)
                    mp[src[u]]++;
                

                for(int u : cmp){
                    if(mp[tar[u]] > 0){
                        dist--;
                        mp[tar[u]]--;
                    }
                }
            }
        }

        return dist;
    }
};