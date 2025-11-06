// 2 solutions -> one just find disconnected comps, other DSU
#include <bits/stdc++.h>

using namespace std;


// no dsu
class Solution1 {
public:
    vector<int> processQueries(int c, vector<vector<int>>& conns, vector<vector<int>>& queries) {
        unordered_map<int, int> compMap;
        vector<vector<int>> adjList(c + 1);


        for(auto &e: conns){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        int cnt = 0;
        vector<set<int>> components;
        vector<bool> vis(c + 1, false);
        for(int i = 1; i <= c; i++){
            if(!vis[i]){
                compMap[i] = cnt;
                queue<int> q;
                q.push(i);
                set<int> t;
                t.insert(i);
                while(!q.empty()){
                    auto u = q.front();
                    q.pop();
                    compMap[u] = cnt;
                    for(int v : adjList[u]){
                        if(!vis[v]){
                            vis[v] = true;
                            q.push(v);
                            t.insert(v);
                        }
                    }
                }
                components.push_back(t);
                cnt++;
            }
        }
        vector<int> res;
        for(auto &q : queries){
            if(q[0] == 1){
                if(components[compMap[q[1]]].count(q[1]))
                    res.push_back(q[1]);
                else if(components[compMap[q[1]]].empty())
                    res.push_back(-1);
                else{
                    auto it = components[compMap[q[1]]].begin();
                    res.push_back(*it);
                }
            }
            else{
                components[compMap[q[1]]].erase(q[1]);
            }
        }
        return res;
    }
};

// dsu ; much faster
class DSU{
    public:
    vector<int> parents, rank;
    DSU(int n){
        parents.resize(n + 1);
        for(int i = 0; i <= n; i++)
            parents[i] = i;
        rank.resize(n + 1, 0);
    }

    int findParent(int u){
        if(parents[u] == u)
            return u;
        return parents[u] = findParent(parents[u]);
    }

    void Union(int u, int v){
        int up = findParent(u);
        int vp = findParent(v);
        if(up == vp)
            return;
        if(rank[up] > rank[vp]){
            parents[vp] = up;
            rank[up]++;
        }
        else{
            parents[up] = vp;
            rank[vp]++;
        }
    }
};
class Solution2 {
public:
    vector<int> processQueries(int c, vector<vector<int>>& conns, vector<vector<int>>& queries) {
        vector<vector<int>> adjList(c + 1);
        DSU ds(c);

        for(auto &e: conns){
            ds.Union(e[0], e[1]);
        }

        int cnt = 0;
        unordered_map<int, set<int>> compMap;
        for(int i = 1; i <= c; i++)
            compMap[ds.findParent(i)].insert(i);
        
        vector<int> res;
        for(auto &q : queries){
            int root = ds.findParent(q[1]);
            if(q[0] == 1){
                if(compMap[root].count(q[1]))
                    res.push_back(q[1]);
                else if(compMap[root].empty())
                    res.push_back(-1);
                else{
                    auto it = compMap[root].begin();
                    res.push_back(*it);
                }
            }
            else{
                compMap[root].erase(q[1]);
            }
        }
        return res;
    }
};