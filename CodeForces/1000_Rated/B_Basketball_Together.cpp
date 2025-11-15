
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
    fastio;

    ll n, d;
    cin >> n >> d;
    vll p(n);

    rep(i, 0, n){
        cin >> p[i];
    }

    sort(all(p));
    if(p[0] > d){
        cout << n << endl;
    }
    else{
        ll current = p.back();
        int cnt = 1;
        int wins = 0;
        int l = 0, r = n - 1;
        while(l < r){
            current = p[r];
            while(l < r && cnt*current <= d){
                cnt++;
                l++;
            }
            if(cnt*current > d)
                wins++;
            cnt = 1;
            r--;
        }
        cout << wins << endl;
    }

    return 0;
}