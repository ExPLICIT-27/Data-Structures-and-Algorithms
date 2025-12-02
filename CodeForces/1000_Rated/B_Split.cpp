
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

int main(){
    fastio;
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        n *= 2;
        map<ll, ll> mp;
        rep(i, 0, n){
            ll t;
            cin >> t;
            mp[t]++;
        }
        ll ans = 0, oddc = 0;
        for(auto [x, f] : mp){
            if(f & 1){
                oddc++;
                ans++;
            }
            else{
                if(f & 2)
                    ans += 2;
            }
        }
        ll cnt = 0;
        for(auto [x, f] : mp){
            if(f & 1 ^ 1){
                if(!(f & 2))
                    cnt++;
            }
        }
        if(oddc >= 2)
            cout << ans + 2*cnt << endl;
        else{
            cout << ans + 2*(cnt - cnt%2) << endl;
        }
    }
    return 0;
}