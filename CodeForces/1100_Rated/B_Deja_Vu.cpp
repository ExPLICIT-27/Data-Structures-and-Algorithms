
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
        ll n, q;
        cin >> n >> q;

        vll A(n);
        vll B;
        set<ll> st;


        rep(i, 0, n){
            cin >> A[i];
        }
        rep(i, 0, q){
            ll t;
            cin >> t;
            if(!st.count(t)){
                B.pb(t);
                st.insert(t);
            }
        }

        
        for(int po : B){
            ll p = (1 << po);
            rep(i, 0, n){
                if(A[i]%p == 0)
                    A[i] += p/2;
            }
        }
        for(ll i : A)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}