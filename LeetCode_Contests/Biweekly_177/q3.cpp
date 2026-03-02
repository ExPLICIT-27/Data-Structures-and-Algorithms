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
    void update(vi &a, int i, int min_el, int max_el){
        if(min_el == max_el){
            a[i]++;
            return;
        }

        if(a[i] == min_el)
            a[i]++;
        if(a[i] == max_el)
            a[i]--;
    }
    vector<int> makeParityAlternating(vector<int>& nums) {
       /*
       either odd - even or even - odd
       */ 

       // odd even and even odd operation cnts

        int odd_even = 0, even_odd = 0;
        int n = sz(nums);
        int min_el = nums[0], max_el = nums[0];
        for(int i = 0; i < n; i++){
            if(i & 1){
                if(nums[i] & 1)
                    odd_even++;
                else
                    even_odd++;
            }
            else{
                if(nums[i] & 1 ^ 1)
                    odd_even++;
                else
                    even_odd++;
            }
            min_el = min(min_el, nums[i]);
            max_el = max(max_el, nums[i]);
        }   


        vector<int> c1 = nums, c2 = nums;
        for(int i = 0; i < n; i++){
            if(i & 1){
                if(c1[i] & 1){
                    update(c1, i, min_el, max_el);
                }
                else{
                    update(c2, i, min_el, max_el);
                }
            }
            else{
                if(c1[i] & 1 ^ 1){
                    update(c1, i, min_el, max_el);
                }
                else{
                    update(c2, i, min_el, max_el);
                }
            }
        }   

        int diff_oe = vmax(c1) - vmin(c1), diff_eo = vmax(c2) - vmin(c2);

        if(odd_even < even_odd)
            return {odd_even, diff_oe};
        if(even_odd < odd_even)
            return {even_odd, diff_eo};
        return {even_odd, min(diff_eo, diff_oe)};
        // wtf are these implementation headaches, this shi deffo out of some atcoder contest
    }
};