
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
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        map<char, vi> mp;
        vi greens;
        for(int i = 1; i <= n; i++){
            if(s[i - 1] == 'g'){
                greens.pb(i);
            }
            else
                mp[s[i - 1]].pb(i);
        }

        int ans = 0;
        if(c == 'g'){
            cout << 0 << endl;
            continue;
        }
        else{
            for(int t : mp[c]){
                auto it = upper_bound(all(greens), t);
                if(it != greens.end()){
                    ans = max(ans, *it - t);
                }
                else
                    ans = max(ans, n - t + greens[0]);
            }
        }

        cout << ans << endl;
    }
    return 0;
}