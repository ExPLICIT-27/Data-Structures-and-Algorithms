
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
        ll n, p;
        cin >> n >> p;

        vector<pll> a(n);
        rep(i, 0, n){
            ll t;
            cin >> t;
            a[i].ff = t;
        }
        rep(i, 0, n){
            ll t;
            cin >> t;
            a[i].ss = t;
        }

        sort(all(a), [](const pll &x, const pll &y){
            return x.ss < y.ss;
        });
        ll ans = p;
        int curr = 1;
        rep(i, 0, n){
            if(a[i].ss <= p){
                if(curr + a[i].ff <= n){
                    ans += a[i].ss*a[i].ff;
                    curr += a[i].ff;
                }
                else{
                    ans += a[i].ss*(n - curr);
                    curr = n;
                }
            }
            else{
                ans += p*(n - curr);
                break;
            }
            if(curr >= n)
                break;
        }
        cout << ans << endl;

    }
    return 0;
}