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

struct Node{
    int s, e, i;

    Node(){}
    Node(int a, int b, int c){
        s = a, e = b, i = c;
    }
};
struct Comparator{
    bool operator()(const pair<Node, int> &a, const pair<Node, int> &b){
        return a.ff.e > b.ff.e;
    }
};
void solve(){
    int n; cin >> n;

    vector<Node> A(n);

    for(int i = 0;i < n; i++){
        cin >> A[i].s >> A[i].e;
        A[i].i = i;
    }

    sort(all(A), [](Node &a, Node &b){
        return a.s < b.s;
    });

    vector<int> ans(n);

    int maxrooms = 1;
    priority_queue<pair<Node, int>, vector<pair<Node, int>>, Comparator> pq;
    pq.push({A[0], 1});
    ans[A[0].i] = 1;
    set<int> free;
    for(int i = 1; i < n; i++){
        while(!pq.empty() && pq.top().ff.e < A[i].s){
            free.insert(pq.top().ss);
            pq.pop();
        }
        if(free.empty()){
            maxrooms++;
            ans[A[i].i] = maxrooms;
            pq.push({A[i], maxrooms});
        }
        else{
            int room = *(free.begin());
            free.erase(room);
            pq.push({A[i], room});
            ans[A[i].i] = room;
        }
    }

    cout << maxrooms << nline;
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
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