
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
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        umap<int, vector<int>> mp;
        int n = sz(nums);
        rep(i, 0, n){
            mp[nums[i]].pb(i);
        }
        for(auto &p : mp){
            int t = INT_MAX;
            for(int i = 2; i < sz(p.ss); i++){
                t = min(t, abs(p.ss[i] - p.ss[i - 1]) + abs(p.ss[i] - p.ss[i - 2] +abs(p.ss[i - 1] - p.ss[i - 2])));
            }
            ans = min(ans, t);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};