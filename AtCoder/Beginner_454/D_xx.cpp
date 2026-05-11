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
    string A, B; cin >> A >> B;

    /*
    can i make A = B
    i can replace (xx) with xx
    or vice versa

    (xx) is suppose X and xx is suppose Y
    i can turn X into Y and Y into X
    X = (Y)
    can then represent the entire string in terms of Y
    (Y)x
    x(Y)


    given xx
    i can make how many ever brackets i want
    given xx, i can destroy all brackets from left and right

    after destroyin all brackets that i can destroy, check?


    optimally destroying brackets
    just do
    */


    auto prune = [&](string &S) -> string {
        int n = sz(S);

        int i = 0;  

        vector<bool> vis(n, true);

        while(i < n){
            if(i > 0 && S[i] == 'x' && S[i - 1] == 'x'){
                int l = i - 2, r = i + 1;

                while(l >= 0 && r < n && S[l] == '(' && S[r] == ')'){
                    vis[l] = vis[r] = false;
                    l--, r++;
                }

                i = r;
            }
            else
                i++;
        }

        string res = "";

        for(int i = 0; i < n; i++){
            if(vis[i])
                res += S[i];
        }

        return res;
    };

    string a1 = prune(A), b1 = prune(B);

    if(a1 == b1)
        cout << "Yes\n";
    else
        cout << "No\n";

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