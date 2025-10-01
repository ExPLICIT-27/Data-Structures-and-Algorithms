
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
            int n;
            cin >> n;
            int neg = 0, pos = 0;
            for(int i = 0;i < n; i++){
                int tmp;
                cin >> tmp;
                if(tmp == -1)
                    neg++;
                else
                    pos++;
            }
            if(pos - neg > 0){
                if(neg%2 == 0)
                    cout << 0 << endl;
                else
                    cout << 1 << endl;
            }
            else{
                int conv = (neg - pos + 1)/2;
                neg -= conv, pos += conv;
                if(neg%2)
                    conv++;
                cout << conv << endl;
            }
        }

        return 0;
    }
