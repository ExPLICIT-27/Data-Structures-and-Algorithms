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
#define nline '\n'
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

// ---------- PBDS ---------- policy based data strcutures, faster sets and maps
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Ordered Set (no duplicates)
template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

// Ordered Multiset (allows duplicates using unique IDs)
template<typename T>
using ordered_multiset = tree<
    pair<T,int>,
    null_type,
    less<pair<T,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

// Ordered Map (key → value)
template<typename K, typename V>
using ordered_map = tree<
    pair<K,V>,
    null_type,
    less<pair<K,V>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;


void solve(){
    ll n;
    cin >> n;

    vll PD;
    
    ll t = n;
    for(ll i = 2; i*i <= n; i++){
        while(n%i == 0){
            PD.pb(i);
            n /= i;
        }
    }
    if(n > 1 && n != t)
        PD.pb(n);
    if(sz(PD) < 3){
        cout << "NO\n";
    }
    else{
        set<int> S(all(PD));
        if(sz(S) == 1){
            if(sz(PD) < 6)
                cout << "NO\n";
            else{
                cout << "YES\n";
                cout << PD[0] << " " << PD[1]*PD[2] << " ";
                ll c = PD[3];

                rep(i, 4, sz(PD))
                    c *= PD[i];
                cout << c << nline;
            }
        }
        else if(sz(S) == 2){
            if(sz(PD) < 4){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
                cout << PD[0] << " ";
                ll b = PD[1];
                rep(i, 2, sz(PD) - 1){
                    b *= PD[i];
                }

                cout << b << " " << PD.back() << nline;
            }
        }
        else{
            cout << "YES\n";
            cout << PD[0] << " ";
            ll b = PD[1];
            rep(i, 2, sz(PD) - 1){
                b *= PD[i];
            }
            cout << b << " " << PD.back() << nline;
        }
    }
}
int main(){
    fastio;
    int T;
    cin >> T;   
    while(T--){
        solve();
    }

    return 0;
}