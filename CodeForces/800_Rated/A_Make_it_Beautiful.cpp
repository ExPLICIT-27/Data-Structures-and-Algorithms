
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

    int gcd(int a, int b){
        return (a == 0)? b : gcd(b%a, a);
    }
    int main() {
        fastio;

        int T; 
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            vi a(n);
            umap <int, int> mp;
            rep(i, 0, n){
                cin >> a[i];
            }
            sort(all(a));
            vi res(n);
            int l = 0, r = n - 1, i = 0;
            while(l < r){
                res[i++] = a[l++];
                res[i++] = a[r--];
            }
            if(l == r)
                res[i++] = a[l++];
            ll sm = res[0];
            bool ok = true;
            for(int i = 1; i < n; i++){
                if(sm == res[i]){
                    ok = false;
                    break;
                }
                sm += res[i];
            }
            if(ok){
                cout << "YES" << endl;
                for(int i : res)
                    cout << i << " ";
                cout << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        return 0;
    }
