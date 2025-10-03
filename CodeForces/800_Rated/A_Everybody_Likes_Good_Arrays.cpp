
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

// ---------- Fast IO ----------
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

// ---------- Loops ----------
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define repd(i,a,b) for (int i = (a); i >= (b); i--)

// ---------- Constants ----------
const ll MOD = 1e9+7;
const ll INF = 1e18;

int main() {
    fastio;

    int T; 
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n);
        int ops = 0;
        rep(i, 0, n){
            cin >> a[i];
        }
        int parity = a[0]%2;
        rep(i, 1, n){
            if(a[i]%2 == parity)
                ops++;
            else
                parity = a[i]%2;
        }
        cout << ops << endl;
    }
    return 0;
}
