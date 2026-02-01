#include <bits/stdc++.h>

using namespace std;


#define INF LLONG_MAX
#define ll long long
class Solution {
public:

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>> G(26, vector<ll>(26, INF));

        int n = changed.size();
        for(int i = 0; i < n; i++){
            G[original[i] - 'a'][changed[i] - 'a'] = min(G[original[i] - 'a'][changed[i] - 'a'], 1ll*cost[i]);
        }

        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(G[i][k] != INF && G[k][j] != INF)
                        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }

        ll ans = 0;
        int m = source.size();
        for(int i = 0; i < m; i++){
            if(source[i] == target[i])
                continue;
            if(G[source[i] - 'a'][target[i] - 'a'] == INF){
                return -1;
            }
            ans += G[source[i] - 'a'][target[i] - 'a'];

        }

        return ans;
    }
};