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
    0 0 0 0 1
    5 different unique ones

    dividing numbers in the range (1, N) into 2 groups
    how can i maximize the no of distinct combination sums taking 1 pair each from each group
    1 2 3 4 5 6
    (1, 2) (2, 3) (3, 4) (4, 5) (5, 6)
    (1, 3) (2, 4) (3, 5) (4, 6)
    (1, 4) (2, 5) (3, 6)
    (1, 5) (2, 6)
    (2, 6)
    */
    int n; cin >> n;

    // try brute force for 5, 6 see if theres any pattern
    // vi a1, a2;
    // int cmax = 0;
    // for(int i = 0; i < (1 << n); i++){
    //     vector<int> t1, t2;
    //     for(int j = 0; j < n; j++){
    //         if((i >> j) & 1)
    //             t1.pb(j + 1);
    //         else
    //             t2.pb(j + 1);
    //     }

    //     uset<int> s;

    //     for(int i : t1){
    //         for(int j : t2){
    //             s.insert(i + j);
    //         }
    //     }

    //     if(sz(s) > cmax){
    //         cmax = sz(s);
    //         a1 = t1, a2 = t2;
    //     }
    // }
    

    // cout << "arr 1 : ";
    // for(int i : a1)
    //     cout << i << " ";
    // cout << nline;
    // cout << "arr2 : ";
    // for(int i : a2)
    //     cout << i << " ";
    // cout << nline;

    if(n == 2){
        cout << "01\n";
        return;
    }

    string ans = "";
    ans += '1';

    for(int i = 1; i < n - 1; i++)
        ans += '0';
    
    ans += '1';


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