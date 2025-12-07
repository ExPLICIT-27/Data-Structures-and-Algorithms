
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
    pll,                               
    null_type,                          
    less<pll>,                          
    rb_tree_tag,                        
    tree_order_statistics_node_update   
> ordered_set; // this wont tle
// PBSD saved my ass, could would'nt be fast enough, distance(s.begin(), x) is O(n), i thought it was O(1)
class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& req) {
        int n = sz(damage);
        vll PD(n);
        PD[0] = damage[0];

        rep(i, 1, n){
            PD[i] += PD[i - 1] + damage[i];
        }
        ll ans = 0;
        umap<int, pll> mp;
        ordered_set D;
        rep(i, 0, n){
            if(hp - PD[i] >= req[i]){
                ans++;
            }
            mp[i] = {req[i] - (hp - PD[i]), i};
            D.insert({req[i] - (hp - PD[i]), i});
        }
        rep(i, 1, n){
            D.erase(mp[i - 1]);
            ll gain = PD[i - 1];
            auto it = D.upper_bound({gain, LLONG_MAX});
            if(it == D.begin())
                continue;
            else{
                --it;
                ans += D.order_of_key(*it) + 1;
            }
        }
        return ans;
    }
};