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
    int n, m; cin >> n >> m;

    vi A(n);

    for(int &i : A)
        cin >> i;
    ll total = vsum(A);

    if(total < m){
        cout << 0 << nline;
        return;
    }
    /*
    can i do this with a PQ
    */
    
    sort(all(A), greater<int>());
    // if N > M, i wil not use N - M types which offer the least amt of salvage days

    priority_queue<int, vi> pq;

    int ans = A[0];
    pq.push(A[0]);
    int assigned = 1;

    int i = 1;
    while(assigned < m){
        int curr = A[i];
        int best = pq.top();
        pq.pop();
        if(best/2 >= curr){
            pq.push(best/2);
            pq.push(best - best/2);

            ans = min(ans, best/2);
        }
        else{
            ans = min(ans, curr);
            pq.push(best);
            pq.push(curr);
            i++;
        }
        assigned++;
    }

    cout << ans << nline;
    
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