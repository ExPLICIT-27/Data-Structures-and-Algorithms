
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
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = sz(s);
        vll pow10(n + 1);
        vll val(n);
        vi cnt(n);
        vll dsum(n);
        pow10[0] = 1;
        ll currval = 0, csum = 0;
        int currcnt = 0;
        rep(i, 1, n + 1){
            csum += s[i - 1] - '0';
            pow10[i] = (pow10[i - 1]*10)%MOD;
            ll d = s[i - 1] - '0';
            if(d){
                currcnt++;
                currval = (currval*10 + d)%MOD;
            }
            val[i - 1] = currval;
            cnt[i - 1] = currcnt;
            dsum[i - 1] = csum;
        }
        vi ans;
        ans.reserve(sz(queries));
        for(auto &q : queries){
            int R = q[1], L = q[0];
            int lcnt = (L - 1 < 0)? 0 : cnt[L - 1];
            int rnct = cnt[R];

            ll rval = val[R];
            ll lval = (L - 1 < 0)? 0 : val[L - 1];
            ll rsum = dsum[R];
            ll lsum = (L - 1 < 0)? 0 : dsum[L - 1];
            ll qans = (rval - lval*pow10[rnct - lcnt]%MOD + MOD)*(rsum - lsum)%MOD;
            ans.pb(qans);
        }
        return ans;
    }
};