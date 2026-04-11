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

// ---------- PBDS ----------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using ordered_multiset = tree<pair<T,int>, null_type, less<pair<T,int>>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename K, typename V>
using ordered_map = tree<pair<K,V>, null_type, less<pair<K,V>>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    /*
    this is clearly out of my reach right now, but i get whats going on, why its done
    the mental picture is my sole convincer right now as a dry run on this on anything large will pull my soul out

    lets talk about the node 1
    A[i] = 1 if you take it with any of its ancestors including itself
    1*N basically

    suppose node 1 has k children (c1, c2, .... ck)
    if you choose a subset that contains different children like c1, c2 or c2, c5 etc, then their lca is bound to be 1 (their parent and this is what min(lca(x, i))) will be just 1*N again, but we already computed this and it is hence of no use to us

    what we are concerned is choosing subset of nodes within c1 or within c2 etc
    then we move on to that particular node and the solve the same problem we had for 1 for them

    1*N was basically node_value*subtree_size[node_value]

    so when we go down to c1
    the value there at start will also be c1*subtree_size[c1]
    
    if we are choosing only the nodes within c1 -> total options being subtree_size[c1], 
    then the other values, which is subtree_size[par[c1]] - subtree_size[c1] will be equal to par[c1] (par is parent)
    let it be rem (rem - subtree_size[par[c1]] - subtree_size[c1])
    so before we go solve for the children of c1, the ans for the c1 will increase by rem*cnt[c1], where cnt[c1] is the distinct arrays possible when considering the subtree of c1
    itll be filled with 1 initially and incremented by the value of its children as we process them

    dp[i] = answer for node at i, we aggregate everything to dp[1] (the root)

    base case, as discussed dp[i] = i*subtree_size[i]
    cnt[i] = 1 as discussed
    calculate subtree_size of each node via dfs or another simple method will be 
    to go from n to 2, and add sub[par[i]] += sub[i] since its given par[i] < i strictly

    now dp table can be filled via dfs or another simple method, again
    is filling it from n to 1
    transition being
    at node i
    rem = subtree[par[i]] - subtree[i]
    cnt[par[i]] += cnt[i]
    dp[par[i]] = (dp[par[i]] + rem*par[i]*cnt[i] + dp[i]) => it increases by how many nodes are outside i with value par[i] added with whatever the answer was for i
    */

    const int M = 998244353;
    int n; cin >> n;

    vi par(n + 1);

    for(int i = 2; i <= n; i++)
        cin >> par[i];
    
    vi dp(n + 1), cnt(n + 1, 1), subsz(n + 1, 1);

    // calc subsz from n to 1
    for(int i = n; i > 1; i--)
        subsz[par[i]] += subsz[i];
    
    // fill base case for dp table
    for(int i = 1; i <= n; i++)
        dp[i] = 1ll*i*subsz[i]%M;
    

    // main logic

    for(int i = n; i > 1; i--){
        int rem = (subsz[par[i]] - subsz[i]);
        cnt[par[i]] += cnt[i];

        dp[par[i]] = (dp[par[i]] + 1ll*cnt[i]*par[i]*rem + dp[i])%M;
    }

    cout << dp[1] << nline;

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