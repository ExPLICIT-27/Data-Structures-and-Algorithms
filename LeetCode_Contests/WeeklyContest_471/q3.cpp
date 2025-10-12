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
    int doubles(string &s, char c1, char c2){
        int res = 0;
        int n = s.length();
        int cnt = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0;i < n; i++){
            if(s[i] == c1)
                cnt++;
            else if(s[i] == c2)
                cnt--;
            else{
                cnt = 0;
                mp.clear();
            }
            if(!mp.count(cnt))
                mp[cnt] = i;
            res = max(res, i - mp[cnt]);
        }
        return res;
    }
    int longestBalanced(string s) {
        int n = s.length();
        // singles
        int res1 = 1;
        char curr = s[0];
        int cnt = 1;
        for(int i = 1; i < n; i++){
            res1 = max(res1, cnt);
            if(s[i] != curr){
                curr = s[i];
                cnt = 1;
            }
            else
                cnt++;
            res1 = max(res1, cnt);
        }
        res1 = max(res1, cnt);

        // triples
        map<pair<int, int>, int> mp;
        int res3 = 0;
        int v1 = 0, v2 = 0;
        mp[{0, 0}] = -1;
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(c == 'a'){
                v1++;
            }
            else if(c == 'c')
                v2++;
            else{
                v1--, v2--;
            }
            if(!mp.count({v1, v2}))
                mp[{v1, v2}] = i;
            res3 = max(res3, i - mp[{v1, v2}]);
        }

        // doubles ab, ac, bc
        int res2 = max({doubles(s, 'a', 'b'), doubles(s, 'a', 'c'), doubles(s, 'b', 'c')});
        cout << res1 << " " << res2 << " " << res3;
        return max({res1, res2, res3});
    }
};