
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
        ll n, k, b, s;
        cin >> n >> k >> b >> s; 
        // s should be at least b*k, if i need a beauty of b, (exactly k to each element of the array, therefor k/k = 1, a total of b)
        // s can be at most b*k + (k - 1)*n, [(2*k - 1)/k is still 1, so this is the max sum possible]
        if((s < b*k) || (s > (b*k + (k - 1)*n))){
            cout << -1 << endl;
        }
        else{
            ll nth = b*k + min(k - 1, s - b*k);
            ll rem = s - nth;
            cout << nth << " ";
            for(int i = 0; i < n - 1; i++){
                cout << min(k - 1, rem) << " ";
                rem -= min(k - 1, rem);
            }
            cout << endl;
        }
    
    }
    return 0;
}