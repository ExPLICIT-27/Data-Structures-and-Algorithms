
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
        ll N;
        cin >> N;
        vll A(N);

        rep(i, 0, N){
            cin >> A[i];
        }

        vll P(N);
        P[0] = A[0];
        rep(i, 1, N){
            P[i] = P[i - 1] + A[i];
        }

        ll ans = 0;
        rep(k, 0, N/2){
            ll mini = LLONG_MAX, maxi = 0;
            ll prev = 0;
            if(N%(k + 1) != 0)
                continue;
            for(ll i = k; i < N; i += (k + 1)){
                mini = min(P[i] - prev, mini);
                maxi = max(P[i] - prev, maxi);
                prev = P[i];
            }
            ans = max(ans, llabs(maxi - mini));
        }

        cout << ans << endl;
    }
    return 0;
}