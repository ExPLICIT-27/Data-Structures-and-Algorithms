
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
        int n;
        cin >> n;
        vll a(n);
        umap<ll, ll> mp;
        ll max_f = 0;
        rep(i, 0, n){
            cin >> a[i];
            mp[a[i]]++;
            max_f = max(max_f, mp[a[i]]);
        }

        if(max_f == n){
            cout << 0 << endl;
        }
        else{
            int ops = 0;
            ll curr_f = max_f;
            while(curr_f < n){
                ops++;
                curr_f += max_f;

                ops += (min(n - max_f, max_f));
                max_f = curr_f;
                
            }
            cout << ops << endl;
        } 
    }
    return 0;
}