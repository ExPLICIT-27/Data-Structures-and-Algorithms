
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
int gcd(int a, int b){
    return (a == 0)? b : gcd(b%a, a);
}
class Solution {
public:
    // top down logic, call for each row
    int cnt(vector<vi> &m, int r, int curr, vector<vi> &dp){
        if(r == sz(m)){
            if(curr == 1)
                return 1;
            return 0;
        }
        if(dp[r][curr] != -1)
            return dp[r][curr];
        int res = 0;
        for(int c = 0; c < sz(m[0]); c++){
            res = (res + cnt(m, r + 1, gcd(curr, m[r][c]), dp))%MOD;
        }
        return dp[r][curr] = res;
    }
    int countCoprime(vector<vector<int>>& mat) {

        // post contest bottom up implementation
        int n = sz(mat), m = sz(mat[0]);
        vector<vi> dp(n, vi(151, 0));
        for(int c = 0; c < m; c++)
            dp[0][mat[0][c]] = (dp[0][mat[0][c]] + 1)%MOD;
        for(int r = 1; r < n; r++)   {
            for(int g = 1; g < 151; g++){
                if(!dp[r - 1][g]) continue;
                for(int c = 0; c < m; c++){
                    int ng = gcd(g, mat[r][c]);
                    dp[r][ng] = (dp[r][ng] + dp[r - 1][g])%MOD;
                }
            }
        }
        return dp[n - 1][1];
    }
};