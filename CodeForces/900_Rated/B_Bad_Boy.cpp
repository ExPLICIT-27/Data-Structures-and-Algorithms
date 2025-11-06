
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
        ll n, m, x, y;
        cin >> n >> m >> x >> y;
        vector<pll> c = {{1,1}, {1,m}, {n, 1}, {n, m}};
        pll a = {1, 1}, b = {1, 1};
        ll curr = llabs(x - a.ff) + llabs(y - a.ss) + llabs(a.ff - b.ff) + llabs(a.ss - b.ss) + llabs(x - b.ff) + llabs(y - b.ss);
        rep(i, 0, 4){
            rep(j, 0, 4){
                ll t = llabs(x - c[i].ff) + llabs(y - c[i].ss) + llabs(c[i].ff - c[j].ff) + llabs(c[i].ss - c[j].ss) + llabs(x - c[j].ff) + llabs(y - c[j].ss);

                if(t > curr){
                    curr = t;
                    a = c[i];
                    b = c[j];
                }
            }
        }
        cout << a.ff << " " << a.ss << " " << b.ff << " " << b.ss << endl;
    }
    return 0;
}