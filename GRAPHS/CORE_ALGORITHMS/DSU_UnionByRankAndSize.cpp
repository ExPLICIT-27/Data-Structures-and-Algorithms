/*
Union(node, v)

- Find ultimate parent of (node, v) => (pu, pv)
- Find rank of pu, pv
- Connect smaller rank to larger rank always
- equal rank? - do as you please


Works in O(4*alpha) time, almost constant
*/



#include <bits/stdc++.h>

using namespace std;

// creating a class for the DSU data structure
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
int main(){
    return 0;
}