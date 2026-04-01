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
void solve(){
    int n, k; cin >> n >> k;

    string S; cin >> S;

    /*
    a necessary condn : 
    S[i] must be equal to S[i + k]
    this is because for the substring S[i..(i + k - 1)]
    and S[i + 1...(i + k)]
    they share k - 1 same characters, hence the what that remaining 1 character should be is fixed and must be same for both
    check this condn first, if its a qn mark, change it to the necessary value
    */

    for(int i = 0; i + k < n; i++){
        if(S[i] == '?')
            continue;
        if(S[i] == '0'){
            if(S[i + k] == '1'){
                cout << "NO\n";
                return;
            }
            else if(S[i + k] == '?')
                S[i + k] = '0';
        }
        else{
            if(S[i + k] == '0'){
                cout << "NO\n";
                return;
            }
            else if(S[i + k] == '?')
                S[i + k] = '1';
        }
    }

    /*
    now we can fix it only if the remaining difference between ones and zeros is <= no of qn marks for each substr of size k

    note : we can stop just after checking the first k sized substr since the condition S[i] = S[i + k] guarantees the same
    for the others
    
    */

    int o = 0, q = 0, z = 0;

    for(int i = 0; i < k; i++){
        char c = S[i];

        if(c == '1')
            o++;
        else if(c == '0')
            z++;
        else
            q++;
    }

    if(q < abs(o - z)){
        cout << "NO\n";
        return;
    }
    

    for(int i = k; i < n; i++){
        char c = S[i];

        if(c == '1')
            o++;
        else if(c == '0')
            z++;
        else
            q++;

        c = S[i - k];
        if(c == '1')
            o--;
        else if(c == '0')
            z--;
        else
            q--;

        if(q < abs(o - z)){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

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