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
bool isValid(map<ll, vi> &mp, ll thresh){
    for(auto &[x, y] : mp){
        ll prev = 0;
        bool repaint = true;
        bool ok = true;
        rep(i, 0, sz(y)){
            ll d = y[i] - prev - 1;
            if(d > 2*thresh + 1){
                ok = false;
                break;
            }
            if(d > thresh){
                if(repaint)
                    repaint = false;
                else{
                    ok = false;
                    break;
                }
            }
            prev = y[i];
        }
        if(ok)
            return true;
    }
    return false;
}
void solve(){
    int n, k;
    cin >> n >> k;
    map<ll, vi> mp;
    ll last = -1;
    rep(i, 0, n){
        ll t;
        cin >> t;
        mp[t].pb(i + 1);
        last = t;
    }
    for(auto &[x, y] : mp){
        if(x != last)
            y.pb(n + 1);
    }
    ll l = 0, r = n;
    while(l <= r){
        ll m = (l + r)/2;
        if(isValid(mp, m))
            r = m - 1;
        else
            l = m + 1;
    }
    cout << l << endl;

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