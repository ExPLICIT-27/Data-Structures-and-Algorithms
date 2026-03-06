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
    int n; cin >> n;

    vll A(n);

    for(ll &i : A)
        cin >> i;
    
    string S; cin >> S;

    int q; cin >> q;
    ll ans1 = 0;
    ll total = 0;

    vll pre(n + 1, 0);
    for(int i = 0; i < n; i++){
        pre[i + 1] = A[i]^pre[i];
        if(S[i] == '1')
            ans1 ^= A[i];
        total ^= A[i];
    }

    
    string extraline;
    getline(cin, extraline);

    
    while(q--){
        string inp;

        getline(cin, inp);

        stringstream ss(inp);

        int type; ss >> type;

        if(type == 1){
            int l, r; ss >> l >> r;
            // need to make this O(1) o O(logn)
            // prefix xors
            l--, r--;
            ans1 ^= (pre[r + 1] ^ pre[l]);
        }
        else{
            // should be O(1) or O(logn)

            int t; ss >> t;
            if(t == 1)
                cout << ans1 << " ";
            else
                cout << (total ^ ans1) << " ";
        }
    }

    cout << nline;
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