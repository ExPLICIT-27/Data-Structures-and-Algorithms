
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
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        vi freq(26, 0);
        for(char c : str)
            freq[c - 'a']++;//t - 4, r - 4, a - 2, k - 2, o - 2
        int oddc = 0;
        int evenc = 0;
        for(int i : freq){
            if(i%2)
                oddc++;
            else
                evenc += i;
        }
        if(oddc - 1 > k)
            cout << "NO" << endl;
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}