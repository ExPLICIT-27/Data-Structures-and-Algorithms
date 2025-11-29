
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
        ll a, b;
        cin >> a >> b; // a is positive, b non negative


        ll xorval;

        // trick to instantly find the xor from 0 to n in O(1) time
        if((a - 1)%4 == 0)
            xorval = a - 1;
        else if((a - 1)%4 == 1)
            xorval = 1;
        else if((a - 1)%4 == 2)
            xorval = a;
        else
            xorval = 0;
        
        if(xorval == b)
            cout << a << endl;
        else if((xorval^b) != a)
            cout << a + 1 << endl;
        else
            cout << a + 2 << endl;


    }
    return 0;
}