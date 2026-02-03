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
bool isValid(int x, int y, int n){
    return x >= 0 && x < n && y >= 0 && y < n;
}
void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> A(n);
    for(int i = 0; i < n; i++)
        cin >> A[i];
    if(A[0][0] == 'A')
        A[0][0] = 'B';
    else if(A[0][0] == 'B')
        A[0][0] = 'C';
    else if(A[0][0] == 'C')
        A[0][0] = 'D';
    else
        A[0][0] = 'A';
    for(int i = 1; i < n; i++){
        if(A[i][0] == 'A'){
            if(A[i - 1][0] == 'B')
                A[i][0] = 'C';
            else if(A[i - 1][0] == 'A')
                A[i][0] = 'B';
            else if(A[i - 1][0] == 'C')
                A[i][0] = 'D';
            else{
                A[i][0] = 'B';
            }
        }
        else if(A[i][0] == 'B'){
            if(A[i - 1][0] == 'B')
                A[i][0] = 'A';
            else if(A[i - 1][0] == 'A')
                A[i][0] = 'C';
            else if(A[i - 1][0] == 'C')
                A[i][0] = 'D';
            else{
                A[i][0] = 'C';
            }
        }
        else if(A[i][0] == 'C'){
            if(A[i - 1][0] == 'B')
                A[i][0] = 'A';
            else if(A[i - 1][0] == 'A')
                A[i][0] = 'B';
            else if(A[i - 1][0] == 'C')
                A[i][0] = 'D';
            else{
                A[i][0] = 'B';
            }
        }
        else{
            if(A[i - 1][0] == 'B')
                A[i][0] = 'C';
            else if(A[i - 1][0] == 'A')
                A[i][0] = 'B';
            else if(A[i - 1][0] == 'C')
                A[i][0] = 'A';
            else{
                A[i][0] = 'B';
            }
        }
    }

    for(int j = 1; j < m; j++){
        if(A[0][j] == 'A'){
            if(A[0][j - 1] == 'B')
                A[0][j] = 'C';
            else if(A[0][j - 1] == 'A')
                A[0][j] = 'B';
            else if(A[0][j - 1] == 'C')
                A[0][j] = 'D';
            else{
                A[0][j] = 'B';
            }
        }
        else if(A[0][j] == 'B'){
            if(A[0][j - 1] == 'B')
                A[0][j] = 'A';
            else if(A[0][j - 1] == 'A')
                A[0][j] = 'C';
            else if(A[0][j - 1] == 'C')
                A[0][j] = 'D';
            else{
                A[0][j] = 'C';
            }
        }
        else if(A[0][j] == 'C'){
            if(A[0][j - 1] == 'B')
                A[0][j] = 'A';
            else if(A[0][j - 1] == 'A')
                A[0][j] = 'B';
            else if(A[0][j - 1] == 'C')
                A[0][j] = 'D';
            else{
                A[0][j] = 'B';
            }
        }
        else{
            if(A[0][j - 1] == 'B')
                A[0][j] = 'C';
            else if(A[0][j - 1] == 'A')
                A[0][j] = 'B';
            else if(A[0][j - 1] == 'C')
                A[0][j] = 'A';
            else{
                A[0][j] = 'B';
            }
        }
    }


    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            char curr = A[i][j];
            char top = A[i - 1][j];
            char prev = A[i][j - 1];
            if('A' != curr && 'A' != top && 'A' != prev)
                A[i][j] = 'A';
            else if('B' != curr && 'B' != top && 'B' != prev)
                A[i][j] = 'B';
            else if('C' != curr && 'C' != top && 'C' != prev){
                A[i][j] = 'C';
            }
            else
                A[i][j] = 'D';
        }
    }

    for(string &s : A)
        cout << s << nline;
    cout << nline;
}
int main(){
    fastio;
    solve();
    // int T;
    // cin >> T;
    // while(T--){
    //     solve();
    // }

    // return 0;
}