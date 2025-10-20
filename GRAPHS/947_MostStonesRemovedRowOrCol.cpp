/*
- main logic is to unionize the columns with the rows by giving them higher indexes
*/
#include <bits/stdc++.h>

using namespace std;

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
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int mrow = 0, mcol = 0;
        for(auto &st : stones){
            mrow = max(mrow, st[0]);
            mcol = max(mcol, st[1]);
        }
        DSU ds(mrow + mcol + 1);
        unordered_set<int> nodes;
    
        for(auto &st : stones){
            ds.UnionByRank(st[0], mrow + 1 + st[1]);
            nodes.insert(st[0]);
            nodes.insert(st[1] + 1 + mrow);
        }

        int cnt = 0;
        for(int i : nodes){
            if(ds.findParent(i) == i)
                cnt++;
        }
        return stones.size() - cnt;
    }
};
int main(){
    return 0;
}