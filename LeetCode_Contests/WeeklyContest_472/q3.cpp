
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
   
    string lexGreaterPermutation(string s, string target) {
        map<char, int> mp;
        for(char c : s)
            mp[c]++;
        string result = "";
        int n = sz(target);
        for(int i = 0; i < n; i++){
            map<char, int> tmp = mp;
            bool found = true;
            string curr = "";
            for(int j = 0; j < i; j++){
                if(tmp[target[j]] > 0){
                    curr += target[j];
                    tmp[target[j]]--;
                }
                else{
                    found = false;
                    break;
                }
            }
            if(!found)
                continue;
            char rep = '-';
            for(auto &pair : tmp){
                if(pair.second > 0 && pair.first > target[i]){
                    rep = pair.first;
                    pair.second--;
                    break;
                }
            }
            if(rep == '-')
                continue;
            curr += rep;
            for(auto pair : tmp){
                rep(j, 0, pair.second)
                    curr += pair.first;
            }
            result = (result == "")? curr : (curr < result)? curr : result;
        }
        return result;
    }
};