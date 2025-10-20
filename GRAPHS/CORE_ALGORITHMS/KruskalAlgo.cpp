/*
Sort all the edges according to their weight
perform DSU

T.C = O(Elog(E) + E*(4*alpha)) 
*/

#include <bits/stdc++.h>

using namespace std;

// importing the preset, DSU class
class DSU{
    private:
        vector<int> parent, rank, size;
    public:
        DSU(int n){
            parent.resize(n + 1); // account for 1 based indexing
            rank.resize(n + 1, 0);
            size.resize(n + 1, 1); // for union by size

            // default parent;
            for(int i = 0; i <= n; i++)
                parent[i] = i;
        }

        // finding the ultimate parent + path compression
        int findParent(int node){
            if(node == parent[node])
                return node;
        
            return parent[node] = findParent(parent[node]); // assigning is the path compression
        }

        // Main logic : the union by rank function
        void UnionByRank(int u, int v){
            int u_p = findParent(u);
            int v_p = findParent(v);
            
            // already unionized
            if(u_p == v_p) return;

            // always attach lower to higher rank, no change in ranks then
            if(rank[u_p] < rank[v_p])
                parent[u_p] = v_p;
            else if(rank[u_p] > rank[v_p])
                parent[v_p] = u_p;
            else{
                // case of equal ranks, attach either to the other and increase the rank of the one whom it is being attached to
                parent[v_p] = u_p; // v has been attached to u
                rank[u_p]++; // u rank increases
            }
        }

        // union by size logic
        void UnionBySize(int u, int v){
            int u_p = findParent(u);
            int v_p = findParent(v);

            if(size[u_p] > size[v_p]){
                parent[v_p] = u_p;
                size[u_p] += size[v_p]; // increasing the size
            }
            else{
                parent[u_p] = v_p;
                size[v_p] += size[u_p]; // increasing the size 
            }
        }
};

// main solution
int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
    DSU ds(V);
    int res = 0;
    // sort the edges by weight
    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b){
        return a.back() < b.back();
    });

    // perform DSU
    for(auto &e : edges){
        int u = e[0], v = e[1], w = e[2];
        if(ds.findParent(u) != ds.findParent(v)){
            ds.UnionByRank(u, v);
            res += w;
        }
    }

    return res;
}
int main(){
    return 0;
}