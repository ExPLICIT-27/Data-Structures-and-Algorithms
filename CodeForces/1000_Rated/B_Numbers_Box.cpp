
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

int main(){
    fastio;
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;

        vector<vi> a(n, vi(m));
        int nc = 0, mnabs = 102;
        rep(i, 0, n){
            rep(j, 0, m){
                cin >> a[i][j];
                if(a[i][j] <= 0){
                    nc++;
                }
                mnabs = min(mnabs, abs(a[i][j]));
            }
        }
        ll ans = 0;
        rep(i, 0, n)
            ans += accumulate(all(a[i]), 0ll, [](ll sum, ll a){
                return sum + abs(a);
            });
        if(nc%2)
            ans -= 1ll*2*mnabs;
        cout << ans << endl;
    }
    return 0;
}