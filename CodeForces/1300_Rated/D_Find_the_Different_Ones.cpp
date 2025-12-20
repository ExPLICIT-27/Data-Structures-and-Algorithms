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
int LB(vector<pll> &P, int L){
    int l = 0, r = sz(P) - 1;

    while(l <= r){
        int mid = (l + r)/2;

        if(P[mid].ss < L){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    if(l < 0)
        return -1;
    return P[l].ss < L? -1 : l;
}
void solve(){
    ll n;

    cin >> n;

    vll A(n);
    rep(i, 0, n){
        cin >> A[i];
    }
    vector<pll> P;
    int l = 0, r = 0;
    rep(i, 1, n){
        if(A[i] != A[i - 1]){
            P.pb({l, r});
            l = i, r = i;
        }
        else    
            r++;
    }
    P.pb({l, r});

    ll q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        int lb = LB(P, l);
        if(lb == -1){
            cout << -1 << " " << -1 << nline;
        }
        else{
            if(P[lb].ss + 1 <= r){
                cout << l + 1 << " " << P[lb].ss + 2 << nline;
            }
            else{
                cout << -1 << " " << -1 << nline;
            }
        }
    }
    cout << nline;
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