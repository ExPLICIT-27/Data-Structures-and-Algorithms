
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
    vll genPrimes(int n){
        vll primes;
        vector<bool> isP(n + 1, true);
        isP[0] = isP[1] = false;
        for(ll i = 2; i <= n; i++){
            if(isP[i]){
                for(ll j = i*i; j <= n; j += i)
                    isP[j] = false;
            }
        }
        for(ll i = 2; i <= n; i++){
            if(isP[i])
                primes.pb(i);
        }
        return primes;
    }
    int largestPrime(int n) {
        vll primes = genPrimes(n);
        uset<ll> pset(all(primes));
        ll csum = 0;
        ll ans = 0;
        for(int i = 0; i < sz(primes); i++){
            csum += primes[i];
            if(pset.count(csum) && csum <= n)
                ans = csum;
            if(csum > n)
                break;
        }
        return ans;
    }
};