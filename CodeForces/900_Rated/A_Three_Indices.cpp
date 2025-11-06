
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
#define setBits(n) __builtin_popcountll(n)

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
        vi a(n);
        rep(i, 0, n){
            cin >> a[i];
        }
        
        vi suffmin(n);
        suffmin[n - 1] = n - 1;
        repd(i, n - 2, 0){
            if(a[i] < a[suffmin[i + 1]])
                suffmin[i] = i;
            else
                suffmin[i] = suffmin[i + 1];
        }
        int x = -1, b = -1, c = -1;
        bool ok = false;
        rep(i, 0, n){
            rep(j, i + 1, n){
                if(a[i] < a[j]){
                    if(a[suffmin[j]] < a[j]){
                        ok = true;
                        x = i, b = j, c = suffmin[j];
                        break;
                    }
                }
            }
            if(ok)
                break;
        }
        if(ok){
            cout << "YES\n";
            cout << x + 1 << " " << b + 1 << " " << c + 1 << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}