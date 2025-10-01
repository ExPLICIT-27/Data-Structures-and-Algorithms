
    #include <bits/stdc++.h>
    using namespace std;

    // ---------- Typedefs ----------
    #define ll long long
    #define ull unsigned long long
    #define ld long double
    #define pii pair<int,int>
    #define pll pair<ll,ll>
    #define vi vector<int>
    #define vc vector<char>
    #define vll vector<ll>
    #define usi unordered_set<int>
    #define si set<int>

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
            int x, k;
            cin >> x >> k;
            if(x%k){
                cout << 1 << endl;
                cout << x << endl;
            }
            else{
                cout << 2 << endl;
                cout << x - 1 <<  " " << 1 << endl;
            }
        }

        return 0;
    }
