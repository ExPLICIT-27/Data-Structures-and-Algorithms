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
    long long nthSmallest(long long n, int k) {
       // precompute nCr, using the formula, nCr = (n-1)C(r-1) + (n - 1)C(r)
        vector<vector<ll>> nCr(55, vector<ll>(55, 0));


        for(int i = 0; i < 55; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i)
                    nCr[i][j] = 1;
                else
                    nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
            }
        }

        /*
        now you have knowledge of nCr, hence you will be able to find for each n, how many numbers exist with k bits set using (bits)C(setBits)
        if that number exceeds n at any point, break and set that particular bit
        subtract the nCr value from n and continue, decrease k by 1 since you set one of the bits
        */
        n--; // bit indexes are one based
        ll ans = 0;
        while(k--){
            int pos = 0;
            while(nCr[pos + 1][k + 1] <= n)
                pos++;
            ans |= (1ll << pos);
            n -= nCr[pos][k + 1];
        }

        return ans;

    }
};