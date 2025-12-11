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


int main(){
    fastio;
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<vll> A(n, vll(3));

        rep(i, 0, n){
            cin >> A[i][0];
        }
        rep(i, 0, n){
            cin >> A[i][1];
        }
        rep(i, 0, n){
            cin >> A[i][2];
        }

        set<pll, greater<pll>> st1, st2, st3;
        rep(i, 0, n){
            st1.insert({A[i][0], i});
            st2.insert({A[i][1], i});
            st3.insert({A[i][2], i});
        }
        ll ans = 0;
        rep(i, 0, n){
            st2.erase({A[i][1], i});
            st3.erase({A[i][2], i});
            // b, then c
            auto fb = *(st2.begin());
            st3.erase({A[fb.ss][2], fb.ss});
            ans = max(ans, A[i][0] + fb.ff + st3.begin()->ff);
            st3.insert({A[fb.ss][2], fb.ss});

            // c, then b
            auto fc = *(st3.begin());
            st2.erase({A[fc.ss][1], fc.ss});
            ans = max(ans, A[i][0] + st2.begin()->ff + fc.ff);
            st2.insert({A[fc.ss][1], fc.ss});
            st2.insert({A[i][1], i});
            st3.insert({A[i][2], i});
        }
        cout << ans << endl;
        
    }

    return 0;
}