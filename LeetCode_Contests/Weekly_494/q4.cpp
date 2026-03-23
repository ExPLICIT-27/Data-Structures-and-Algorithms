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
    long long countGoodSubarrays(vector<int>& nums) {
        /*
        need to cnt of subarrays whose or equals some element within it

        if i want the or of any subarray to be equal to x,
        then all values within that subarray

        can i do the opposite, discount the number of subarrays which 
        can never equal any value within that subarray
        */
        int n = sz(nums);
        ll ans = 0;

        /*
        for any subarray, 
        */
        // just handle duplicates.....
        
        /*
        this code TLE's what optimizations can i make?
        go left till i set an index not set in nums[i] && left should not 
        equal nums[i]

        go right till i set an index not set in nums[i]
        */

        vector<vector<int>> pre(32);
         
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 32; j++){
                if((nums[i] >> j) & 1)
                    pre[j].push_back(i);
            }
        }
        umap<int, vector<int>> mp;

        for(int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);
        
        for(int i = 0; i < n; i++){
            auto lb = lower_bound(all(mp[nums[i]]), i);
            int l, r;
            if(lb == mp[nums[i]].begin())
                l = 0;
            else{
                --lb;
                l = *lb + 1;
            }
            // for each unset bit, see till what point you have to go to make it unset
            for(int j = 0; j < 32; j++){
                if((nums[i] >> j) & 1 ^ 1){
                    auto it = lower_bound(all(pre[j]), i);
                    if(it == pre[j].begin())
                        continue;
                    --it;
                    l = max(l, *it + 1);
                }
            }
            
            r = n - 1;
            for(int j = 0; j < 32; j++){
                if((nums[i] >> j) & 1 ^ 1){
                    auto it = upper_bound(all(pre[j]), i);
                    if(it == pre[j].end())
                        continue;
                    r = min(r, *it - 1);
                }
            }
            ans += 1ll*(r - i + 1)*(i - l + 1);
        }
        return ans;
    }
};