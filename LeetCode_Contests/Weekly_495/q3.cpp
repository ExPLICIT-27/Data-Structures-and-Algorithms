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
    int sortableIntegers(vector<int>& nums) {
        /*
        for every number k that is divisble by n,
        i need to check whether i can sort the array by dividing
        it into subarrays of size n/k and rotating them however

        question boils down to efficiently figuring out if 
        every subsegment of k can be sorted
        [3, 1, 2]
        [2, 0, 1]
        for a segment of size k to be valid, 
        every integer from 0 to k - 1 must be present in that segment

        can i not bruteforce with divisors?
        */
        int n = sz(nums);

        vector<int> divisors;

        for(int k = 1; k <= n; k++){
            if(n%k == 0)
                divisors.pb(k);
        }
        // if k is valid, all divisors of k will be valid
        // now just do whatever they say
        ll ans = 0;

        vi T = nums;
        sort(all(T));
        /*
        exceeding time limit, O(128*n*log(n)) is apparently too much
        
        */
        for(int k : divisors){ // lets say O(128*n*log(n)) -> exceeds 1e8
            // take k, put in map, check that k, move forward
            
            bool ok = true;
            for(int i = 0; i + k <= n; i += k){
                // it should be within i and i + k - 1
               
                
                // check if is array is sorted and rotated
                /*
                1 2 3 4 5
                4 5 1 2 3
                3 3 4 5 1 
                1 2 1 4 5
                */
                vi tmp(k);
                int cmin = INT_MAX, cmax = INT_MIN;
                for(int j = i; j < i + k; j++){
                    tmp[j - i] = nums[j];
                    cmin = min(cmin, nums[j]);
                    cmax = max(cmax, nums[j]);
                }

                if(cmin != T[i] || cmax != T[i + k - 1]){
                    ok = false;
                    break;
                }

                int icnt = 0;

                for(int j = 1; j < k; j++){
                    if(tmp[j] < tmp[j - 1])
                        icnt++;
                }
                if(tmp[0] < tmp[k - 1])
                    icnt++;

                if(icnt > 1){
                    ok = false;
                    break;
                }
                
            }
            if(ok)
                ans += k;
            
        }

        return ans;
    }
};