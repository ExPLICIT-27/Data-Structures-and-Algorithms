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
    int n, m;

    cin >> n >> m;

    int total = 0;
    priority_queue<pll, vector<pll>> pq;
    rep(i, 0 ,n){
        ll T;
        cin >> T;
        ll t = T;
        ll cnt = 0;
        while(t && t%10 == 0){
            cnt++;
            t /= 10;
        }
        int tsize = sz(to_string(T));
        pq.push({cnt, tsize - cnt});

        total += tsize;
    }

    int turn = 0;
    while(sz(pq) > 1){
        if(turn & 1 ^ 1){
            auto tp = pq.top();
            pq.pop();
            total -= tp.ff;
            pq.push({0, tp.ss});
        }
        else{
            auto fp = pq.top();
            pq.pop();
            auto sp = pq.top();
            pq.pop();
            int zeros = min(fp.ff, sp.ff);
            pq.push({zeros, fp.ff + fp.ss + sp.ff + sp.ss - zeros});
        }
        turn++;
    }

    if(turn & 1 ^ 1){
        total -= pq.top().ff;
    }
    if(total >= (m + 1))
        cout << "Sasha\n";
    else
        cout << "Anna\n";
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