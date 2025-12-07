
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
// generally more implementation heavy than usual easy
class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        sort(all(nums), [](const int &a, const int &b){
            ll x = a, y = b;
            string ss = "", sb = "";
            while(x){
                ss += (x%2 + '0');
                x /= 2;
            }
            while(y){
                sb += (y%2 + '0');
                y /= 2;
            }
            int i = sz(ss) - 1, j = sz(sb) - 1;
            x = 0, y = 0;
            ll pow = 1;
            while(i >= 0){
                x += pow*(ss[i] - '0');
                i--;
                pow <<= 1;
            }
            pow = 1;
            while(j >= 0){
                y += pow*(sb[j] - '0');
                j--;
                pow <<= 1;
            }
            if(x != y)
                return x < y;
            return a < b;
        });
        return nums;
    }
};