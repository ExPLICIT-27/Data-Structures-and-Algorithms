
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
        ll n, x;
        cin >> n >> x;
        

        vll a(n);
        
        rep(i, 0, n){
            cin >> a[i];
        }
        ll ans = 0;
        ll left = a[0] - x, right = a[0] + x;
        rep(i, 1, n){
            ll l1 = a[i] - x, r1 = a[i] + x;
            if(l1 > right || r1 < left){
                ans++;
                left = l1, right = r1;
            }
            else{
                left = max(l1, left);
                right = min(r1, right);
            }
        }
        cout << ans << endl;
    
    }
    return 0;
}