
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

// ---------- Fast IO ----------
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

// ---------- Loops ----------
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define repd(i,a,b) for (int i = (a); i >= (b); i--)

// ---------- Constants ----------
const ll MOD = 1e9+7;
const ll INF = 1e18;

int main() {
    fastio;

    int T; 
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ll current_num = 10;
        if(n < 10){
            cout << n << endl;
            continue;
        }
        int result = 9;
        while(current_num*10 <= n){
            result += 9;
            current_num *= 10;
        }
        string str = to_string(n);
        result += str[0] - '0';
        cout << result << endl;
    }
    return 0;
}
