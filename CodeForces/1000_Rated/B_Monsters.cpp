
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
        ll n, k;
        cin >> n >> k;

        vector<pll> a(n);

        rep(i, 0, n){
            cin >> a[i].ff;
            a[i].ss = i + 1;
            if(a[i].ff%k)
                a[i].ff %= k;
            else
                a[i].ff = k;
        }
        sort(all(a), [](const pll &a, const pll &b){
            if(a.ff != b.ff)
                return a.ff > b.ff;
            return a.ss < b.ss;
        });

        for(auto &p : a)
            cout << p.ss << " ";
        cout << endl;




    }
    return 0;
}