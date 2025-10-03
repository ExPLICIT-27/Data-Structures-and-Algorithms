


#include <bits/stdc++.h>
using namespace std;

// ---------- Typedefs ----------
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vec vector
#define uset unordered_set
#define umap unordered_map

// ---------- Macros ----------
#define pushb push_back
#define popb pop_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define sum(a) accumulate((a).begin(), (a).end(), 0LL)

// ---------- Fast IO ----------
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

// ---------- Loops ----------
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define repr(i,a,b) for (int i = (a); i >= (b); i--)

// ---------- Constants ----------
const ll MOD = 1e9+7;
const ll INF = 1e18;

int main() {
    fastio;

    int T; 
    cin >> T;
    while (T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if((d < b) || (c > a && ((c - a) > (d - b)))){
            cout << -1 << endl;
        }
        else{
            ll dist;
            if(a > c){
                dist = a - c + 2*(d - b);
            }
            else{
                dist = 2*(d - b) - (c - a);
            }
            cout << dist << endl;
        }
    }

    return 0;
}
