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
    int n, q; cin >> n >> q;


    vll A(n);

    for(ll &i : A)
        cin >> i;

    sort(all(A));

    if(sz(A) == 1){
        while(q--){
            ll x; cin >> x;

            cout << (A[0] + x) - A[0] << nline;
        }
        return;
    }
    vll diff(n - 1, 0);

    for(int i = 1; i < n; i++)
        diff[i - 1] = A[i] - A[i - 1] - 1;
    
    sort(all(diff));

    vll pr(n - 1, 0);
    pr[0] = diff[0];
    for(int i = 1; i < n - 1; i++)
        pr[i] = pr[i - 1] + diff[i];
    ll a = A[0], b = A.back();
    
    while(q--){
        // min value is min(A) + 1,
        // max value is max(A) + X
        /*
        10, 20, 30, 40, 50
        10, 10, 10, 10
        10, 20, 30, 40
        40 - 5*4 = 20
        11 to 55
        */
        ll x; cin >> x;
        ll curr = (b + x) - a;

        // discount duplicate cases
        if(x > diff.back()){
            cout << curr << nline;
            continue;
        }

        auto lb = lower_bound(all(diff), x);

        int idx = lb - diff.begin();
        ll sm = pr.back() - ((idx - 1 < 0)? 0 : pr[idx - 1]);
        // cout << "sm : " << sm << " ";
        // cout << "diff : " << (n - idx - 1)*(x - 1) << nline;
        cout << curr - (sm - 1ll*(n - idx - 1)*(x - 1)) << nline;

        /*
        1 6 8 8 
        -1, 1, 4
        2 7 9 9
        (2) (7) (9) (9)
        8
        

        8
        (2,3) (7, 8) (9, 10), (9, 10)

        4 elements, it provides 1
        gap - x - 1

        10
        4 elements, it provides 2

        */
        
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