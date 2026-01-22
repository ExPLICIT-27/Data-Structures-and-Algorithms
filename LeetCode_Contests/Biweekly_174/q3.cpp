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
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

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
class Solution {
public:
    int alternatingXOR(vector<int>& nums, int t1, int t2) {
        /*
        count no of subarrays ending with t1 and
        count no of subarrays ending with t2 as you go
        throught each index
        for any index i
        let c1 be number of valid blocks of type t1,t2,t1 (ending t1)
        let c2 be number of valid blocks of type t1,t2,t1,t2 (ending t2)
        c1 = number of valid blocks ending t2
        c2 = number of valid blocks ending t1


        number of valid t1, t2, t1 endings at i += c1
        number of valid t1, t2, t1, t2 endings at i += c2

        answer = final c1 + final c2
        */


        int n = sz(nums);

        umap<int, int> mp1, mp2;
        mp1[0]++; // if entire subarray equals t1, then xor is 0
        
        int c1 = 0, c2 = 0, xr = 0;

        for(int i : nums){
            xr ^= i;

            c1 = mp2[xr^t2];
            c2 = mp1[xr^t1];

            mp1[xr] = (mp1[xr] + c1)%MOD;
            mp2[xr] = (mp2[xr] + c2)%MOD;
        }

        return (c1 + c2)%MOD;

    }
};