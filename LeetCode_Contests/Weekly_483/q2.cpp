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
    set<vector<string>> S;
    void chck(vector<string> &square){
        vector<string> T = square;
        sort(all(T));
        do{
            if(T[0][0] == T[1][0] && T[0][3] == T[2][0] && T[3][0] == T[1][3] && T[3][3] == T[2][3])
                S.insert(T);
        }while(next_permutation(all(T)));
    }
    void helper(vector<string> &words, vector<string> &temp, int i){
        if(sz(temp) == 4){
            chck(temp);
            return;
        }
        if(i >= sz(words))
            return;
        temp.push_back(words[i]);
        helper(words, temp, i + 1);
        temp.pop_back();
        helper(words, temp, i + 1);
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<string> T;
        helper(words, T, 0);
        vector<vector<string>> ans(all(S));

        sort(all(ans));
        return ans;
    }
};