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

void solve(vector<vector<char>> &P, int n){
    // dp[row][col][reds]

    int rows = 3, cols = n, reds = n;
    vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(reds + 1, 0)));
    for(int i = 0; i < 3; i++){
        if(P[i][0] != 'r')
            dp[i][0][0] = 1;
        else
            dp[i][0][1] = 1;
    }
    for(int j = 1; j < cols; j++){
        for(int i = 0; i < 3; i++){
            for(int r = 0; r <= reds; r++){
                if(P[i][j] == 'r'){
                    if(r - 1 >= 0){
                        for(int k = 0; k < 3; k++){
                            if(k == i)
                                continue;
                            dp[i][j][r] += dp[k][j - 1][r - 1];
                        }
                    }
                }
                else{
                    for(int k = 0; k < 3; k++){
                        if(k == i)
                            continue;
                        dp[i][j][r] += dp[k][j - 1][r];
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 3; i++){
        for(int r = 0; r <= reds; r += 2)
            ans += dp[i][cols - 1][r];
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < cols; j++){
            for(int r = 0; r <= reds; r++)
                cout << dp[i][j][r] << " ";
            cout << nline;
        }
    }
    cout << ans << nline;
}
int main(){
    // fastio;
    // int T;
    // cin >> T;
    // while(T--){
    //     solve();
    // }
    vector<vector<char>> P = {{'r', 'g', 'r', 'b', 'b', 'r', 'b'}, 
    {'g', 'r', 'r', 'g', 'r', 'g', 'r'}, 
    {'g', 'g', 'g', 'r', 'g', 'r', 'r'}};
    // vector<vector<char>> P = {
    //     {'g', 'g', 'r', 'g', 'b', 'g'},
    //     {'g', 'r', },
    //     {'g', 'g', 'g', 'r', 'r', 'g'}
    // };
    solve(P, 7);
    return 0;
}