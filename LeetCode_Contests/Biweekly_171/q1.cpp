
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


class Solution {
public:
    bool isPrime(int n){
        if(n <= 1)
            return false;
        for(int i = 2; i*i <= n; i++){
            if(n%i == 0)
                return false;
        }
        return true;
    }
    bool completePrime(int num) {
        string nm = to_string(num);
        for(int i = 0; i < sz(nm); i++){
            if(!isPrime(stoi(nm.substr(i))))
                return false;
            if(!isPrime(stoi(nm.substr(0, i + 1))))
                return false;
        }
        return true;
    }
};