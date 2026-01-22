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
class Solution {
public:
    char flip(char c){
        return c == '0'? '1' : '0';
    }
    // TLE eliminator's logic, bfs at leaves
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        vector<set<pair<int, int>>> G(n);

        for(int i = 0; i < n - 1; i++){
            auto e = edges[i];
            G[e[0]].insert({e[1], i});
            G[e[1]].insert({e[0], i});
        }

        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++){
            if(sz(G[i]) == 1)
                q.push({i, G[i].begin()->ss});
        }

        vector<int> ans;
        while(!q.empty()){
            auto u = q.front(); q.pop();
            auto v = *(G[u.ff].begin());
            if(start[u.ff] != target[u.ff]){
                ans.pb(u.ss);
                start[u.ff] = flip(start[u.ff]);
                start[v.ff] = flip(start[v.ff]);
            }
            G[v.ff].erase(u);
            G[u.ff].erase(v);
            if(sz(G[v.ff]) == 1){
                q.push({v.ff, G[v.ff].begin()->ss});
            }
        }

        sort(all(ans));
        if(start == target)
            return ans;
        return {-1};
    }
};