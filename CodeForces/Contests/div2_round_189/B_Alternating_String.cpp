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
    string S; cin >> S;
    int n = sz(S);
    /*
    we have S, consisting of only a's and b's
    I can take a substring and
        - flip reverse 
        - or just reverse

    the only two answers possible are
    ababab...
    or 
    bababa...


    abbba


    wait i am only allowed do the operation at most once

    abbaabba
    abababab

    can i just do a greedy operaiotn

    for case 1 -> find the first mismatch and the last mismatch
    then try it out 
    */

    auto canDo = [&](string &target, string curr) -> bool {
        int fi = -1, li = -1;
        
        for(int i = 0; i < n; i++){
            if(curr[i] != target[i]){
                if(fi == -1)
                    fi = i;
                li = i;
            }
        }

        if(fi == -1)
            return true;
        
        // reversing
        reverse(curr.begin() + fi, curr.begin() + li + 1);
        if(curr == target)
            return true;
        for(int i = fi; i <= li; i++){
            if(curr[i] == 'a')
                curr[i] = 'b';
            else
                curr[i] = 'a';
        }

        if(curr == target)
            return true;

        return false;
    };

    string c1, c2;

    for(int i = 0; i < n; i++){
        if(i & 1){
            c1 += 'a';
            c2 += 'b';
        }
        else{
            c1 += 'b';
            c2 += 'a';
        }
    }

    if(canDo(c1, S) || canDo(c2, S))
        cout << "YES\n";
    else    
        cout << "NO\n";
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