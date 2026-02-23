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

void solve(){
    /*
    not an easy problem.
    core logic:
    before heading in, understand the true objective
    let the players be p1 and p2
    we need to maximmize p1's score
    i.e minimize p2's score
    so what does this mean in context of both players together?
    we need to maximize p1 - p2 : this is the heart of the solution
    we know for a fact that p1 + p2 = sum of all scores
    if we find maximum value for p1 - p2, then we can get p1 by solving the set of eqns for 
    p1 + p2 and p1 - p2
    further analysis : 
    start from the trivial cases
    if theres just one element, ans = that element
    if theres two, say '4 1', ans = 4, ergo the maximum among the two, how did this come?
    p1 + p2 = 4 + 1 = 5
    p1 - p2 we need to maximize, in this case its just 4 - 1 = 3
    p1 + p2 = 5
    p1 - p2 = 3, 
    hence p1 = 4, which is indeed the answer

    what if there are three elements
    '4 1 6'
    ans would be max of take 4, find ans for '1 6', and take 6 find ans for '4 1'

    so in general for any two indices
    'i....j'
    dp[i][j] = max(A[i] - dp[i + 1][j], A[j] - dp[i][j - 1]) : Main recurrence

    note we need to move i from n to 1, and j from i + 1 to n (j must be always >= i)

    */
    int n; cin >> n;


    vll A(n);
    vector<vll> dp(n + 1, vll(n + 1, 0));

    ll total = 0;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        dp[i][i] = A[i]; // base case for 1 element;
        total += A[i];
    }
    
    // i goes from n - 1 to 0, j from i to n -1 
    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++)
            dp[i][j] = max(A[i] - dp[i + 1][j], A[j] - dp[i][j - 1]);
    }

    ll maxdiff = dp[0][n - 1]; // ans is obv in the range 0 to n - 1 (including all the elements)

    ll ans = (total + maxdiff)/2;

    cout << ans << nline;

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