
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
        ll num;
        cin >> num;
        vi a;
        while(num){
            a.pb(num%10);
            num /= 10;
        }

        // find the latest 2 digits divisible by 25, so min operations is removing all digits between and after those 2, all the others 
        // before can be taken
        reverse(all(a));
        int n = sz(a);
        int f = -1, s = -1;
        rep(i, 0, n){
            rep(j, i + 1, n){
                if((a[i]*10 + a[j])%25 == 0){
                    f = max(f, i);
                    s = max(s, j);
                }
            }
        }
        cout << s - f - 1 + n - s - 1 << endl;
    }
    return 0;
}