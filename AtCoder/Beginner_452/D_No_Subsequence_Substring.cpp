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
    string S, T; cin >> S >> T;

    // I can do O(S*T)

    int m = sz(T);


    
   

    // ctn substrings with it, subtract from n*(n - 1)/2

    int n = sz(S);
    ll cnt = 0;

    map<char, set<int>> mp;

     auto chck = [&]() -> bool {
        int prev = -1;
        for(int j = 0; j < m; j++){
            char c = T[j] - 'a';
            if(!mp.count(c) || (mp[c].upper_bound(prev) == mp[c].end()))
                return false;
            prev = *(mp[c].upper_bound(prev));
        }

        return true;
    };
    int r = 0;
    for(int l = 0; l < n; l++){
        while(r < n){
            mp[S[r] - 'a'].insert(r);
            if(!chck()){
                cnt += (r - l + 1);
                r++;
            }
            else
                break;
        }

        mp[S[l] - 'a'].erase(l);

        if(mp[S[l] - 'a'].empty())
            mp.erase(S[l] - 'a');
    }

    cout << cnt << nline;


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