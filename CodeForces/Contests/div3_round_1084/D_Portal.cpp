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
// binary exponentiation
ll binexp(ll a, ll b, ll M){
    ll ans = 1;

    while(b){
        if(b & 1)
            ans = (ans*a)%M;
        b >>= 1;
        a = (a * a)%M;
    }

    return ans;
}

void solve(){
    int n, x, y; cin >> n >> x >> y;

    /*
    for in between the portals
    circular shift from smallest 
    */
    vi A(n);
    for(int &i : A)
        cin >> i;
    vi middle;

    for(int i = x; i < y; i++){
        middle.pb(A[i]);
    }

    int mmin = vmin(middle);

    vi midans;

    int midx = 0;
    for(int i = 0; i < sz(middle); i++){
        if(middle[i] == mmin){
            for(int j = i; j < sz(middle) + i; j++)
                midans.pb(middle[j%sz(middle)]);
            break;
        }
    }

    int mbest = midans[0];
    int curr = 0;
    vi ans;
    while(curr < x && A[curr] < mbest){
        ans.pb(A[curr]);
        curr++;
    }
    if(curr == x){
        curr = y;
        while(curr < n && A[curr] < mbest)
            ans.pb(A[curr++]);
        for(int i : midans)
            ans.pb(i);

        for(int i = curr; i < n; i++)
            ans.pb(A[i]);
    }
    else{
        for(int i : midans)
            ans.pb(i);
        for(int i = curr; i < x; i++)
            ans.pb(A[i]);
        for(int i = y; i < n; i++)
            ans.pb(A[i]);
    }


    for(int i : ans)
        cout << i << " ";
    cout << nline;


}
int main(){
    ExPLICIT_27;
    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}