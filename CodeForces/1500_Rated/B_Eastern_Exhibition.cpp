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
    /*
    1 3 8 10
    3 => 2 + 0 + 5 + 7 = 14
    4 => 3 + 1 + 4 + 6 = 14
    5 => 4 + 2 + 3 + 5 = 14
    6 = 14
    7 = 14
    8 = 14

    any value between the median is valid for even
    for odd length, one valid position only 
    */

    ll n; cin >> n;

    vll X(n), Y(n);

    for(ll i = 0; i < n; i++){
        cin >> X[i] >> Y[i];
    }


    sort(all(X));
    sort(all(Y));

    cout << (X[n/2] - X[(n - 1)/2] + 1)*(Y[n/2] - Y[(n - 1)/2] + 1) << nline; // n/2 and (n - 1)/2 are equal when n is odd
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