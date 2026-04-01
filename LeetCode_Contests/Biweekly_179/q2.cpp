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
    const ll M = 1e9 + 7;
    ll F(ll n){
        ll ans = 1;

        for(ll i = 2; i <= n; i++)
            ans = (__int128)ans*i%M;

        return ans;
    }
    ll binexp(ll b, ll p){
        ll ans = 1;

        while(p){
            if(p & 1)
                ans = (__int128)ans*b%M;
            p >>= 1;
            b = (__int128)b*b%M;
        }

        return ans;
    }
    int countVisiblePeople(int n, int pos, int k) {
        ll lcnt = pos;
        ll rcnt = n - pos - 1;

        if(lcnt + rcnt < k)
            return 0;
        
        // 0, k | 1, k - 1 | 2, k - 2 ... k, 0
        vll lCr(lcnt + 1), rCr(rcnt + 1);
        lCr[0] = 1ll, rCr[0] = 1ll;

        for(ll i = 1; i <= max(lcnt, rcnt); i++){
            if(i <= lcnt){
                lCr[i] = (__int128)lCr[i - 1]*(lcnt - (i - 1))%M;
                lCr[i] = (__int128)lCr[i]*binexp(i, M - 2)%M;
            }
            if(i <= rcnt){
                rCr[i] = (__int128)rCr[i - 1]*(rcnt - (i - 1))%M;
                rCr[i] = (__int128)rCr[i]*binexp(i, M - 2)%M;
            }
        }

        ll ans = 0;
        for(int i = 0; i <= k; i++){
            if(lcnt < i || rcnt < k - i)
                continue;
            // (lcnt)C(i) * (rcnt)C(i - k)
            ll mul = 2*lCr[i]*rCr[k - i]%M;
            
            ans = (__int128)(ans + mul%M)%M;
        }

        return ans;
    }
};