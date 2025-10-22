/*

If the mail does not belong to an person as of now, assign it to the current person,
else unionize
*/
#include <bits/stdc++.h>

using namespace std;


class DSU{
    public:
        vector<int> rank, parent;
        DSU(int n){
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
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
        }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // map the mails to the indexes and perform union if mail alr exists
        unordered_map<string, int> mailToIdx;

        int n = accounts.size();
        DSU ds(n);

        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(!mailToIdx.count(mail))
                    mailToIdx[mail] = i;
                else
                    ds.UnionByRank(i, mailToIdx[mail]);
            }
        }

        
        
        unordered_map<int, set<string>> finalMap;
        for(int i = 0; i < n; i++){
            int parent = ds.findParent(i);
            finalMap[parent].insert(accounts[i].begin() + 1, accounts[i].end());
        }

        vector<vector<string>> result;
        for(auto pair : finalMap){
            vector<string> el;
            el.push_back(accounts[pair.first][0]);
            for(auto &st : pair.second)
                el.push_back(st);
            result.push_back(el);
        }

        return result;
    }
};
int main(){
    return 0;
}