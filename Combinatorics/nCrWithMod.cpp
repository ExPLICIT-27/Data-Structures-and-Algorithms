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