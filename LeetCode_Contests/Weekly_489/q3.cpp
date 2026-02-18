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
    int EX(string &s, int l, int r){
        int curr = 0;
        while(l >= 0 && r < sz(s) && s[l] == s[r]){
            l--, r++;
            curr += 2;
        }

        return curr;
    }
    int almostPalindromic(string s) {
        int n = sz(s);


        int ans = 0;
        for(int i = 0; i < n; i++){
            // odd
            int l = i - 1, r = i + 1;
            int curr = 1;
            while(l >= 0 && r < n){
                if(s[l] != s[r]){
                    curr += max(EX(s, l - 1, r), EX(s, l, r + 1));
                    break;
                }
                else{
                    l--, r++;
                    curr += 2;
                }                
            }
            
            ans = max(ans, min(curr + 1, n));
            // even
            l = i, r = i + 1;
            curr = 0;
            while(l >= 0 && r < n){
                if(s[l] != s[r]){
                    curr += max(EX(s, l - 1, r), EX(s, l, r + 1));
                    break;
                }
                else{
                    l--, r++;
                    curr += 2;
                }  
                
            }
            ans = max(ans, min(curr + 1, n));

        }
        return ans;
    }
};