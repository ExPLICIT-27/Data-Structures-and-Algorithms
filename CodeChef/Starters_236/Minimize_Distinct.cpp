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

    vi A(n);

    for(int &i : A)
        cin >> i;
    
    /*
    need to solve for all (i, R)

    for elements in range(i, R)
    i should do A[i] + 1
    for elements not in range (i, R)
    i should do A[i] - 1

    for all elements in range(0, R - 2)
    their distinct counts remain the same

    for all elements 

    for the elements = R
    it becomes R + 1, and the element = R + 2 also becomes R + 1

    for element R - 1, it becomes R, while R + 1 also becomes R

    so for any (R) the value is
    distinct elements in range(0, R - 2)

    +1 (if there exists either R - 1 or R + 1)
    +1 (if there exists either R or R + 2)

    then distinct elements in range(R + 3, N)

    */

    vector<int> isP(n + 1, false), pr(n + 1, false), br(n + 1, false);

    for(int i : A){
        isP[i] = true;
        pr[i] = true;
        br[i] = true;
    }
    
    for(int i = 1; i <= n; i++)
        pr[i] += pr[i - 1];
    
    for(int i = n - 1; i >= 0; i--)
        br[i] += br[i + 1];
    
    vector<int> R(n + 1);


    vector<int> RO(n + 1);
    for(int i = 1; i <= n; i++){
        int left = ((i - 2 >= 0)? pr[i - 2] : 0);
        
        int r = 0, r1 = 0;

        if(isP[i - 1] || ((i + 1 <= n) && isP[i + 1])) // this i can only do for r - l + 1 >= 2
            r = 1;
        
        if(isP[i] || ((i + 2 <= n) && isP[i + 2]))
            r1 = 1;
        
        int right = ((i + 3 > n)? 0 : br[i + 3]);

        R[i] = (left + right + r + r1);
        
        left = pr[i - 1], right = ((i + 2 <= n)? br[i + 2] : 0);

        RO[i] = (left + right + r1);
    }

    // for(int i : R)
    //     cout << i << " ";
    // cout << nline;
    
    vector<int> smin(n + 1);
    for(int i = n; i >= 0; i--){
        smin[i] = R[i];
        if(i + 1 <= n)
            smin[i] = min(smin[i], smin[i + 1]);
    }

    for(int i = 1; i < n; i++){
        // int cans = RO[i];
        // if(i + 1 <= n)
        //     cans = min(cans, smin[i + 1]);

        // cout << cans << " ";
        // smin[i + 1] because when L = R, no of distinct values do not change, they remain the same
        cout << smin[i + 1] << " ";
    }
    cout << smin.back();
    cout << nline;
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