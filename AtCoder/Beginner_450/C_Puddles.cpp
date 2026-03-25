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

// ---------- PBDS ---------- policy based data strcutures, faster sets and maps
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Ordered Set (no duplicates)
template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

// Ordered Multiset (allows duplicates using unique IDs)
template<typename T>
using ordered_multiset = tree<
    pair<T,int>,
    null_type,
    less<pair<T,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

// Ordered Map (key → value)
template<typename K, typename V>
using ordered_map = tree<
    pair<K,V>,
    null_type,
    less<pair<K,V>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
void solve(){
    // multi source bfs from the borders?
    /*
    all connected components that can be reached will be marked false
    */

    int n, m; cin >> n >> m;

    vector<string> G(n);

    for(int i = 0; i < n; i++)
        cin >> G[i];
    
    // first partition into components
    vector<vector<int>> comp(n, vector<int>(m, -1));

    int cnt = 0;
    int dirx[] = {1, -1, 0, 0};
    int diry[] = {0, 0, 1, -1};
    auto isValid = [&](int u, int v) -> bool {
        return u >= 0 && u < n && v >= 0 && v < m;
    };
    auto dfs = [&](auto &&self, int u, int v) -> void {
        comp[u][v] = cnt;

        for(int k = 0; k < 4; k++){
            int nx = u + dirx[k];
            int ny = v + diry[k];
            if(isValid(nx, ny) && comp[nx][ny] == -1 && G[nx][ny] == '.')
                self(self, nx, ny);
        }
    };

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(G[i][j] == '.' && comp[i][j] == -1){
                dfs(dfs, i, j);
                cnt++;
            }
        }
    }
    vector<bool> ok(cnt, true);
    for(int i = 0; i < n; i++){
        if(G[i][0] == '.')
            ok[comp[i][0]]= false;
        if(G[i][m - 1] == '.')
            ok[comp[i][m - 1]] = false;
    }

    for(int j = 0; j < m; j++){
        if(G[0][j] == '.')
            ok[comp[0][j]] = false;

        if(G[n - 1][j] == '.')
            ok[comp[n - 1][j]] = false;
    }

    int ans = 0;
    for(int i : ok)
        ans += i;
    cout << ans << nline;
}
int main(){
    ExPLICIT_27;
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }

    return 0;
}