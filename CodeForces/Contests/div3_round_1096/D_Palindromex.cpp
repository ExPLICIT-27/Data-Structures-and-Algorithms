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

    int N = 2*n;
    vector<int> A(N);

    for(int &i : A)
        cin >> i;

    /*
    every element is in the range (0, n - 1)
    every element in the range (0, n - 1) appears exactly twice
    i need to find a l,r such that mex is maximised

    A palindrome starting at L, should end at the other index of L

    so a palindrome in this scenario can be possible only if
    
    so i can find the L, R of every plausible palindrome starting at index i
    how do i quickly find the mex and verify the palindrome??

    can i running find mex/palindrome

    start by checking all values?

    check if theres a palindrome with mex = n
    entire array must be palindrome

    f f f f s s s s

    expand from centre? cause of the 2*n condition there will guaranteed be collisions

    how do i find mex while expanding?
    just brute force? using sets or sum
    */

    auto find = [&](int l, int r) -> int {

        set<int> s;
        while(l >= 0 && r < N){
            if(A[l] == A[r]){
                s.insert(A[l]);
                l--, r++;
            }
            else
                break;
        }

        int mex = 0;
        for(int i : s){
            if(i == mex)
                mex++;
        }

        return mex;
    };

    int ans = 0;
    for(int c = 0; c < N; c++){
        // even pal
        ans = max(ans, find(c, c));
        // odd pal

        if(c > 0)
            ans = max(ans, find(c - 1, c));
    }

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