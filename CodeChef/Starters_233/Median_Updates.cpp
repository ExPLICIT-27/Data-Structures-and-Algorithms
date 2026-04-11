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

    string S; cin >> S;

    auto getNei = [&](int i, string &S) -> pii {
        if(i == 0)
            return {S[n - 1], S[1]};
        if(i == n - 1)
            return {S[n - 2], S[0]};
        
        return {S[i - 1], S[i + 1]};
    };

    /*
    impossible when there is not even a single set of consecutive ones or zeros (cyclically as well)
    otherwise its always possible

    consec set of ones/zeros im calling them free
    */

    bool ok = false;

    for(int i = 1; i < n; i++){
        if(S[i] == S[i - 1])
            ok = true;
    }

    if(S[0] == S[n - 1])
        ok = true;

    if(!ok){
        cout << -1 << nline;
        return;
    }

    /*
    a zero or one is 'stuck' if it is of the form
    010 - 1 is stuck
    101 - 0 is stuck

    found the logic : 
    between any 2 blocks of free zeros and ones
    the maximum no of stuck 1's/0's is the ans

    basically the formula boils down to
    max(ceil((no of consecutive alternating elements)/2))
    gotta do it over the concatenation of the 2 strings to account for the circular nature
    */

    string _S = S + S;

    int curr = 0, ans = 0;

    for(int i = 1; i < 2*n; i++){
        if(_S[i] != _S[i - 1])
            curr++;
        else
            curr = 0;
        ans = max(ans, curr/2);
    }

    cout << ans + 1 << nline;

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