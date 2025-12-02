
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
    int minMirrorPairDistance(vector<int>& nums) {
        map<int, vi> mp;
        rep(i, 0, sz(nums)){
            mp[nums[i]].pb(i);
        }
        int ans = sz(nums) + 1;
        rep(i, 0, sz(nums)){
            int t = nums[i];
            int c =0;
            while(t > 0){
                c = c*10 + t%10;
                t /= 10;
            }           
            if(mp.count(c)){
                auto it = upper_bound(all(mp[c]), i);
                if(it != mp[c].end())
                    ans = min(ans, *it - i);
            }
        }
        return ans == sz(nums) + 1 ? -1 : ans;
    }
};