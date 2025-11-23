
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
    int maxBalancedSubarray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if(n < 4)
            return 0;
        
        map<pii, int> mp;
        int curr = 0;
        int c= 0;
        vector<int> pre;
        rep(i, 0, n){
            curr ^= nums[i];
            if(nums[i]%2)
                c++;
            else
                c--;
            if(curr == 0 && c == 0)
                ans = max(ans, i + 1);
            if(mp.count({curr, c})){
                ans = max(ans, i - mp[{curr, c}]);
            }
            else
                mp[{curr, c}] = i;
        }
        return ans;
        
        
    }
};