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
// binary exponentiation
ll binexp(ll a, ll b, ll M){
    ll ans = 1;

    while(b){
        if(b & 1)
            ans = (ans*a)%M;
        b >>= 1;
        a = (a * a)%M;
    }

    return ans;
}
void solve(){
    
    int n, m; cin >> n >> m;
    
    /*
    group based on y (reactivity)
    in order to find the max value obtainable for any reactivity y, just find the sum of the highest y + 1 elements whose reactivity is >= y
    in order to do this traverse from n to 1, keep track of max value possible for each type of reactivity
    update max possible with the current values make sure the set always contains no more than i elements
    in the same time, to answer the query keep track for each i, max sum possible if you exclude one element (obv the smallest) so that you can add the element in shop with this value to get total reactivity
    */

    vector<vector<ll>> A(n + 1);


    for(int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        A[y].push_back(x);
    }

    vector<ll> max_m1(n + 1, -INF); // max_m1[i] (max_m1 stands for max minus 1) = max value i - 1 elements with reactivity >= i - 1 (to be used in the queries )

    ll maxposs = 0, curr = 0;
    multiset<ll> ms;

    for(int y = n; y >= 0; y--){
        for(ll x : A[y]){
            ms.insert(x);
            curr += x;
        }

        // no of elements cannot exceed current reactivity values, reactivity y means can inlcude together y + 1 values
        while(sz(ms) > (y + 1)){
            curr -= *ms.begin();
            ms.erase(ms.find(*ms.begin()));
        }

        if(sz(ms) == y + 1){
            max_m1[y] = curr - *ms.begin(); // one less than
        }
        else if(sz(ms) == y){// alr one less than
            max_m1[y] = curr;
        }
        maxposs = max(maxposs, curr);
    }

    for(int i = 1; i <= n; i++)
        max_m1[i] = max(max_m1[i], max_m1[i - 1]); // if using 2 less elements (lesser reactivity) gives more output, then let that be the max for the given reactivity y
    
    for(int i = 0; i < m; i++){
        ll x, y; cin >> x >> y;

        cout << max(maxposs, x + max_m1[y]) << ' ';
    }

    cout << nline;


}
int main(){
    ExPLICIT_27;
    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}