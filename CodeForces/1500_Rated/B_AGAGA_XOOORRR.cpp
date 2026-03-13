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
    qn is basically dividing the array into 2 subsets which yield the same xor

    hence the entire array xor must be 0

    nvm its adjacent elements
    
    if n == 2 at the end, then the xor of the entire array should be 0
    if n == 3 at the end, then xor of the entire array should be equal to the target

    oh basically odd even
    11 10
    if the entire xor is zero, then possible
    or if i can make all elements equal to the entire array xor, then also possible
    */
    int n; cin >> n;

    vll A(n);

    for(ll &i : A)  
        cin >> i;
    
    ll xr = 0;

    for(ll i : A)
        xr ^= i;
    
    if(xr == 0)
        cout << "YES\n";
    else{

        // check if i can achieve xr with 
        ll curr = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            curr ^= A[i];
            if(curr == xr){
                cnt++;
                curr = 0;
            }
        }

        if(cnt >= 2 && curr == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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