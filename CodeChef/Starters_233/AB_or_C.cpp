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
    int n; cin >> n;

    
    /*
    the smallest difference is in the window of n elements
    hence we need to calc answer over all n window elements
    */
    
    int N = 3*n;
    vector<pii> A;

    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        A.emplace_back(a, i);
        A.emplace_back(b, i);
        A.emplace_back(c, i);
    }

    sort(all(A), [](pii &a, pii &b){
        return a.ff < b.ff;
    });


    map<int, int> mp;

    int r = 0;

    int ans = INT_MAX;
    for(int l = 0; l < N; l++){
        while(r < N && sz(mp) < n){
            mp[A[r].ss]++;
            r++;
        }
        
        if(sz(mp) == n)
            ans = min(ans, A[r - 1].ff - A[l].ff);
        
        mp[A[l].ss]--;

        if(mp[A[l].ss] == 0)
            mp.erase(A[l].ss);
    }

    cout << ans << nline;

    
    
}

int main(){
    ExPLICIT_27;
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}