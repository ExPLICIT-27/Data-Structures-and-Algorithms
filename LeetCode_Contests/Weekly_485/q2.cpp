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
    // prefix maximum, keep the top two maximum to take second biggest in case
    // of repeated index
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = sz(costs);

        vector<pair<int, int>> CC(n);

        for(int i = 0; i < n; i++){
            CC[i].ff = costs[i], CC[i].ss = capacity[i];
        }
        
        sort(all(CC), [](const pair<int, int> &a, const pair<int, int> &b){
            return a.ff < b.ff;
        });

        vector<pair<int, int>> P(n);
        P[0].ff = CC[0].ss, P[0].ss = 0;
        for(int i = 1; i < n; i++){
            P[i] = P[i - 1];
            if(CC[i].ss > P[i].ff){
                P[i].ss = P[i].ff;
                P[i].ff = CC[i].ss;
            }
            else if(CC[i].ss > P[i].ss)
                P[i].ss = CC[i].ss;
        }
        sort(all(CC), [](const pair<int, int> &a, const pair<int, int> &b){
            return a.ss > b.ss;
        });

        sort(all(costs));

        int ans = 0;
        for(int i = 0; i < n; i++){
            auto &p = CC[i];
            if(p.ff >= budget)
                continue;
            int r = budget - p.ff - 1;
            auto it = upper_bound(all(costs), r);
            if(it == costs.begin())
                ans = max(ans, p.ss);
            else{
                it--;
                int idx = it - costs.begin();
                if(P[idx].ff == p.ss)
                    ans = max(ans, p.ss + P[idx].ss);
                else
                    ans = max(ans, p.ss + P[idx].ff);
            }
            
        }

        
        

        return ans;
    }
};