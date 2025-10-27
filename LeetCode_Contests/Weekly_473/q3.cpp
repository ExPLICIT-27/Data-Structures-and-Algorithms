
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
class Solution {
public:
    
    long long countStableSubarrays(vector<int>& v) {
        int n = sz(v);
        map<pair<int, ll>, int> mp;
        vll p(n);
        p[0] = 0;
        rep(i, 1, n)
            p[i] = p[i - 1] + v[i];
        ll res = 0;
        rep(i, 0, n){
            int j = i - 2;
            if(j >= 0)
                mp[{v[j], p[j]}]++;
            if(mp.count({v[i], p[i] - 2*v[i]}))
                res += mp[{v[i], p[i] - 2*v[i]}];
        }
        return res;
        
    }
};