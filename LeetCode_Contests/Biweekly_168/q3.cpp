
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
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = sz(nums1);
        long long result = 0;
        long long lastop = LLONG_MAX;
        int l = nums2.back();
        for(int i = 0; i < n; i++){
            if(nums2[i] > nums1[i]){
                if(l >= nums1[i] && l <= nums2[i])
                    lastop = 0;
                else if(l <= nums1[i]){
                    lastop = min(lastop, 1ll*abs(l - nums1[i]));
                }
                else if(l >= nums2[i])
                    lastop = min(lastop, 1ll*abs(l - nums2[i]));
            }
            else{
                if(l >= nums2[i] && l <= nums1[i])
                    lastop = 0;
                else if(l <= nums2[i]){
                    lastop = min(lastop, 1ll*abs(l - nums2[i]));
                }
                else if(l >= nums1[i])
                    lastop = min(lastop, 1ll*abs(l - nums1[i]));
            }
            result += abs(nums1[i] - nums2[i]);
        }
        return result + lastop + 1;
        
    }
};