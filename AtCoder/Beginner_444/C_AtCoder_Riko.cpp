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
    int n; cin >> n;

    vll A(n);

    for(ll &i : A)
        cin >> i;
    
    sort(all(A));
    if(n & 1){
        cout << A[n - 1] << nline;
    }
    else{
        // max two sols
        // can i make everything equal to the last?, or 

        map<ll, int> mp;
        for(ll &i : A)
            mp[i]++;
        if(A[0] == A[n - 1]){
            if(n & 1)
                cout << A[0] << nline;
            else
                cout << A[0] << " " << A[0]*2 << nline;
            return;
        }
        // equal to last?
        bool canLast = true;
        for(int i = 0; i < n; i++){
            if(!mp[A[i]] || A[i] == A[n - 1])
                continue;
            if(mp.count(A[n - 1] - A[i]) && mp[A[n - 1] - A[i]] > 0){
                mp[(A[n - 1] - A[i])]--;
                mp[A[i]]--;
            }
            else{
                canLast = false;
                break;
            }
        }
        if(A[0] == A[n - 1])
            canLast = true;
        if(!canLast){
            cout << A[n - 1] + A[0] << nline;
            return;
        } 
        cout << A[n - 1] << " ";
    
        bool fiLa = true;

        mp.clear();

        for(ll &i : A)
            mp[i]++;
        ll target = A[n - 1] + A[0];
        for(int i = 0; i < n; i++){
            if(!mp[A[i]])
                continue;
            if(mp.count(target - A[i]) && mp[target - A[i]] > 0){
                mp[target - A[i]]--;
                mp[A[i]]--;
            }
            else{
                fiLa = false;
                break;
            }
        }

        if(fiLa)
            cout << target << nline;
        else
            cout << nline;

    }
}
int main(){
    fastio;
    solve();
    // int T;
    // cin >> T;
    // while(T--){
    //     solve();
    // }

    return 0;
}