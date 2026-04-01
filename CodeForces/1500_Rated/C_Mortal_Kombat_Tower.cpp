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
int helper(int i, bool isFr, int turns, vector<vector<vi>> &dp, vi &A){
    if(i == sz(A))  
        return 0;
    
    if(dp[i][isFr][turns] != -1)
        return dp[i][isFr][turns];
    
    if(turns == 0){
        isFr = !isFr;
        turns = 2;
    }


    int ans = 0;
    if(isFr && A[i])
        ans++;

    ans += min(helper(i + 1, isFr, turns - 1, dp, A), helper(i + 1, !isFr, 2, dp, A));

    return dp[i][isFr][turns] = ans;

}
void solve(){
    int n; cin >> n;

    vi A(n);

    for(int &i : A)
        cin >> i;

    
    /*
    seems like a standard dp prblm
    bool var -> isfriend, choose to keep him or not keep him, calculate points accordingly
    turns left -> one or 2
    so tc will amount to left*var*n
    = O(n) basically
    */
    vector<vector<vi>> dp(n, vector<vi>(2, vi(3, -1)));

    cout << helper(0, true, 2, dp, A) << nline;
    

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