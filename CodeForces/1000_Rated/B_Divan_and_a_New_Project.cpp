
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
        ll n;
        cin >> n;
        vector<pll> a(n);

        rep(i, 0, n){
            ll tmp;
            cin >> tmp;
            a[i] = {tmp, i};
        }

        vll ans(n);
        sort(all(a), greater<pll>());
        ll coord = 1;
        ll mindist = 0;
        rep(i, 0, n){
            ans[a[i].ss] = coord;
            mindist += 2*llabs(coord)*a[i].ff;
            coord = (i%2)? -coord + 1 : -coord;
        }
        cout << mindist << endl;
        cout << 0 << " ";
        rep(i, 0, n)
            cout << ans[i] << " ";
        cout << endl;

    }
    return 0;
}