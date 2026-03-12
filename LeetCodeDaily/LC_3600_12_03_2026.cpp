#include <bits/stdc++.h>

using namespace std;
/*
ill cry, cant believe i solved this 
*/
struct Node{
    int u, s, m;

    Node(){};

    Node(int u, int s, int m) : u(u), s(s), m(m) {};
};
class DSU{
    public:

    vector<int> parent, rank;

    DSU(int n){
        parent.resize(n);
        rank.assign(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int u){
        if(u == parent[u])
            return u;
        return parent[u] = findParent(parent[u]);
    }

    void UBR(int u, int v){
        int u_p = findParent(u);
        int v_p = findParent(v);

        if(u_p == v_p)
            return;
        
        if(rank[u_p] < rank[v_p])
            parent[u_p] = v_p;
        else if(rank[u_p] > rank[v_p])
            parent[v_p] = u_p;
        else{
            parent[v_p] = u_p;
            rank[u_p]++;
        }
    }
};
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        /*
        idea :
        first handle the invalid cases before starting

        if sz(edges) < n - 1 : impossible

        if all the edges in which must[i] = 1 form a cycle, then impossible

        */

        if(edges.size() < n - 1)
            return -1;
        
        vector<vector<Node>> G(n);
        int ans = INT_MAX;
        for(auto &e: edges){
            if(e[3]){
                G[e[0]].push_back(Node(e[1], e[2], e[3]));
                G[e[1]].push_back(Node(e[0], e[2], e[3]));
                ans = min(ans, e[2]);
            }
        }

        // check for cycles in the must[i] = 1 components
        vector<bool> vis(n, false);
        auto dfs = [&](auto &&self, int u, int par) -> bool {
            vis[u] = true;

            for(auto &e : G[u]){
                if(e.u == par)
                    continue;
                if(vis[e.u])
                    return true;
                if(!vis[e.u]){
                    if(self(self, e.u, u))
                        return true;
                }
            }

            return false;
        };
        for(int u = 0; u < n; u++){
            if(!vis[u]){
                if(dfs(dfs, u, -1))
                    return -1;
            }
        }



        // sort by s to choose best weights
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b){
            return a[2] > b[2];
        });
        
        /*
        this is the tricky part
        find the components and choose the best pairing for joining each component
        for eg, if e[i] = {2, 3, 9, 0}
        check if 2 and 3 are from different components

        using DSU would be better no?
        yea lesgo w dsu
        wait how do you apply dsu on graphs? by edges? must be by edges
        so ive gotta use the graph G and apply dsu?
        */

        DSU ds(n);
        for(int u = 0; u < n; u++){
            for(auto &node : G[u])
                ds.UBR(u, node.u);
        }
        /*
        kay DSU is done, now ive gotta pick the highest weighted edges
        to connect each disconnected component and keep track of ans along the way
        */
        vector<int> newWeights;
        for(auto &e : edges){
            if(e[3])
                continue;
            int u_p = ds.findParent(e[0]);
            int v_p = ds.findParent(e[1]);

            if(u_p == v_p) // from same component, cant connect will form cycle
                continue;
            
            // connect
            ds.UBR(e[0], e[1]);
            G[e[0]].push_back(Node(e[1], e[2], e[3]));
            G[e[1]].push_back(Node(e[0], e[2], e[3]));
            newWeights.push_back(e[2]);
        }
        /*
        check if graph remains unconnected, then impossible
        */
        int f_p = ds.findParent(0);
        for(int i = 1; i < n; i++){
            if(ds.findParent(i) != f_p)
                return -1;
        }
        /*
        now sort the newly added weights and apply the doubling operation
        */
        sort(newWeights.begin(), newWeights.end());

        for(int i = 0; i < newWeights.size(); i++){
            if(i < k)
                ans = min(ans, 2*newWeights[i]);
            else
                ans = min(ans, newWeights[i]);
        }

        return ans;
    }
};