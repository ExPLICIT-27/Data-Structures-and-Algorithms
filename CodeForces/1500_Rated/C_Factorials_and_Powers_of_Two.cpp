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

vector<pair<ll, int>> F;
void solve(){
    ll n; cin >> n;

    int ans = 60; // cant exceed this value guaranteed, total pows of 2 and factorials


    for(auto &[total, pc] : F){
        if(n - total < 0)
            continue;
        
        ans = min(ans, pc + __builtin_popcountll(n - total));
    }

    cout << ans << nline;


}
int main(){
    ExPLICIT_27;

    /*
    onlye 14 valid factorials are there (excluding 1 and 2 which are powers of 2)
    all possible sums they can generate are 2^14 -> 16384

    and since every power of 2 is valid, you can generate any n value using powers of 2 only

    so test what the ans would be if you use any of the sums among the 2^14, and the remaining using powers of 2
    lesgoo goated shi
    */

    vector<ll> facts;

    ll curr = 2;
    for(ll i = 3; ; i++){
        curr *= i;
        if(curr > 1e12)
            break;
        facts.pb(curr);
    }
    int p = sz(facts);
    for(int i = 0; i < (1 << p); i++){
        ll curr = 0;

        int t = i, idx = 0, pc = 0;
        while(t){
            if(t & 1){
                curr += facts[idx];
                pc++;
            }
            t >>= 1;
            idx++;
        }
        F.pb({curr, pc});
    }
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}