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
class Solution {
public:
    long long minCost(string s, int encCost, int flatCost) {
        /*
        X = 0, cost is flatCost
        X > 0, (at least 1 '1') -> cost is encCost
        
        */
        

        /*
        if its odd length i cant split?
        prefix sum for costs?
        */
        int n = sz(s);
        vi pre(n + 1, 0);

        for(int i = 0; i < n; i++){
            if(s[i] == '1')
                pre[i + 1] = 1 + pre[i];
            else
                pre[i + 1] = pre[i];
        }

        /*
        idea -1
        what if i design a divide and conquer type func?
        rec(l, r)
        calculate cost in the range l, r
        return max(currcost, rec cost if i can split it)
        */

        auto dNc = [&](auto &&self, int l, int r) -> ll {
            int sens = pre[r + 1] - pre[l];
            // cout << l << " " << r << nline;
            ll currcost = 0;
            int L = (r - l + 1);
            if(sens)
                currcost = 1ll*L*sens*encCost;
            else
                currcost = flatCost;
            // if i can divide then divide
            if(L & 1 ^ 1)
                return min(currcost, self(self, l, l + L/2 - 1) + self(self, l + L/2, r));
            return currcost;
        };

        return dNc(dNc, 0, n - 1);
    }
};