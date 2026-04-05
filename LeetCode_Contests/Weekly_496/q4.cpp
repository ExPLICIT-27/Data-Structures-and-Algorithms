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
    
    int minOperations(vector<int>& nums, int k) {
        int n = sz(nums);

        // i can do O(n^2)
        
        // if 0 is a peak, then last element cannot be peak?

        int max_poss;
        if((n - 2) & 1)
            max_poss = (n - 1)/2;
        else
            max_poss = (n - 2)/2 + 1;

        if(k > max_poss)
            return -1;

        /*
        dp[i][k][isF]

        at index i, we have generated k peaks, isFirst = is the first element a peak, if so, the last cannot be one
        */
        

        auto getNei = [&](int i) -> pii {
            if(i == 0)
                return {nums[n - 1], nums[1]};
            if(i == n - 1)
                return {nums[i - 1], nums[0]};

            return {nums[i - 1], nums[i + 1]};
        };

    
        vector<vll> dp1(n + 2, vll(k + 1, 1e9 + 1)), dp2(n + 2, vll(k + 1, 1e9 + 1));
        
        for(int i = 0; i <= n + 1; i++)
            dp1[i][k] = dp2[i][k] = 0;

        ll ans = 1e9 + 1;
        for(int i = n - 1; i >= 0; i--){
            for(int p = k - 1; p >= 0; p--){
                for(int isF = 0; isF < 2; isF++){
                    
                    if(i == n - 1 && isF)
                        dp2[i][p] = dp2[i + 1][p];
                    else{
                        auto [prev, nxt] = getNei(i);
                        ll cost = max(prev, nxt) - nums[i] + 1;

                        if(nums[i] > prev && nums[i] > nxt){
                            if(i == 0){
                                if(isF)
                                    dp2[i][p] = min(dp1[i + 1][p], dp2[i + 2][p + 1]);
                                else
                                    dp1[i][p] = min(dp1[i + 1][p], dp2[i + 2][p + 1]);

                            }
                            else{
                                if(isF)
                                    dp2[i][p] = dp2[i + 2][p + 1];
                                else
                                    dp1[i][p] = dp1[i + 2][p + 1];
                            }
                        }
                        else{
                            if(i == 0){
                                if(isF)
                                    dp2[i][p] = min(dp1[i + 1][p], cost + dp2[i + 2][p + 1]);
                                else
                                    dp1[i][p] = min(dp1[i + 1][p], cost + dp2[i + 2][p + 1]);

                            }
                            else{
                                if(isF)
                                    dp2[i][p] = min(dp2[i + 1][p], cost + dp2[i + 2][p + 1]);
                                else
                                    dp1[i][p] = min(dp1[i + 1][p], cost + dp1[i + 2][p + 1]);
                            }
                            

                        }
                    }
                }
            }
        }

        return min(dp1[0][0], dp2[0][0]);
    }
};