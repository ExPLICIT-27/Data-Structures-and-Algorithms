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
    all subarrays which have a peak element in them,  A[i - 1] < A[i] > A[i + 1], cannot be sorted

    total subarrays = n*(n + 1)/2
    cnt subarrays which have peaks, subtract from total
    how to efficiently cnt the subarrays which have peaks in them
    try brute force and see if it passes
    im getting WA and TLE
    so inconclusive as to whether this logic is correct or not 
    */

    int n; cin >> n;

    vi A(n);

    /*
    how do i prevent peak overcnts?

    3 elements form a peak, everything to the right


    note every peak

    ok tried all failed all, now the real soln involves only the following

    count all V shaped subarrays (dec then increasing, or simply increasing, or simply decreasing, DEC THEN INC IS NOT SORTABLE)


    if A[i] >= A[i - 1]
        then it can be considered to be part of the extendsion of the right half of V
        dp[i] = dp[i - 1] + 1
    else
        in this case A[i] < A[i - 1], it is in the strictly decreasing part
        we need to maintain a separate dec[i] array which cnts the size of decreasing array ending at this index
        and put dp[i] to dec[i]
    pre compute dec[i] using the case
    if A[i] <= A[i -1 ]
        dec[i] = 1 + dec[i - 1]
    else
        dec[i] = 1
    */

    for(int &i : A)
        cin >> i;
    vi dec(n), dp(n);

    dec[0] = 1;
    for(int i = 1; i < n; i++){
        if(A[i] <= A[i - 1])
            dec[i] = 1 + dec[i - 1];
        else    
            dec[i] = 1;
    }

    dp[0] = 1;
    for(int i = 1; i < n; i++){
        if(A[i] >= A[i - 1])
            dp[i] = 1 + dp[i - 1];
        else    
            dp[i] = dec[i];
    }

    cout << vsum(dp) << nline;

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