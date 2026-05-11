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

    vi A(n);

    for(int &i : A)
        cin >> i;
    
    /*
    gravity shift always sorts elements
    i.e the number of changes can be calced as the current height - what is supposed to be there
    doing this takes O(n) time -> can be done using horizontal gap analysis and prefix sums
    

    if i decrease the value of any element by 1, how does its position change?
    
    i think if i find how to 

    how about first finding what the total position change is without removeal
    */


    ll og = 0;

    int cmin = INT_MAX;
    vi smin(n);
    for(int i = n - 1; i >= 0; i--){
        cmin = min(cmin, A[i]);
        smin[i] = cmin;
        og += (A[i] - cmin);
    }

    /*
    it is only beneficiary if i change a suffix minimum to somehting - 1
    */

    ll ans = og;
    for(int i = n - 1; i >= 0; i--){
        if(smin[i] == A[i]){
            // if i change what will be the 
            auto it = lower_bound(all(smin), A[i]);

            
            
            ans = max(ans, og + (i - (it - smin.begin())));

            
        }
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