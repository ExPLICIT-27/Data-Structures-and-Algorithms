
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

// ---------- Fast IO ----------a
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

// ---------- Loops ----------
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define repd(i,a,b) for (int i = (a); i >= (b); i--)

// ---------- Constants ----------
const ll MOD = 1e9+7;
const ll INF = 1e18;

int main(){
    fastio;
    int T;
    cin >> T;
    while(T--){
        ll N, K;
        cin >> N >> K;

        vll A(N);
        
        rep(i, 0, N){
            cin >> A[i];
        }

        vll B(N);
        rep(i, 0, N){
            cin >> B[i];
        }
        ll maxscore = 0, currsum = 0, maxb = LLONG_MIN;
        rep(i, 1, min(N + 1, K + 1)){
            currsum += A[i - 1];
            maxb = max(maxb, B[i - 1]);
            maxscore = max(maxscore, currsum + maxb*(K - i));

        }
        cout << maxscore << endl;
    }
    return 0;
}
