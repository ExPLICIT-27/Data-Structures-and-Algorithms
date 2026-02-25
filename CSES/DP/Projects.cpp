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
struct Project{
    int s, e;
    ll c;
    Project(){}
    Project(int s, int e, ll c) : s(s), e(e), c(c) {}
};
void solve(){

    /*
    Core logic:
    sort by end times, so that you can easily check overlap between activities
    in order to avoid O(n^2) time complexity, always keep the highest possible answer at index
    i regardless of whether that index is part of the answer or not, for eg
    [end_time, max_score possible]
    [6, 70]
    [7, 30]
    from this max score possible if an activity with start time 8 comes, you lowerbound - 1 to get 7
    but taking 6 is better, since if you can take 7, it implies you will be able to take 6 as well,
    store the array such that the latest index/end time always contains the max possible value obtainable
    i.e store 
    [6, 70]
    [7, max(70, 30)] = [7, 70]
    */

    int n; cin >> n;

    vector<Project> P(n);


    for(auto &p : P)
        cin >> p.s >> p.e >> p.c;
    
    sort(P.begin(), P.end(), [](Project &a, Project &b){
        return a.e < b.e;
    });

    vector<pair<int, ll>> dp;

    dp.emplace_back(0, 0); // sentinel for lower_bound

    for(int i = 0; i < n; i++){
        auto lb = lower_bound(all(dp), make_pair(P[i].s, -1ll));
        lb--;
        dp.emplace_back(P[i].e, max(dp[i].ss, lb->ss + P[i].c));
        
    }

    cout << dp[n].ss << nline;
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