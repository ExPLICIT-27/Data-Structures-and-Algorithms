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
    n rows of bones
    length of each rib is n

    for row i
    s[B[i]] = i
    */
    int n; cin >> n;

    vi A(n), B(n);

    for(int i = 0; i < n; i++){
        cin >> A[i] >> B[i];
        B[i]--;
    }


    int m; cin >> m;


    vector<string> S(m);

    for(int i = 0; i < m; i++)
        cin >> S[i];
    
    
    vector<vector<set<int>>> mp(11, vector<set<int>>(11, set<int>()));

    for(auto &s : S){
        
        int k = sz(s);

        for(int i = 0; i < k; i++){
            mp[k][i].insert(s[i]);
        }
    }
    for(int i = 0; i < m; i++){
        // is there a path 
        /*retro => */
        // 
        bool ok = true;
        if(S[i].size() != n){
            cout << "No\n";
            continue;
        }
        for(int j = 0; j < n; j++){
            if(mp[A[j]].empty() || mp[A[j]][B[j]].empty() || !mp[A[j]][B[j]].count(S[i][j])){
                ok = false;
                break;
            }
        }

        if(ok)
            cout << "Yes\n";
        else
            cout << "No\n";
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