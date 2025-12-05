
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

int rc(vll &A, ll x){
    int n = sz(A);
    int c1 = -1;
    rep(i, 0, n){
        int j = 0;
        bool ok = true;
        while(j < 32){
            if(((A[i] >> j) & 1) && !((x >> j) & 1)){
                ok = false;
                break;
            }
            j++;
        }
        if(ok)
            c1++;
        else
            break;
    }
    return c1;
}
int main(){
    fastio;
    int T;
    cin >> T;
    while(T--){
        ll n, x;
        cin >> n >> x;

        vll A(n), B(n), C(n);

        rep(i, 0, n)
            cin >> A[i];
        rep(i, 0, n)
            cin >> B[i];
        rep(i, 0, n)
            cin >> C[i];
        
        ll sc = 0;
        int c1 = rc(A, x), c2 = rc(B, x), c3 = rc(C, x);
        rep(i, 0, c1 + 1){
            sc |= A[i];
        }
        rep(i, 0, c2 + 1){
            sc |= B[i];
        }
        rep(i, 0, c3 + 1){
            sc |= C[i];
        }

        if(sc == x)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
