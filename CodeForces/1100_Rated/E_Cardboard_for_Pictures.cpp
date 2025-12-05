
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
ll calcArea(ll w, vll &A, ll c){
    ll sm = 0;
    int n = sz(A);
    rep(i, 0, n){
        ll side = A[i] + 2*w;
        sm += side*side;
        if(sm > c)
            return sm;
    }
    return sm;
}
int main(){
    fastio;
    int T;
    cin >> T;
    while(T--){
        ll n, c;
        cin >> n >> c;

        vll A(n);
        rep(i, 0, n){
            cin >> A[i];
        }

        ll l = 1, r = 1e9;
        ll ans = -1;
        while(l <= r){
            ll m = (l + r)/2;
            ll area = calcArea(m, A, c);
            // cout << "debug : "<< m << " " << area << endl;
            if(area <= c){
                ans = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        cout << ans << endl;

    }
    return 0;
}