
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
        ll a, b, c;
        cin >> a >> b >> c;
        // x-d, x, and x + d
        //try a
        ll d1 = c - b;
        ll a1 = b - d1;
        if(a1 > 0 && a1%a == 0){
            cout << "YES\n";
            continue;
        }
        if((a + c)%2 == 0 && ((a + c)/2)%b == 0){
            cout << "YES\n";
            continue;
        }
        d1 = b - a;
        ll c1 = b + d1;
        if(c1 > 0 && c1%c == 0){
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}