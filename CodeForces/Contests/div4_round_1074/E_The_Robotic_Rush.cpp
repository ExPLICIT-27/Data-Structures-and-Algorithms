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

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vll A(n);

    for(ll & i : A)
        cin >> i;

    vll B(m);

    for(ll & i : B)
        cin >> i;
    
    string S;
    cin >> S;

    sort(all(B));
    map<ll, set<ll>> mp;
    map<ll, ll> L, R;
    for(int j = 0; j < n; j++){
        ll i = A[j];
        // left 
        auto it1 = lower_bound(all(B), i);
        if(it1 != B.begin()){
            it1--;
            mp[*it1 - i].insert(j);
            L[j] = *it1 - i;
        }
        auto it2 = upper_bound(all(B), i);
        // right
        if(it2 != B.end()){
            mp[*it2 - i].insert(j);
            R[j] = *it2 - i;
        }
    }

    ll curr = 0, cans = n;
    // for(auto &[x, y] : mp)
    //     cout << x << " " << y << nline;
    for(char c : S){
        if(c == 'L')
            curr--;
        else
            curr++;
        if(mp.count(curr)){
            cans -= sz(mp[curr]);
            if(curr < 0){
                // delete rights
                for(ll i : mp[curr]){
                    if(mp.count(R[i])){
                        mp[R[i]].erase(i);
                    }
                }
            }
            else{
                for(ll i : mp[curr]){
                    if(mp.count(L[i])){
                        mp[L[i]].erase(i);
                    }
                }
            }
            mp.erase(curr);
        }

        cout << cans << " ";
    }

    cout << nline;
    

}
int main(){
    fastio;
    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}