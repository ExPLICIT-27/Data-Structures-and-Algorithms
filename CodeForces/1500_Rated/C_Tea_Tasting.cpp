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
    int n; cin >> n;

    vll A(n), B(n);


    for(ll &i : A)
        cin >> i;

    for(ll &i : B)
        cin >> i;
    

    // brute force, TLE's
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < (n - i); j++){
    //         ans[j + i] += min(B[j + i], A[j]);
    //         A[j] -= min(B[i + j], A[j]);
    //     }
    // }


    /*
    Logic:
    use prefix sums and difference arrays to see how many tea testers a given stall can provide full to

    just take lower bound on current tea still capacity + previous prefix sum of tea tester capacities (to start lower bound from current index)
    add leftover at lower bound index to the ans
    then update the difference array count at index i to j, for increasing the amount of tea testers that can have their full tea amounts

    */
    vll pre(n + 1, 0);

    for(int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + B[i];
    
    vll ans(n, 0);
    vll diff(n + 1, 0);


    for(int i = 0; i < n; i++){
        ll val = A[i] + pre[i];

        int idx = upper_bound(all(pre), val) - pre.begin();


        if(idx <= n){
            ans[idx - 1] += (val - pre[idx - 1]);
        }

        diff[i]++;
        diff[idx - 1]--;
    }

    ans[0] += diff[0]*B[0];
    cout << ans[0] << " ";

    for(int i = 1; i < n; i++){
        diff[i] += diff[i - 1];
        cout << ans[i] + B[i]*diff[i] << " ";
    }
    cout << nline;
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