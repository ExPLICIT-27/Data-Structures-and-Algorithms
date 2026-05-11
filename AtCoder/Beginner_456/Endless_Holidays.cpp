#include <bits/stdc++.h>
using namespace std;

// ---------- Typedefs ----------
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define uset unordered_set
#define umap unordered_map

// ---------- Macros ----------
#define nline '\n'
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define vmax(a) (*max_element(all(a)))
#define vmin(a) (*min_element(all(a)))
#define vsum(a) (accumulate(all(a), 0LL))
#define vsumd(a) (accumulate(all(a), 0.0))

// ---------- Fast IO ----------
#define ExPLICIT_27 ios::sync_with_stdio(false); cin.tie(nullptr)

// ---------- Constants ----------
const ll MOD = 1e9+7;
const ll INF = 1e18;

// ---------- PBDS ----------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using ordered_multiset = tree<pair<T,int>, null_type, less<pair<T,int>>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename K, typename V>
using ordered_map = tree<pair<K,V>, null_type, less<pair<K,V>>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n, m; cin >> n >> m;

    // n - verts, m - edges

    /*
    
    i could start anywhere
    the options are cities where S[0] = o
    i could go to any city from there which is connected to the city i moved to and
    S[1] = o
    at any point if i cant move to a city where the ith day is a holiday, then return false

    how does my journey end?


    ANY pair of cities can be reached from one by traversing some roads
    W <= 10
    */

    vector<vi> G(n);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--, v--;

        G[u].pb(v);
        G[v].pb(u);
    }


    /*
    okay for each node in the bfs, if its a holiday at day i, then i push back (node, i) into the queue
    i push back all neighbors that have holiday as well
    if it any point i cannot move anymore (q becomes empty) return false, otherwise return true if i 
    encounter an already visited state(node, day j)
    */

    int w; cin >> w;

    vector<string> H(n);

    vi st;
    for(int i = 0; i < n; i++){
        cin >> H[i];
        if(H[i][0] == 'o')
            st.pb(i);
    }
    

    /*
    ok logic is to use a 3 state visited array
    where 0 represents unvisited
    1 represents unvisited in path
    2 represents completely explored (at end of dfs of curr node, day we mark it is 2)
    this reduces time needed
    */
    vector<vector<int>> vis(n, vector<int>(w, 0));

    queue<pair<int, int>> q; // u, day

    function<bool(int, int)> dfs;

    dfs = [&](int node, int day) -> bool {
        vis[node][day] = 1;
        int nxt = (day + 1)%w;
        

        if(H[node][nxt] == 'o'){
            if(vis[node][nxt] == 1)
                return true;
            if(dfs(node, nxt))
                return true;
        }
        

        for(int v : G[node]){
            if(vis[v][nxt] == 1)
                return true;
            if(H[v][nxt] == 'o' && vis[v][nxt] == 0){
                if(dfs(v, nxt))
                    return true;
            }
        }
        vis[node][day] = 2;

        return false;
    };

    for(int i : st){
        if(vis[i][0] == 0){
            if(dfs(i, 0)){
                cout << "Yes\n";
                return;
            }
        }
    }

    cout << "No\n";

}

int main(){
    ExPLICIT_27;
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}