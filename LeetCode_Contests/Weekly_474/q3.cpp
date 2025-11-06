
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
    // find out exclusive delivery times for each drone, and check if the remaining time (found by subtracting the total rest hours from
    // the total time) is enough for them
    long long minimumTime(vector<int>& d, vector<int>& r) {
        ll lo = 1, hi = 1e15;
        ll d1 = d[0], d2 = d[1], r1 = r[0], r2 = r[1];
        while(lo <= hi){
            ll m = (lo + hi)/2;
            ll common_rest_hrs = m/lcm(r1, r2);
            ll r1_exc_rest = m/r1 - common_rest_hrs;
            ll r2_exc_rest = m/r2 - common_rest_hrs;
            ll delivery_time_left = m - m/r1 - m/r2 + common_rest_hrs;
            ll d1_exc_hrs = max(0ll, d1 - r2_exc_rest);
            ll d2_exc_hrs = max(0ll, d2 - r1_exc_rest);
            if(d1_exc_hrs + d2_exc_hrs > delivery_time_left)
                lo = m + 1;
            else
                hi = m - 1;
        }
        return hi + 1;
    }
};