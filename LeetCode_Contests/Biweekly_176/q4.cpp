// hardest and most concept rich qn till date
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
// IMPORTANT VERY VERY : FENWICK TREES ARE 1 INDEXED pls dont mess up
class FenwickXorB { // method B
public:
    int n;
    vector<ll> bit;

    FenwickXorB(int n) : n(n) {
        bit.assign(n + 1, 0);
    }

    void add(int i, int val){
        for(; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    // range XOR update
    void rangeUpdate(int l, int r, int val){
        add(l, val);
        add(r+1, val);
    }

    // point query
    ll pointQuery(int i){
        ll res = 0;
        for(; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }
};

class Solution {
public:
    vector<int> pathMasks, depth;
    vector<vector<int>> up, G;
    vector<int> tin, tout;
    int LOG;
    int timer;
    void dfsSetup(int u, int par, string &s){
        up[u][0] = par;
        tin[u] = ++timer;
        for(int v : G[u]){
            if(v != par){
                depth[v] = 1 + depth[u];
                pathMasks[v] = pathMasks[u]^(1 << (s[v] - 'a'));
                dfsSetup(v, u, s);
            }
        }
        tout[u] = timer;
    }
    int LCA(int u, int v){
        if(depth[u] > depth[v])
            swap(u, v);

        int d = depth[v] - depth[u];
        for(int i = LOG - 1; i >= 0; i--){
            if(d & (1 << i))
                v = up[v][i];
        }

        if(u == v)
            return v;
        
        for(int i = LOG - 1; i >= 0; i--){
            if(up[u][i] != up[v][i]){
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        /*
        main logic to employ
        Palindrome conditions = either 1 or 0 odd freq
        - for efficient palindrome checking
            - 26 bit masking, ith bit is the only set bit for the ith character
            - for a => 0...(25 zeros)..01, for b 0..(24 zeros)..010, and so on
            - so for the path with chars "abcca", when you xor them, only the 2nd bit (bit corresponding to b) will be set, 
            - so basically a palindromic path will only have 0 or 1 bit set
        - how to query efficiently 
            - so pre compute xor path from root to all the other nodes
            - if you want to find xor value from node u to node v, then
            - we have path from root to u, and root to v
            - let it be path[u], path[v]
            - if we xor them together, we cancel out path from root to lca of u and v
            - hence the xor value from u to v will be path[u]^path[v]^(mask[lca(u, v)])
        - now efficient updates
            - We know fenwick trees can handle efficient xor point updates and range queries
            - But the given structure is a tree
            - Hence we need to flatten it into an array such that i can have information regarding every nodes subtree (because when you update a node u, its entire subtree gets affected)
            - Euler's tour is used to flatten the tree, which makes use of the in and out time
            of visiting a node and stores the entire subtree of a node between its intime and 
            outtime
            - Hence we have a flattened tree and we use Fenwick tree over it for efficient updates
        */
        LOG = 0;
        while((1 << LOG) <= n)
            LOG++;

        vector<bool> ans;
        G.resize(n);
        pathMasks.resize(n);
        up.resize(n, vector<int>(LOG, 0));
        depth.resize(n, 0);
        tin.resize(n), tout.resize(n);

        for(auto &e : edges){
            G[e[0]].pb(e[1]);
            G[e[1]].pb(e[0]);
        }
        // precompute xor path masks from root to all nodes
        // along with it, set up the first parent and depth of each node as well for
        // binary lifting to get lcs later on
        // also update tin and tout times for eulers tour
        up[0][0] = 0;
        pathMasks[0] = (1 << (s[0] - 'a'));
        timer = 0;
        dfsSetup(0, 0, s);
        //use pathmasks to initialize fenwick tree
        FenwickXorB F(n);

        for(int u = 0; u < n; u++){
            F.rangeUpdate(tin[u], tin[u], pathMasks[u]);
        }

        // fill the binary lifting table
        for(int j = 1; j < LOG; j++){
            for(int u = 0; u < n; u++){
                up[u][j] = up[up[u][j - 1]][j - 1];
            }
        }

        for(auto &q : queries){
            stringstream ss(q);
            string type, a, b;
            ss >> type;
            if(type == "update"){
                int u;
                char c;
                ss >> u >> c;
                if(s[u] != c){// if its alr the same then no need to do anythin, do only if diff
                    int diff = (1 << (s[u] - 'a'))^(1 << (c - 'a')); 
                    s[u] = c;

                    // currently tree stores a^something, we want to change to c^somehting, so we xor it with diff which is a^c, which results in a^something^a^c = c^something, voila
                    // propagate the xor diff to u and all its children aka its subtree
                    F.rangeUpdate(tin[u], tout[u], diff);
                    
                } 
            }
            else{
                int u, v;
                ss >> u >> v;
                // shortcut to see if bits set is <= 1, do (mask & (mask - 1)), if its 
                // zero then yes, else no

                int lca = LCA(u, v);

                int mask = F.pointQuery(tin[u])^F.pointQuery(tin[v])^(1 << (s[lca] - 'a'));
                if(mask & (mask - 1))
                    ans.pb(false);
                else
                    ans.pb(true);
            }
            
        }

        return ans;
    }
};