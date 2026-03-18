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
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        // frequency of all elements must be even
        umap<int, int> tf;
        int n = sz(nums1);
        for(int i = 0; i < n; i++){
            tf[nums1[i]]++;
            tf[nums2[i]]++;
        }

        for(auto &[x, y] : tf){
            if(y & 1)
                return -1;
        }

        umap<int, int> f1, f2;

        for(int i : nums1)
            f1[i]++;
        for(int i : nums2)
            f2[i]++;

        // jsut find good strat to make equal
        // is tot imb count always even?
        ll cnt = 0;
        for(auto &[x, y] : tf){
            int c1 = (f1.count(x))? f1[x] : 0;
            int c2 = (f2.count(x))? f2[x] : 0;
            if(c1 == c2)
                continue;
            cnt += llabs(c1 - y/2);
        }

        return cnt/2;
    }
};