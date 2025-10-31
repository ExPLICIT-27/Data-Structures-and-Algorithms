
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
        string s, t;

        cin >> s >> t;
        uset<int> last;
        int n = sz(s), m = sz(t);
        int j = m - 1;
        repd(i, n - 1, 0){
            if(s[i] == t[j]){
                last.insert(i);
                j--;
            }
            if(j < 0)
                break;
        }
        if(j >= 0){
            cout << "NO" << endl;
            continue;
        }
        umap<char, vi> mmp;
        repd(i, n - 1, 0){
            mmp[s[i]].pb(i);
        }
        bool ok = true;
        rep(i, 0, n){
            if(!last.count(i)){
                int idx = mmp[s[i]].back();
                if(last.count(idx)){
                    ok = false;
                    break;
                }
                mmp[s[i]].pop_back();
            }
        }
        if(ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    

        
    }
    return 0;
}