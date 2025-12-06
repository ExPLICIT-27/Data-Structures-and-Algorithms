
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
        string s;
        cin >> s;
        if(count(all(s), '1') == sz(s))
            cout << 1ll*sz(s)*sz(s) << endl;
        else{
            s += s;
            int n = sz(s);
            int cnt = s[0] - '0';
            int mcnt = cnt;
            rep(i, 1, n){
                if(s[i] == '1')
                    cnt++;
                else{
                    cnt = 0;
                }
                mcnt = max(mcnt, cnt);
            }
            ll ans = 1ll*(mcnt + 1)/2*(mcnt + 1 - (mcnt + 1)/2);
            cout << ans << endl;
        }

    }
    return 0;
}