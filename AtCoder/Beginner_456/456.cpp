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

// ---------- PBDS ----------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using ordered_multiset = tree<pair<T,int>, null_type, less<pair<T,int>>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename K, typename V>
using ordered_map = tree<pair<K,V>, null_type, less<pair<K,V>>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    /*
    4,5,6
    4,6,5
    5,4,6,
    */

    vi face = {4, 5, 6};

    vi f(6), s(6), t(6);

    for(int i = 0; i < 6; i++)
        cin >> f[i];
    for(int i = 0; i < 6; i++)
        cin >> s[i];
    for(int i = 0; i < 6; i++)
        cin >> t[i];  
    
    
    auto calcP = [](vi &a, int t) -> double {
        double p = 0;

        for(int i : a)
            if(i == t)
                p++;
        
        return p/6.0;
    };

    double ans = 0;
    do{
        ans += (calcP(f, face[0])*calcP(s, face[1])*calcP(t, face[2]));

    }while(next_permutation(all(face)));

    printf("%.10f\n", ans);
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