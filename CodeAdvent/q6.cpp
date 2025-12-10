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
#include <fstream>

int main(){
    
    ifstream file("input_6.txt");
    if (!file.is_open()) return 1;

    string line;

    vector<pll> ranges;
    vll Q;
    bool q = false;
    vector<string> A;
    while(getline(file, line)){
        if(!line.empty()){
            A.pb(line);
        }
    }
    int N = sz(A);
    vector<vll> B(N - 1);

    rep(i, 0, N - 1){
        stringstream ss(A[i]);
        ll tmp;
        while(ss >> tmp){
            B[i].pb(tmp);
        }
    }

    // for(auto &v : B){
    //     for(ll i : v)
    //         cout << i << " ";
    //     cout << endl;
    // }
    vector<char> ops;
    stringstream ss(A.back());
    char tmp;
    while(ss >> tmp){
        ops.pb(tmp);
    }
    int M = sz(B[0]);

    ll ans = 0;
    rep(j, 0, M){
        ll curr = B[0][j];
        rep(i, 1, sz(B)){
            if(ops[j] == '+')
                curr += B[i][j];
            else
                curr *= B[i][j];
        }
        ans += curr;
    }
    cout << ans << endl;
    
    return 0;
}