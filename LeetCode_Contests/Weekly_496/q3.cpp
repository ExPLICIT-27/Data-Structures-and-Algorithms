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
    long long minIncrease(vector<int>& nums) {
        /*
        no of spcl indices will always be 
        at most ceil((sz(nums) - 2)/2)

        */

        int n = sz(nums);

        int max_poss = (n - 2 + 1)/2;

        ll ans = 0;

        auto calcOps = [&](int start, int end) -> ll {
            ll ops = 0;
            for(int i = start; i <= end; i += 2){
                if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                    continue;
                ops += max(nums[i + 1], nums[i - 1]) - nums[i] + 1;
            }

            return ops;
        };
        
        ll dp[n][2];
        memset(dp, -1, sizeof(dp));
        
        auto skip1 = [&](auto &&self, int i, int skips) -> ll {
            if(i >= n - 1)
                return 0;
            if(dp[i][skips] != -1)
                return dp[i][skips];
            
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return dp[i][skips] = self(self, i + 2, skips);

            ll cost = max(nums[i - 1], nums[i + 1]) - nums[i] + 1;
            if(skips > 0)
                return dp[i][skips] = min(self(self, i + 1, skips - 1), cost + self(self, i + 2, skips));
            
            return dp[i][skips] = cost + self(self, i + 2, skips);
        };

        
        if((n - 2) & 1){
            // if odd, then only one possible scenario
            ans = calcOps(1, n - 2);
        }
        else{
            // skip at most 1 => dp?
            ans = skip1(skip1, 1, 1);
        }

        return ans;
    }
};