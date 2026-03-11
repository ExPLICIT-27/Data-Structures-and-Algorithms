#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <climits>
 
#define ll long long
#define nline '\n'
 
using namespace std;
 
 
void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m, k; cin >> n >> m >> k;
 
 
    vector<vector<pair<int, int>>> G(n);
 
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
 
        u--, v--;
 
        G[u].push_back({v, w});
    }
 
 
 
    
    /*
    oke no access to my template :(

    can djikstra provide a solution to this?
 
    my concern for edge modification is the following scenario
 
       1
       |
       |
       2
       /\
      /  \
     3    4
     \    /
      \  /
        5
    
    there are 2 paths from 1 -> 5, disturbing 1-2 edge messes all of it up
 
 
    okay, modified djikstra is the way to go,
    SAME damn logic as last time for half cost path
 
    maintain a dist array of size N*K, 
    now the requirement means for you do update the k-th value if more than k values appear, for the first code lets just sort
    dist[u] every time u is relaxed, it will add an additional k factor to the ans
    T.C = O(M*K*log(N*K))
    */
 
    vector<vector<ll>> dist(n, vector<ll>(k, LLONG_MAX));
 
    auto djikstras = [&](int src) {
        dist[src][0] = 0;
 
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
 
        pq.push({0, src});
 
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
 
            if(u.first > dist[u.second][k - 1])
                continue;
            
            for(auto &p : G[u.second]){
                ll ncost = u.first + p.second;
 
                if(dist[p.first][k - 1] > ncost){
                    dist[p.first][k - 1] = ncost;
                    sort(dist[p.first].begin(), dist[p.first].end());
                    pq.push({ncost, p.first});
                }
            }
        }
    };
 
    djikstras(0);
 
    for(int i = 0; i < k; i++)
        cout << dist[n - 1][i] << " ";
    cout << nline;
 
}
int main(){
    solve();
    return 0;
}