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
// binary exponentiation
ll binexp(ll a, ll b, ll M){
    ll ans = 1;

    while(b){
        if(b & 1)
            ans = (ans*a)%M;
        b >>= 1;
        a = (a * a)%M;
    }

    return ans;
}
int n, m;
vector<vll> dp;
void update(int row, int currmask, int nextmask, int col){
    if(row == n){
        dp[col + 1][nextmask] = (dp[col][currmask] + dp[col + 1][nextmask])%MOD;
        return;
    }
    
    // if curr row is occupied, move ahead
    if(currmask & (1 << row))
        update(row + 1, currmask, nextmask, col);
    else{
        // go for horizontla tile
        update(row + 1, currmask, (nextmask | (1 << row)), col);
        // chck if we can do vertical
        if(row + 1 < n && !(currmask & (1 << (row + 1))))
            update(row + 2, currmask, nextmask, col);
    }
}
void solve(){
    cin >> n >> m;


    /*
    another bitmasks dp problem
    logic:
    fill column by column basically
    if we decide to put a horizontal tile, itll affect the next column
    only col i+1 gets affected when we are working at col i
    so a column can be in different states depending on what was used in the previous column
    so the states into consideration must be current column, if the row at this column is blocked due to the previous col horizontal placement or not

    so basically a bit mask where ith bit represents if ith row is blocked out or not

    now answer will be in the last + 1th column with bitmask value 0 (every single row of the column is free indicating no horizontal blocks used in the last column)
    */

    dp.resize(m + 1, vll(1 << n, 0));

    // number of ways to place tiles such that the entire first col is free = 1 
    dp[0][0] = 1;

    for(int i = 0; i < m; i++){
        for(int mask = 0; mask < (1 << n); mask++){
            // check if i can reach this state from b4
            if(dp[i][mask])
                update(0, mask, 0, i);

        }
    }

    cout << dp[m][0] << nline;
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