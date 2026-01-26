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
ll cnt(vll &A, int i, ll prod){

}
bool isPrime(ll n){
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0)
            return false;
    }

    return true;
}
void solve(){
    int n;
    cin >> n;

    vll A(n);

    for(ll & i : A)
        cin >> i;
    set<ll> S(all(A));
    vll ans(n + 1, INT_MAX);
    if(S.count(1))
        ans[1] = 1;
    for(ll i : S){
        if(i == 1)
            continue;
        ll steps = 1;
        for(ll j = i; j <= n; j *= i, steps++)
            ans[j] = min(ans[j], steps);
        steps = 1;
        while(i*steps <= n){
            if(S.count(steps))
                ans[i*steps] = min(ans[i*steps], 2ll);
            else if(ans[steps] != INT_MAX)
                ans[i*steps] = min(ans[i*steps], ans[steps] + 1ll);
            steps++;
        }
    }

    for(ll i = 1; i <= n; i++){
        if(ans[i] == INT_MAX)
            cout << -1 << " ";
        else
            cout << ans[i] << " ";
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