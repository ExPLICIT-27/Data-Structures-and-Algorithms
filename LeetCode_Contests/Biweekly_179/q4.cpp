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
    // 32 max sum of digits
    vector<int> dsum;

    Solution(){
        dsum.resize(5001);
        for(int d = 0; d <= 5000; d++){
            int t = d;
            int sm = 0;

            while(t){
                sm += t%10;
                t /= 10;
            }

            dsum[d] = sm;
        }
    }
    const int M = 1e9 + 7;
    int countArrays(vector<int>& digitSum) {
        /*
        each element should be within 0 and 5K
        the array must be sorted
        the sum of digits of array[i] equals digitSum[i]
        pre compute all numbers whose digit sum equals i for all numbers in range 0, 5000
        O(1000*5000*5000) -> TLE
        how to optimize
        */

        int n = digitSum.size();

        ;

        // dp[i][curr] => no of ways to make array of length i, ending at curr
        /*
        base case
        no of ways to make array of size 1, ending with any num from 0 to 5K = 1 such that 
        the sum of digits = digitSum[0] is 1

        dp[i][curr] += dp[i - 1][curr - 1] .... dp[i - 1][0]
        dp[i][curr] => prefix sum of all valid dp[i - 1]
        im not using i - 1, just remove the n states only
        */

        vi dp(5001, 0);

       
        for(int v = 0; v <= 5000; v++){
            if(dsum[v] == digitSum[0])
                dp[v] = 1;

            if(v)
                dp[v] += dp[v - 1];
        }


        for(int i = 2; i <= n; i++){
            vi ndp(5001, 0);
            for(int v = 0; v <= 5000; v++){
                if(digitSum[i - 1] == dsum[v])
                    ndp[v] = (dp[v] + ndp[v])%M;
                

                if(v)
                    ndp[v] = (ndp[v - 1] + ndp[v])%M;
            }
            dp = ndp;
        }

        return dp[5000];

    }
};