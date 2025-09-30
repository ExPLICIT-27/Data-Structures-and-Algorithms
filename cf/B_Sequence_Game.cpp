
#include <bits/stdc++.h>
using namespace std;

// ---------- Typedefs ----------
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define usi unordered_set<int>
#define si set<int>

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
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(n == 1){
            cout << 1 << endl;
            cout << a[0] << endl;
            continue;
        }
        vi out;
        out.pb(a[0]);
        for(int i = 1; i < n; i++){
            if(a[i] < a[i - 1]){
                out.pb(a[i]);
                out.pb(a[i]);
            }
            else
                out.pb(a[i]);
        }
        cout << out.size() << endl;
        for(int i : out)        
            cout << i << " ";
        cout << endl;
        
    }

    return 0;
}
