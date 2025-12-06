
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
        int n;
        cin >> n;

        vll A(n), B(n);

        rep(i, 0, n){
            cin >> A[i];
        }
        rep(i, 0, n){
            cin >> B[i];
        }

        // find the longest sorted subarray
        int f = -1, l = -1;
        rep(i, 0, n){
            if(A[i] != B[i]){
                if(f == -1)
                    f = i;
                else{
                    l = i;
                    break;
                }
            }
        }
        int i = f - 1;
        while(i >= 0){
            if(B[i] <= B[i + 1])
                i--;
            else
                break;
        }
        f = i + 1;

        if(l == -1)
            l = n;
        int j = l + 1;
        while(j < n){
            if(B[j - 1] <= B[j])
                j++;
            else
                break;
        }
        l = j - 1;

        cout << f  + 1 << " " << l + 1 << endl;

    }
    return 0;
}