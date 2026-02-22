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
string helper(int i, int j, int n, vector<string> &G, vector<vector<string>> &dp){
    if(i >= n || j >= n)
        return string(1, 'Z' + 1);
    if(i == n - 1 && j == n - 1)
        return string(1, G[n - 1][n - 1]);
    
    if(!dp[i][j].empty())
        return dp[i][j];

    return dp[i][j] = string(1, G[i][j]) + min(helper(i + 1, j, n, G, dp), helper(i, j + 1, n, G, dp));
}
void solve(){
    int n; cin >> n;


    vector<string> G(n);


    for(auto &s : G)
        cin >> s;
    

    // any standard dp solution will TLE or MLE, this is basically a greedy + BFS solution


    // vector<string> prev(n + 1, string(1, 'Z' + 1)), curr(n + 1, string(1, 'Z' + 1));

    // prev[n - 1] = curr[n - 1] = string(1, G[n - 1][n - 1]);

    // for(int i = n - 1; i >= 0; i--){
    //     for(int j = n - 1; j >= 0; j--){
    //         if(i == n - 1 && j == n - 1)
    //             continue;

    //         string c1 = string(1, G[i][j]) + prev[j], c2 = string(1, G[i][j]) + curr[j + 1];

    //         curr[j] = min(c1, c2);
            
    //     }
    //     prev = curr;
    // }

    // cout << prev[0] << nline;
    
    // use bfs strategy to optimize

    /*
    We traverse diagonally to build the smallest one
    Since its lexicographically largest, we always try to move in the direction of the shorter string
    if there are multiple same characters we store all of them for the next level and continue the strategy
    */

    cout << G[0][0];

    vector<pii> curr_level;
    curr_level.emplace_back(0, 0);

    // number of elements in the diagonal is 2*n - 2
    for(int i = 0; i < 2*n - 2; i++){
        vector<pii> nxt_level;

        char printletter = 'Z' + 1;
        for(auto &[x, y] : curr_level){
            if(x + 1 < n && G[x + 1][y] <= printletter){
                if(G[x + 1][y] < printletter)
                    nxt_level.clear();
                nxt_level.emplace_back(x + 1, y);
                printletter = G[x + 1][y];
            }
            if(y + 1 < n && G[x][y + 1] <= printletter){
                if(G[x][y + 1] < printletter)
                    nxt_level.clear();
                nxt_level.emplace_back(x, y + 1);
                printletter = G[x][y + 1];
            }
        }
        curr_level = nxt_level;
        cout << printletter;
        // erase all the same pairs of x, y -> took this from the editorial
        curr_level.erase(unique(all(curr_level)), curr_level.end());
    }

    cout << "\n";
    
}
int main(){
    fastio;
    solve();
    // int T;
    // cin >> T;
    // while(T--){
    //     solve();
    // }

    return 0;
}