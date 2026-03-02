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
// binary exponentiation
ll binexp(ll a, ll b, ll M){
    ll ans = 1;

    while(b){
        if(b & 1)
            ans = (ans*a)%M;
        b >>= 1;
        a = (a * a)%M;
    }

    return ans;
}

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        /*
        we calculate ans for each l from 0 to n - 1

        strategy : for each l
        1. find the left most index r2 such that the number of unique elements in l..r2 is k + 1
        2. find the left most index r1 such that the number of elements with frequency >= m is k
        if r1 > r2 (i.e you encountered more diff elements before you had k elements with freq >= m)
        then add nothing to ans
        else
            inc ans by r2 - r1
        l.....r1...r2
        l..r1 -> there are k elements in this range with freq >= m
        l..r2 -> there are k + 1 unique elements in this range
        only case where r1 > r2 is the case where we have found a range l..r1 such that there are k elements with freq >= m but there are some other elements with freq < m which makes the count of unique elements > k
        */

        umap<int, int> f1, f2; // f1 for r1, f2 for r2

        int r1 = -1, r2 = -1, valid_cnts = 0; // r1 = freq >= m, r2 = distinct == k + 1, valid_cnts = els with freq >= m

        int n = nums.size();
        ll ans = 0;
        for(int l = 0; l < n; l++){
            while(r2 < n && sz(f2) <= k){ // go till i find k + 1 els
                r2++;
                if(r2 < n)
                    f2[nums[r2]]++;
            }

            // go till i find k els with freq >= m
            while(r1 < n && valid_cnts < k){
                r1++;
                if(r1 < n){
                    f1[nums[r1]]++;
                    if(f1[nums[r1]] == m)
                        valid_cnts++;
                }
            }

            ans += max(r2 - r1, 0);// add 0 if r1 > r2

            f1[nums[l]]--;
            if(f1[nums[l]] == m - 1)
                valid_cnts--;
            f2[nums[l]]--;

            if(f2[nums[l]] == 0)
                f2.erase(nums[l]);
        }

        return ans;
    }
};
