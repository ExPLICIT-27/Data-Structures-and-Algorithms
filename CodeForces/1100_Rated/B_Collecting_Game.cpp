
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

        vector<pll> A(N);
        rep(i, 0, N){
            cin >> A[i].ff;
            A[i].ss = i;
        }
        sort(all(A));
        vll pre(N);
        rep(i, 0, N){
            pre[i] = A[i].ff;
            if(i)
                pre[i] += pre[i - 1];
        }
        
        set<int> st;
        rep(i, 0, N){
            if(A[i].ff > pre[max(0, i - 1)])
                st.insert(i);
        }

        vi ans(N);
        rep(i, 0, N){
            ans[A[i].ss] = i;
            auto it = st.lower_bound(i + 1);
            if(it != st.end()){
                ans[A[i].ss] += *it - i - 1;
            }
            else
                ans[A[i].ss] += N - i - 1;
        }
        for(int i : ans)
            cout << i << " ";
        cout << endl;

    }
    return 0;
}
