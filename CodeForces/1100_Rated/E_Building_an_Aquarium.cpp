
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
ll FindCapacity(vll &A, ll h){
    int n = sz(A);

    A[0] = A[n - 1] = h;

    vll dp(n);
    ll prev = A[0];
    rep(i, 1, n){
        if(A[i] > prev){
            prev = A[i];
            dp[i] = 0;
        }
        else{
            dp[i] = min(max(0ll, h - A[i]), prev - A[i]);
        }
    }
    prev = A[n - 1];
    repd(i, n - 2, 0){
        if(A[i] > prev){
            prev = A[i];
            dp[i] = 0;
        }
        else{
            dp[i] = min(dp[i], prev - A[i]);
        }
    }
    
    dp[0] = dp[n - 1] = 0;
    return vsum(dp);
}
int main(){
    fastio;
    int T;
    cin >> T;
    while(T--){
        ll n, x;
        cin >> n >> x;


        vll A(n + 2);

        rep(i, 1, n + 1){
            cin >> A[i];
        }

        // trapping rainwater, but with a modification
        // binary search for h prolly
        ll l = min(A[0], A.back()), r = vmax(A) + x + 1;

        while(l <= r){
            ll m = (l + r)/2;
            if(FindCapacity(A, m) <= x)
                l = m + 1;
            else
                r = m - 1;
        }
        cout << r << endl;
    }
    return 0;
}