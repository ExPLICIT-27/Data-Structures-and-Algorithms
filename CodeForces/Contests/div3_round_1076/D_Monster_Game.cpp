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

    vll A(n), B(n);

    for(ll & i : A)
        cin >> i;
    
    for(ll & i : B)
        cin >> i;
    map<ll, ll> mp;

    for(ll i : A)
        mp[i]++;
    vector<pll> P;
    for(auto &[x, y] : mp){
        P.pb({x, y});
    }
    sort(all(P));
    for(int i = 1; i < sz(P); i++){
        P[i].ss += P[i - 1].ss;
    }
    vll MS(n); MS[0] = B[0];
    for(int i = 1; i < n; i++){
        MS[i] = MS[i - 1] + B[i];
    }

    ll ans = 0;
    sort(all(A));
    for(int i = 0; i < n; i++){
        ll x = A[i];
        if(i && A[i] == A[i - 1])
            continue;
        auto it = lower_bound(all(P), make_pair(x, -1ll));
        ll swords = 0;
        if(it != P.begin()){
            it--;
            swords = P.back().ss - it->ss;
        }
        else
            swords = P.back().ss;
        // cout << swords << " " << x << nline;
        auto it2 = upper_bound(all(MS), swords);

        if(it2 != MS.begin()){
            it2--;
            ans = max(ans, 1ll*(it2 - MS.begin() + 1)*x);
        }
        
    }

    cout << ans << nline;
    
}
int main(){
    fastio;
    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}