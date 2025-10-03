
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

int gcd(int a, int b){
    return (a == 0)? b : gcd(b%a, a);
}
int main() {
    fastio;

    int T; 
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n);
        rep(i, 0, n){
            int tmp;
            cin >> tmp;
            if(tmp == 2)
                a[i] = 1;
        }

        for(int i = 1; i < n; i++)
            a[i] += a[i - 1];
        
        int k = -1;
        for(int i = 0; i < n - 1; i++){
            if(a[i] == a.back() - a[i]){
                k = i + 1;
                break;
            }
        }
        cout << k << endl;

    }
    return 0;
}
