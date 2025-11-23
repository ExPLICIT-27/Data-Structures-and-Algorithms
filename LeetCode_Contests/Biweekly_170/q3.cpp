
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
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        ll maxposs = 1ll*n*(n + 1)/2;
        ll minposs = -maxposs;
        if(target > maxposs || target < minposs || (llabs(target)%2 != maxposs%2))
            return {};
        ll req;
        if(target >= 0)
            req = (maxposs - target)/2;
        else
            req = maxposs + (minposs - target)/2;
        
        vector<bool> b(n);
        for(int c = n; c > 0 && req > 0; c--){
            if(req >= c){
                req -= c;
                b[c - 1] = true;
            }
        }
        vector<int> ans;
        repd(i, n - 1, 0){
            if(b[i]) ans.pb(-i - 1);
        }
        rep(i, 0, n){
            if(!b[i]) ans.pb(i + 1);
        }

        return ans;
    }
};