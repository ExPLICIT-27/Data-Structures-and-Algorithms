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


void solve(){
    int n;
    cin >> n;

    if(n & 1 ^ 1){
        // if n is even, then i will have n/2 up down movements and n/2 left right movements
        // if x is the number of up down movements, the number of different positions i cn end up is
        // x (all up movmts), x - 2(1 down, remaining up).... -x (all down) => total x + 1 diff movements
        // hence, for n/2 updown and n/2 left right, total possible positions = (n/2 + 1)*(n/2 + 1)
        ll x = n/2;

        cout << (x + 1)*(x + 1) << nline;
    }
    else{
        // for this case, up down or left right will end up having more movements
        // up down can have n/2 + 1 total, and left right can have n/2
        // and the case where left right has n/2 + 1, up down n/2
        // hence total cases => 2*(n/2 + 1)*(n/2 + 2)

        ll x = n/2;

        cout << 2*(x + 1)*(x + 2) << nline;
    }
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