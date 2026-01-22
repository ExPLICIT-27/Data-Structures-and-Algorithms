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

    vi A(n);

    for(int &i : A)
        cin >> i;
    
    int q;
    cin >> q;

    vector<vi> SB(n, vi(31, 0));

    for(int j = 0; j < 31; j++){
        if(A[0] & (1 << j))
            SB[0][j] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 31; j++){
            if(A[i] & (1 << j)){
                SB[i][j] = 1 + SB[i - 1][j];
            }
            else
                SB[i][j] = SB[i - 1][j];
        }
    }

    

    while(q--){
        int l, k;
        cin >> l >> k;
        l--;
        if(A[l] < k){
            cout << -1 << " ";
            continue;
        }
        int ans = 0, num = 0;
        int L = l, R = sz(A) - 1;

        while(L <= R){
            int M = (L + R)/2;

            num = 0;
            for(int j = 0; j < 31; j++){
                int ri = SB[M][j];
                int le = (l - 1 < 0)? 0 : SB[l - 1][j];
                if(ri - le == M - l + 1)
                    num += (1 << j);
            }

            if(num >= k)
                L = M + 1;
            else
                R = M - 1;
        }
        cout << R + 1 << " ";
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