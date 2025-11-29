
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
        ll w, h, k1, k2, k3, k4;
        cin >> w >> h;

        // bottomx
        cin >> k1;
        vll bx(k1);
        rep(i, 0, k1)
            cin >> bx[i];
        
        // topx
        cin >> k2;
        vll tx(k2);
        rep(i, 0, k2)
            cin >> tx[i];

        // lefty
        cin >> k3;
        vll ly(k3);
        rep(i, 0, k3)
            cin >> ly[i];
        
        // righty
        cin >> k4;
        vll ry(k4);
        rep(i, 0, k4)
            cin >> ry[i];
        
        // bottom 
        ll ans = 0;
        ll p1 = bx[0], p2 = bx.back();
        ans = max(ans, (p2 - p1)*h)        ;
        // top
        p1 = tx[0], p2 = tx.back();
        ans = max(ans, (p2 - p1)*h);

        // left;
        p1 = ly[0], p2 = ly.back();
        ans = max(ans, (p2 - p1)*w);

        //right 
        p1 = ry[0], p2 = ry.back();
        ans = max(ans, (p2 - p1)*w);

        cout << ans << endl;
        

    }
    return 0;
}