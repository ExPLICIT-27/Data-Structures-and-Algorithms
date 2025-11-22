
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
    long long countDistinct(long long n) {
        string s = to_string(n);
        int L = s.size();
        ll ans = 0;
        // first L - 1 digits, => 9, 9*9, etc
        ll p = 9;
        rep(i, 1, L){
            ans += p;
            p *= 9;
        }
        // handle the last case
        // iterate and add 9*remaining digits for every time the current digit is < the
        // digit at this position
        // if its a zero, break out
        rep(i, 0, L){
            int rem = L - i - 1;
            int d = s[i] - '0';
            if(!d)
                return ans;
            ll p9 = 1;
            rep(j, 0, rem) p9 *= 9;
            ans += 1ll*(d - 1)*p9;
        }
        // inlcude current number, it doesnt have any zeros
        return ++ans;
    }
};