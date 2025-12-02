
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
ll findops(ll b, ll a){
    ll ops = 0;
    while(a > 0){
        a /= b;
        ops++;
    }

    return ops;
}
int main(){
    fastio;
    int T;
    cin >> T;
    while(T--){
        ld a, b;
        cin >> a >> b;
        // a = a/b, or b = b + 1
        // for a/b to become 0, b must be > a
        ll minops = LLONG_MAX;
        ll inc = 0;
        if(b == 1){
            b++;
            inc = 1;
        }
        while(inc < 32){
            ll currops = inc + findops(b, a);
            minops = min(minops, currops);
            inc++, b++;
        }
        cout << minops << endl;
    }
    return 0;
}