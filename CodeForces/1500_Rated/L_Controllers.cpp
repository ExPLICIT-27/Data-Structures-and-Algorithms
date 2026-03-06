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
#define ExPLICIT_27 ios::sync_with_stdio(false); cin.tie(nullptr)

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
    int n; cin >> n;

    string S; cin >> S;

    int pos = 0, neg = 0;

    for(char c : S){
        if(c == '+')
            pos++;
        else
            neg++;
    }

    int q; cin >> q;


    while(q--){
        ll a, b; cin >> a >> b;

        if(pos == neg){
            cout << "YES\n";
            continue;
        }

        /*
        using a +, - on the same button cancels it out
        which is effectively doing a +0

        I need to see if there exists an x and y such that
        a*x = y*b
        or
        b*x = y*b
        possible values for x are in the range (0, N)
        i will try only for cases where ax%b == 0

        correct yeah, but TLE's


        alright, 
        first set of eqns are

        ax = by and pos - x = neg - y
        only happens for common multiples
        find lcm = a*b/hcf(a, b) (hcf = gcd)

        correct but TLE's again

        when should i stop checking??
        wtf lmaooo changed the max to min and i got AC
        lucky ig

        tbh idk how i came up with half of this shi, half of it was intuition lmao

        */


        // bool ok = false;
        // for(ll i = 0; i <= min(a, b)*n; i += lcm){
        //     ll x = i/a;
        //     ll y = i/b;

        //     if((x <= pos && y <= neg && pos - x == neg - y) || (y <= pos && x <= neg && pos - y == neg - x)){
        //         ok = true;
        //         cout << "YES\n";
        //         break;
        //     }
        // }
        // if(!ok)
        //     cout << "NO\n";
        

        ll lcm = a*b/gcd(a, b);

        ll x = lcm/a, y = lcm/b;

        // can always decrease by a factor of abs(x - y)

        if(x - y == 0 || llabs(pos - neg)%llabs(x - y)){
            cout << "NO\n";
        }
        else{
            ll r = llabs(pos - neg)/llabs(x - y);
            if((x + y)*r > n){
                cout << "NO\n";
            }
            else
                cout << "YES\n";
        }
        
    }
}
int main(){
    ExPLICIT_27;
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }

    return 0;
}