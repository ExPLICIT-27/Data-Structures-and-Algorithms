
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

int main(){
    int T;
    cin >> T;
    while(T--){
        int a, b, xk, yk, xq, yq;
        cin >> a >> b >> xk >> yk >> xq >> yq;
        set<pii> check;
        for(int i : {a, -a}){
            for(int j : {b, -b}){
                int x = xk + i;
                int y = yk + j;
                check.insert({x, y});
                x = xk + j;
                y = yk + i;
                check.insert({x, y});
            }
        }
        int result = 0;
        for(int i : {a, -a}){
            for(int j : {b, -b}){
                int x = xq + i;
                int y = yq + j;
                if(check.count({x, y})){
                    result++;
                    check.erase({x, y});
                }
                x = xq + j;
                y = yq + i;
                if(check.count({x, y})){
                    result++;
                    check.erase({x, y});
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}