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

class SGT{
    public:
    
    vll S, A;

    SGT(vll &A, int n){
        this->A = A;       
        S.resize(4*n + 1, 0);
    }

    void Build(int i, int l, int r, bool isOr) {
        if(l == r){
            S[i] = A[l];
            return;
        }

        int m = (l + r)/2;

        Build(2*i + 1, l, m, !isOr);
        Build(2*i + 2, m + 1, r, !isOr);

        if(isOr)
            S[i] = S[2*i + 1] | S[2*i + 2];
        else
            S[i] = S[2*i + 1] ^ S[2*i + 2];
    }

    void Update(int i, int l, int r, int t, ll v, bool isOr){
        if(l == r){
            S[i] = v;
            return;
        }

        if(l > r)
            return;

        int m = (l + r)/2;

        if(t <= m)
            Update(2*i + 1, l, m, t, v, !isOr);
        else
            Update(2*i + 2, m + 1, r, t, v, !isOr);
        
        if(isOr)
            S[i] = S[2*i + 1] | S[2*i + 2];
        else
            S[i] = S[2*i + 1] ^ S[2*i + 2];
    }
};
void solve(){
    int n, m; cin >> n >> m;

    int N = 1 << n;

    vll A(N);

    for(int i = 0; i < N; i++)
        cin >> A[i];
    SGT S(A, N);
    if(n & 1)
        S.Build(0, 0, N - 1, true);
    else
        S.Build(0, 0, N - 1, false);

    while(m--){
        int i;
        ll v;
        cin >> i >> v;

        i--;
        if(n & 1)
            S.Update(0, 0, N - 1, i, v, true);
        else
            S.Update(0, 0, N - 1, i, v, false);

        cout << S.S[0] << nline;
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