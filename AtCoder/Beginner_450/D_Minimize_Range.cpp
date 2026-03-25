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
    ll n, k; cin >> n >> k;

    vll A(n);

    for(ll &i : A)
        cin >> i;
    
    /*
    I need to minimize max(A) - min(A)

    the task is basically modifying the array elements such that all the elements are as close to each other as possible

    */

    
    // try making everything near max -> this doesnt work

    /*
    make a multiset, keep taking min max, out, if they cant be made any better, return that particular difference
    */

    if(n == 1){
        cout << 0 << nline;
        return;
    }

    multiset<ll> S;

    for(ll i : A)
        S.insert(i);

    /*
    this logic is right, but it TLEs
    how can i optimize this to convergence?

    */
    ll L = vmax(A), R = 1e18;

    auto chck = [&](ll M) -> ll {
        vll B;
        for(ll i : A){
            ll mul = (M - i)/k;
            B.pb(i + k*mul);
        }

        return vmax(B) - vmin(B);
    };
    ll prev = -1;
    while(L <= R){

        ll M = (L + R)/2;
        ll curr = chck(M);
        if(curr == prev){
            cout << curr << nline;
            return;
        }
        else{
            prev = curr;
            L = M + 1;
        }

    }
    
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