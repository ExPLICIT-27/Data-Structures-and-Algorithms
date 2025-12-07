
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

// ---------- Fast IO ----------a
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

// ---------- Loops ----------
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define repd(i,a,b) for (int i = (a); i >= (b); i--)

// ---------- Constants ----------
const ll MOD = 1e9+7;
const ll INF = 1e18;

// sort based on the gain obtained while swapping out t2[i] for t1[i]
class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        vector<pll> unchosen;
        int used = 0;
        ll ans = 0;
        int n = sz(t1);
        rep(i, 0, n){
            if(t1[i] >= t2[i]){
                ans += t1[i];
                k--;
            }
            else{
                ans += t2[i];
                unchosen.push_back({t1[i], t2[i]});
            }
        }
        if(k <= 0)
            return ans;
        sort(all(unchosen), [](const pll &a, const pll &b){
            return (a.ff - a.ss) > (b.ff - b.ss);
        });
        rep(i, 0, k)
            ans += (unchosen[i].ff - unchosen[i].ss);
        return ans;
    }
};