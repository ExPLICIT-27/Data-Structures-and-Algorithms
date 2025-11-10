
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

        vi a(n), b(n);

        rep(i, 0, n){
            cin >> a[i];
        }
        rep(i, 0, n){
            cin >> b[i];
        }
        
        map<int, int> amp;
        int curr = a[0], cnt = 1;
        
        rep(i, 1, n){
            if(a[i] == curr){
                cnt++;
            }
            else{
                amp[curr] = max(amp[curr], cnt);
                curr = a[i], cnt = 1;
            }
        }

        amp[curr] = max(amp[curr], cnt);
        map<int, int> bmp;

        curr = b[0], cnt = 1;
        rep(i, 1, n){
            if(b[i] == curr){
                cnt++;
            }
            else{
                bmp[curr] = max(bmp[curr], cnt);
                curr = b[i], cnt = 1;
            }
        }
        bmp[curr] = max(bmp[curr], cnt);

        int ans = 1;
        for(auto &p : amp){
            if(bmp.count(p.ff)){
                ans = max(ans, p.ss + bmp[p.ff]);
            }
            ans = max(ans, p.ss);
        }
        for(auto &p : bmp){
            ans = max(ans, p.ss);
        }
        cout << ans << endl;
    }
    return 0;
}