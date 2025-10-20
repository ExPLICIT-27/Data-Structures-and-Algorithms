/*
- It is impossible if there are less edges than the number of vertices - 1
- Otherwise it is equal to the number of disconnected components - 1
- Can be found using direct bfs or DSU
*/
#include <bits/stdc++.h>

using namespace std;



// BFS Code
int makeConnectedBFS(int n, vector<vector<int>>& conns) {
    int m = conns.size();
    // base case
    if(m < n - 1)
        return -1;
    
    vector<vector<int>> adjList(n);
    for(auto &c : conns){
        adjList[c[0]].push_back(c[1]);
        adjList[c[1]].push_back(c[0]);
    }

    // driver code
    vector<bool> vis(n, false);
    int result = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            result++;
            vis[i] = true;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v : adjList[u]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
    }

    return result - 1;
}

// DSU Code
class DSU{
    private:
        vector<int> parent, rank;
    public:
        DSU(int n){
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            for(int i = 0; i <= n; i++)
                parent[i] = i;
        }

        int findParent(int u){
            if(u == parent[u])
                return u;
            return parent[u] = findParent(parent[u]);
        }

        void UnionByRank(int u, int v){
            int u_p = findParent(u);
            int v_p = findParent(v);

            if(u_p == v_p) return;

            if(rank[u_p] > rank[v_p]){
                parent[v_p] = u_p;
            }
            else if(rank[u_p] < rank[v_p])
                parent[u_p] = v_p;
            else{
                parent[v_p] = u_p;
                rank[u_p]++;
            }

        }
};

// main driver code using DSU
int makeConnectedDSU(int n, vector<vector<int>>& conns) {
    int m = conns.size();
    if(m < n - 1)
        return -1;
    
    DSU ds(n);

    int result = n;
    for(auto &c : conns){
        int u = c[0],  v = c[1];
        if(ds.findParent(u) != ds.findParent(v)){
            ds.UnionByRank(u, v);
            result--;
        }
    }

    return result - 1;
}
int main(){
    return 0;
}