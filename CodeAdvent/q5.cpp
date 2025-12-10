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
    
    ifstream file("input_5.txt");
    if (!file.is_open()) return 1;

    string line;

    vector<pll> ranges;
    vll Q;
    bool q = false;
    while(getline(file, line)){
        if(line.empty()){
            q = true;
            continue;
        }
        if(q)
            Q.pb(stoll(line));
        else{
            int pos = line.find('-');
            ll st = stoll(line.substr(0, pos));
            ll en = stoll(line.substr(pos + 1));
            ranges.pb({st, en});
        }
    }

    // merge the ranges
    sort(all(ranges));
    vector<pll> F;// final range 
    F.pb(ranges[0]);
    int n = sz(ranges);
    rep(i, 1, n){
        if(ranges[i].ff <= F.back().ss){
            F.back().ss = max(F.back().ss, ranges[i].ss);
        }
        else{
            F.pb(ranges[i]);
        }
    }
    sort(all(F), [](const pll &A, const pll &B){
        if(A.ss != B.ss)
            return A.ss < B.ss;
        return A.ff < B.ff;
    });
    // for(auto &p : F)
    //     cout << p.ff << " " << p.ss << endl;
    ll ans = 0;
    for(ll a : Q){
        auto it = lower_bound(all(F), make_pair(LLONG_MIN, a), [](const pll &A, const pll &B){
            if(A.ss != B.ss)
                return A.ss < B.ss;
            return A.ff < B.ff;
        });
        if(it != F.end()){
            if(a >= it->first && a <= it->second)
                ans++;
        }
    }
    ans = 0;
    for(auto &p : F){
        ans += (p.ss - p.ff + 1);
    }
    cout << ans << endl;
    
    return 0;
}