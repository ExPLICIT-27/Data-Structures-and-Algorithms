
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
        ll n, k;
        cin >> n >> k;


        vll A(n);

        rep(i, 0, n){
            cin >> A[i];
        }

        sort(all(A));

        rep(i, 1, n){
            A[i] += A[i - 1];
        }
        ll ans = 0;
        rep(i, 0, k + 1){
            int l = 2*i - 1;
            ll lsum = l < 0 ? 0 : A[l];
            ll rsum = A[n - (k - i) - 1];
            ans = max(ans, rsum - lsum);
        }   

        cout << ans << endl;
    }

    return 0;
}