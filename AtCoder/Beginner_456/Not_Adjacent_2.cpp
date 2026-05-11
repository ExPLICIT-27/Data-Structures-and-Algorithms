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
const ll MOD = 998244353;
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
    string s; cin >> s;
    /*
    is this dp, 
    choose not choose
    track prev char -> O(3)
    ind -> O(n)
    contains -> bool
    */

    int n = sz(s);
    function<ll(int, char, bool)> helper;

    vector<vector<vector<ll>>> dp(n, vector<vll>(5, vll(2, -1)));

    helper = [&](int i, int prev, bool had) -> ll {
        if(i == n)
            return !had;
        
        if(dp[i][prev][had] != -1)
            return dp[i][prev][had];


        ll choose = helper(i + 1, s[i] - 'a', ((s[i] - 'a') == prev) || had)%MOD;
        ll skip = helper(i + 1, prev, had)%MOD;

        return dp[i][prev][had] = (choose + skip)%MOD;
    };

    cout << (helper(0, 4, false) - 1 + MOD)%MOD << nline;
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