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

class SGT{
    public:
    // no need to build tree here, it all starts with 0
    vll S;
    SGT(int n){
        S.assign(4*n + 1, 0);
    }

    ll query(int idx, int low, int high, int l, int r){

        if(low > r || high < l)
            return 0;
        
        if(low >= l && high <= r)
            return S[idx];
        
        int mid = (low + high)/2;
        ll left = query(2*idx + 1, low, mid, l, r);
        ll right = query(2*idx + 2, mid + 1, high, l, r);

        return (left + right)%MOD;
    }

    void update(int idx, int low, int high, int target, ll val){
        if(low == high){
            S[idx] += val;
            return;
        }

        int mid = (low + high)/2;

        if(target <= mid)
            update(2*idx + 1, low, mid, target, val);
        else
            update(2*idx + 2, mid + 1, high, target, val);
        S[idx] = (S[2*idx + 1] + S[2*idx + 2])%MOD;
    }

};
void solve(){
    // int n; cin >> n;


    // vi A(n);


    // for(int &i : A)
    //     cin >> i;
    
    // vll dp(n, 1);

    // this code TLE's we need to redo the same using Sum based Segment trees and coordinate compression
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < i; j++){
    //         if(A[i] > A[j]){
    //             dp[i] += dp[j];
    //             dp[i] %= MOD;
    //         }
    //     }
    // }

    // ll ans = 0;

    // for(int i = 0; i < n; i++)
    //     ans = (ans + dp[i])%MOD;

    // cout << ans << nline;

    /*
    First perform coordinate compression
    - its basically assigning a value from 1 - cnt of unique elements (or 0 based index also) in the array to each element in the array
    array element count goes only until 1e5, but each element can be as large as 1e9

    strategy for coordinate compression involves sorting and removing duplicates, then assigning index to it
    if we have a sorted unique array, we can use the index only as the compressed coordinate value


    segment tree logic:
    now its clear that for every A[i] in the array, you need accumulate the values of the 
    elements smaller than it to the current dp value


    hence in other words, for every A[i], you need to sum up the values for elements 0 - A[i] - 1, then add 1 to it (include A[i] itself, we wont be initializing the array with values 1, rather we will be initializing with 0, hence the +1)
    */


    int n; cin >> n;

    vi A(n), compressed(n);


    for(int i = 0; i < n; i++){
        cin >> A[i];
        compressed[i] = A[i];
    }

    sort(all(compressed));

    compressed.erase(unique(all(compressed)), compressed.end());// remove duplicates

    // now the new 'id' is just the index, which can be found using lower bound
    auto getIdx = [&](int x){
        return int(lower_bound(all(compressed), x) - compressed.begin());
    };


    int newSize = sz(compressed);
    SGT seg = SGT(newSize);

    for(int i = 0; i < n; i++){
        int x = A[i];
        // obtain the new 'id'/idx
        int compressedIdx = getIdx(x);

        ll ans = compressedIdx == 0 ? 0 : seg.query(0, 0, newSize - 1, 0, compressedIdx - 1);

        ans = (ans + 1)%MOD; // +1 for itself
        seg.update(0, 0, newSize - 1, compressedIdx, ans);
    }

    // finally ans will be stored in the entire arrrays sum

    cout << seg.query(0, 0, newSize - 1, 0, newSize - 1) << nline;

}
int main(){
    ExPLICIT_27;
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }

    return 0;
}