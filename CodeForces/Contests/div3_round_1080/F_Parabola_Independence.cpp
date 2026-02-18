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
/*

oke conditions for parabola intersection

two paras of the form f(x) = a1x^2 + b1x + c1 and g(x) = a2x^2 + b2x + c2 intersect iff
f(x) - g(x) = 0 has a real solution, hence just check the if discriminant is equal to 0
also handle the case where the coefficient of x^2 in f(x) - g(x) = 0, in that case
itll be a line of the form bx + c = 0, and since they gave all curves are distinct, it always has a 
unique solution of -c/b, so if coefficient of x^2 is 0, then coefficient of x must also be 0 for it to be non intersecting


Now the core idea

if two funcs are independent, f(x) - g(x) is never 0,
i.e either f(x) > g(x) or f(x) < g(x) for all x

how to see if f(x) > g(x)? just compare their coefficients in the order
a, b, c

now if we sort the functions based on this ordering, we impose impose a consistent global order on the parabolas so that any organized subset becomes an increasing subsequence in that order.

so every valid subset that we find will be such that [f1, f2, f3 ... fn], either f1 < f2 < f3 ... < fn
or f1 > f2 > f3 .... fn

hence to find the length of the longest chain each function is a part of, just count how many are before it and how many are after
it 
*/
struct FN{
    ll a, b, c, i;
    FN(){};
    FN(ll a, ll b, ll c, ll i) : a(a), b(b), c(c), i(i) {};
};
bool isInd(FN &x, FN &y){
    if(x.a == y.a)
        return x.b == y.b;

    ll b = x.b - y.b, a = x.a - y.a, c = x.c - y.c;

    return b*b - 4*a*c < 0;
}
void solve(){
    int n; cin >> n;

    vector<FN> F(n);

    for(int i = 0; i < n; i++){
        cin >> F[i].a >> F[i].b >> F[i].c;
        F[i].i = i;
    }
    
    // sort based on a, b, c
    sort(all(F), [](FN &x, FN &y){
        if(x.a != y.a)
            return x.a < y.a;
        if(x.b != y.b)
            return x.b < y.b;
        
        return x.c < y.c;
    });

    vi before(n, 1); // count hw many b4, including itself

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(isInd(F[i], F[j]))
                before[i] = max(before[i], 1 + before[j]);
        }
    }

    vi after(n, 1); // cnt after
    for(int i = n - 1; i >= 0; i--){
        for(int j = n - 1; j > i; j--){
            if(isInd(F[i], F[j]))
                after[i] = max(after[i], 1 + after[j]);
        }
    }

    vi ans(n);

    // before + after - 1 is the ans for each
    for(int i = 0; i < n; i++){
        ans[F[i].i] = before[i] + after[i] - 1;
    }

    for(int i : ans)
        cout << i << " ";
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