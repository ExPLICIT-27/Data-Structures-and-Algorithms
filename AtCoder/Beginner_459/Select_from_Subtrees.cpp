#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'


// n and r ill do till 1e6
#include <bits/stdc++.h>

#define ll long long
using namespace std;


class Combinatorics{
    private:
        ll mod;
        vector<ll> fact, inv_fact;

        ll binpow(ll base, ll exp){
            ll res = 1;

            while(exp){
                if(exp & 1)
                    res = res*base%mod;

                base = base*base%mod;
                exp >>= 1;
            }

            return res;
        }
        
        ll modInv(ll n){
            return binpow(n, mod - 2);
        }

    public:
        Combinatorics(int MAX_N, ll mod) {
            this->mod = mod;

            fact.resize(MAX_N + 1);
            inv_fact.resize(MAX_N + 1);

            fact[0] = 1;
            inv_fact[0] = 1;

            for(int i = 1; i <= MAX_N; i++)
                fact[i] = (fact[i - 1]*i)%mod;


            /*
            1/i! = (i + 1)/(i + 1)!
            so just compute 1/i! for i = MAX_N, and use the forward values
            */
            inv_fact[MAX_N] = modInv(fact[MAX_N]);


            for(int i = MAX_N - 1; i > 0; i--){
                inv_fact[i] = (inv_fact[i + 1]*(i + 1))%mod;
            }
        
        }


        ll nCr(int n, int r){
            if(n < 0 || r < 0 || r > n)
                return 0;
            
            /*
            n!/(n - r)!*r!
            */

            ll num = fact[n];

            ll den = (inv_fact[n - r]*inv_fact[r])%mod;

            return (num*den)%mod;
        }


        ll nCr_large(ll n, int r){
            if(n < 0 || r < 0 || r > n)
                return 0;
            
            /*
            n!/(n - r)!r!
            = (n*(n - 1)*(n - 2)...(n - r + 1))*(n - r)!/(n - r)!r!

            = n*(n - 1)...(n - r + 1)/r!
            */

            ll num = 1;

            for(int i = 0; i < r; i++)
                num = (num*((n - i)%mod))%mod;
            
            ll den = inv_fact[r];
        

            return (num*den)%mod;
        }
};

void solve() {
    int n; cin >> n;
    
    vector<int> C(n), D(n);

    vector<vector<int>> G(n);

    for(int i = 1; i < n; i++){
        int p; cin >> p;
        p--;
        G[p].push_back(i);
        G[i].push_back(p);
    }

    for(int &i : C)
        cin >> i;
    
    for(int &i : D)
        cin >> i;
    
    int maxN = 1e6 + 1, mod = 998244353;
    /*
    start from the leaves, dfs your way up
    find subtree sums
    find subtree choices
    need to build nCr table
    */

    Combinatorics comb = Combinatorics(int(1e6 + 1), mod);


    vector<ll> subsums(n, 0), subreq(n, 0);
    vector<bool> vis(n, false);

    function<ll(int, vector<ll>&, vector<int>&)> dfs1;


    dfs1 = [&](int u, vector<ll> &sumarr, vector<int> &inp) -> ll {
        vis[u] = true;

        ll sum = 0;
        for(int v : G[u]){
            if(!vis[v])
                sum += dfs1(v, sumarr, inp);
        }

        return sumarr[u] = sum + inp[u];
    };

    dfs1(0, subsums, C);
    fill(vis.begin(), vis.end(), false);
    dfs1(0, subreq, D);


    
    function<ll(int)> F;


    fill(vis.begin(), vis.end(), 0);
    F = [&](int u) -> ll {
        vis[u] = true;


        ll curr = 1;
        for(int v : G[u]){
            if(!vis[v])
                curr = (curr*F(v))%mod;
        }

        curr = (curr*comb.nCr_large(subsums[u] - subreq[u] + D[u], D[u])%mod);

        return curr%mod;
    };

    cout << F(0) << nline;

}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}