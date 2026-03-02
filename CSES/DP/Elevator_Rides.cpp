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
// binary exponentiation
ll binexp(ll a, ll b, ll M){
    ll ans = 1;

    while(b){
        if(b & 1)
            ans = (ans*a)%M;
        b >>= 1;
        a = (a * a)%M;
    }

    return ans;
}
void solve(){
    int n; cin >> n;

    int x; cin >> x;

    vi A(n);

    for(int &i : A)
        cin >> i;
    
    /*
    brute force would be O(n*n!), too slow
    all possible subsets -> 2^n
    as you build subsets, the length goes from
    0 -> 1 -> 2 .. so on

    if you can find the least number of elevators needed for each subset of length i, you can 
    use that information to find the answer for subset of length i + 1
    how to find out the better subset?
    compare the value pair {no of elevators (lesser the better), space utilized in current elevator (lesser the better)}
    
    eg for 4 8 6 1

    null set -> 4 ->  4 8 now see which is better if the subset ended with 8, or if it ended with 4, 
                8     4 6
                6     4 1
                1     8 6
                      8 1
                      6 1
    for each subset, determine the optimal ending number, to find this just see what would happen by adding this number to previous
    subset which did not contain it

    use bitmasks to represent choice of subset
    watch the YT video by NeatlyStrcutured on this question
    T.C = S.C = O(n*2^n)
    */                
    
    int N = 1 << n;

    vector<pii> dp(N, {1e9 + 1, 1e9 + 1});

    // if no one is there, i.e n = 0, then one elevator, and used space is 0
    dp[0] = {1, 0};

    for(int mask = 0; mask < N; mask++){
        for(int bit = 0; bit < n; bit++){
            if(mask & (1 << bit)){
                int prev = (mask ^ (1 << bit));

                if(dp[prev].ss + A[bit] <= x) // can include with the previous subset
                    dp[mask] = min(dp[mask], {dp[prev].ff, dp[prev].ss + A[bit]});
                else// too heavy
                    dp[mask] = min(dp[mask], {dp[prev].ff + 1, A[bit]});
            }
        }
    }

    cout << dp[N - 1].ff << nline;
    
}
int main(){
    ExPLICIT_27;
    solve();
    // int T;
    // cin >> T;
    // while(T--){
    //     solve();
    // }

    return 0;
}