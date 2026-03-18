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
// 2, 4, 7, 8, 10
// 2, 3, 1, 2

/*
l = [2, 2, 2, 2, 2]
r = [2, 2, 2, 2, 2]
ans = 3

*/
class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        /*
        i can change at most 1 integer
        choose, choose not choose to change an integer?

        if this is dp, what will my states be?

        can i be greedy?

        will it have something to do with already existing longest sequences?
        [1, 2], [2, 6], [6, 7], in this case changing any element affects
        every other sequence, hence it will be longest existing sequence + 1

        the only way changing something would extend the sequence is if
        it was of the form
        a, a + d, something, a + 3d
    2, 4, 7, 8
        so for any 2 consecutive ap segments, 

        i dont need to insert, i assume to add the correct element and move on

        for 2, 4, 7, 8
        when i reach 7, i can choose to change it to the valid value, then 
        move on
        valid value being 6 in this case

        so if i make a dp function for this it would be

        dp[index][curr_el][prev_el] => O(n^3), also will have to use a mp or
        sum since curr and prev can be negative
        indicator that i should not proceed with this approach

        common diff array, see if i can make any observations

        [1, 4, 1]

        2, 4, 5, 9, 11
        [2, 1, 4, 2, 2]

        a modification for increase involves, 2 elements such that
        their sum/2 is equal to the prev and next differences
        basically

        i - 1, i, i + 1, i + 2

        (cd[i] + cd[i + 1])/2 = cd[i - 1] and cd[i + 1]
        then we can do a merge

        9, 7, 5, 10, 1
        [-2, -2, 5, -9]
        */

        int n = sz(nums);

        vector<int> L(n, 2), R(n, 2);

        for(int i = 2; i < n; i++){
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                L[i] = 1 + L[i - 1];
        }

        for(int i = n - 3; i >= 0; i--){
            if(nums[i + 1] - nums[i] == nums[i + 2] - nums[i + 1])
                R[i] = 1 + R[i + 1];
        }

        
        // for the edges
        int ans = 3;
        ans = max(ans, 1 + max(L[n - 2], R[1]));

        for(int i = 1; i < n - 1; i++){
            ans = max(ans, 1 + max(L[i - 1], R[i + 1]));

            int diff = nums[i + 1] - nums[i - 1];
            if(diff & 1)
                continue;
    
            diff /= 2;
            
            int left = 1, right = 1;
            if((i - 2 >= 0) && (nums[i - 1] - nums[i - 2] == diff))
                left = L[i - 1];
            if((i + 2 < n) && (nums[i + 2] - nums[i + 1] == diff))
                right = R[i + 1];
            
            ans = max(ans, 1 + left + right);
        }

        return ans;
    }
};