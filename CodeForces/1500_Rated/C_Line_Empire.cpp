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
    ll n, a, b; cin >> n >> a >> b;

    vll A(n + 1, 0);

    for(int i = 1; i <= n; i++)
        cin >> A[i];
    
    /*
    from the constraints, its clear that you can conquer kingdoms only in the order they are given one by one

    question boils down to when to move the capital and to where

    idea - 1
    just move it forward whenever the cost becomes less
    nope doesnt work for the second test case

    idea - 2
    another observation
    it doesnt matter if you move capital later or earlier what matters is the end position of the capital
    as the cost would always be equal to A[i]*a (distance from origin always)


    problem boils down to efficiently computing what the cost would be provided
    capital is finally at A[i] from every i : 0 -> n
    voila i think itll work

    always set everything to fucking LL
    
    */

    vll pre(n + 1, 0);
    pre[0] = A[0];

    for(int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + A[i];
    
    ll ans = b*pre[n];
    ll left = 0;
    for(int i = 1; i < n; i++){
        left += (a*(A[i] - A[i - 1]) + b*(A[i] - A[i - 1]));
        ll right = b*(pre[n] - pre[i] - A[i]*(n - i));
        ans = min(ans, left + right);
    }

    cout << ans << nline;
    

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