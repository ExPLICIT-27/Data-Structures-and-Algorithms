/*
Core logic required : 
- merging the neighbors using DSU 
- keeping track of the number of components
*/
#include <bits/stdc++.h>

using namespace std;

class DSU{
    public:
        vector<int> rank, parent;
        int components; // additional instance to keep track of the components
        DSU(int n){
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            components = 0;
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
            else if(rank[u_p] < rank[v_p]){
                parent[u_p] = v_p;
            }
            else{
                parent[v_p] = u_p;
                rank[u_p]++;
            }
            components--;
        }
};
bool isValid(int i, int j, int n, int m){
	return (i >= 0 && i < n && j >= 0 && j < m);
}
vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){

    // set up the grid
	vector<vector<int>> grid(n, vector<int>(m, 0));
    // dirn arrays to check components to be merged
	int dirx[] = {0, 0, -1, 1};
	int diry[] = {1, -1, 0, 0};
	vector<int> result;
    // DSU set up
	DSU ds(n*m + 1);
    // onlne query processing -> i believe its online when you process it on the go, else offline
	for(auto &qi : q){
		int x = qi[0], y = qi[1];
        // if its a repeated query, just move on
		if(grid[x][y]){
            result.push_back(ds.components);
            continue;
        }
        grid[x][y] = 1;
        ds.components++;

        // check for mergeable components
		for(int i = 0; i < 4; i++){
			int u = x + dirx[i];
			int v = y + diry[i];
			if(isValid(u, v, n, m) && grid[u][v]){
				ds.UnionByRank(u*m + v, x*m + y);
			}
		}
		result.push_back(ds.components);
	}
	return result;
}