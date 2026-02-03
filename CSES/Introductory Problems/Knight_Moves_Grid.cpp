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
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

// ---------- Loops ----------
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define repd(i,a,b) for (int i = (a); i >= (b); i--)

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
bool isValid(int x, int y, int n){
    return x >= 0 && x < n && y >= 0 && y < n;
}
void solve(){
    int n;
    cin >> n;

    vector<vll> G(n, vll(n));
    vector<vector<bool>> V(n, vector<bool>(n, false));

    V[0][0] = true;
    G[0][0] = 0;

    int dirx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int diry[] = {1, -1, 1, -1, 2, -2, 2, -2};

    queue<pii> Q;
    Q.push({0, 0});

    while(!Q.empty()){
        auto [x, y] = Q.front();
        Q.pop();

        for(int i = 0; i < 8; i++){
            int nx = x + dirx[i];
            int ny = y + diry[i];

            if(isValid(nx, ny, n) && !V[nx][ny]){
                G[nx][ny] = G[x][y] + 1;
                V[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << G[i][j] << " ";
        cout << nline;
    }
}
int main(){
    fastio;
    solve();
    // int T;
    // cin >> T;
    // while(T--){
    //     solve();
    // }

    // return 0;
}