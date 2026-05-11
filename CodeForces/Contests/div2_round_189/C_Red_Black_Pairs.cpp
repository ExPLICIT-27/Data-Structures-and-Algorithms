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
    my current strategy : 
    DP obv

    I choose to color either 1 or 2 at a time
    
    if i can color 1
        then make it 
        R
        R
        or 
        B
        B
    
    if i can color 2
    then make it 
    RR
    RR
    or 
    BB
    BB
    or 
    RR
    BB
    or 
    BB
    RR
    */
    vector<vector<char>> G(2, vector<char>(n));

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++)
            cin >> G[i][j];
    }

    ll dp[n];
    memset(dp, -1, sizeof(dp));
    function<ll(int)> chck;

    
    chck = [&](int i) -> ll {
        if(i >= n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];

        // try for 1
        // make R, R
        ll c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;
        if(G[0][i] != 'R')
            c1++;
        if(G[1][i] != 'R')
            c1++;
        
        if(G[0][i] != 'B')
            c2++;
        if(G[1][i] != 'B')
            c2++;

        ll one = chck(i + 1);
        c1 += one, c2 += one;

        
        if(i + 1 >= n)        
            return dp[i] = min(c1, c2);

        /*
        RR RR BB BB
        RR BB RR BB
        c3 c4 c5 c6
        */
        
        if(G[0][i] == 'R'){
            c5++;
            c6++;
        }
        else{
            c3++;
            c4++;
        }

        if(G[0][i + 1] == 'R'){
            c5++;
            c6++;
        }
        else{
            c3++;
            c4++;
        }

        // scnd riw
        if(G[1][i] == 'R'){
            c4++;
            c6++;
        }
        else{
            c3++;
            c5++;
        }

        if(G[1][i + 1] == 'R'){
            c4++;
            c6++;
        }
        else{
            c3++;
            c5++;
        }

        ll two = chck(i + 2);
        c3 += two;
        c4 += two;
        c5 += two;
        c6 += two;
        return dp[i] = min(c1, min(c2, min(c3, min(c4, min(c5, c6)))));
    };

    cout << chck(0) << nline;
};

int main(){
    ExPLICIT_27;
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}