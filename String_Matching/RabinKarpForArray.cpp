/*
this is rabin karp code for an array of integers in the range 0, 1e5


Basic rabin karp analogy
If you have the number 432, and you want to slide the window right to get 321, you don't re-calculate from scratch. 
You do three things:
Subtract the old digit: Remove the 4 from the hundreds place (432 - 400 = 32).
Shift left: Multiply by the base 10 to move everything over (32*10 = 320).
Add the new digit: Add 1 (320 + 1 = 321).
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

// to drastically decrease the possiblility of hash collisions,
// its best if we use 2 hashes for it


// assuming elements of the array are in the range 1, 1e5
pair<vector<ll>, vector<ll>> RabinKarp(vector<int> &arr, int len){

    int n = arr.size();
    const ll mod1 = 1e9 + 7, mod2 = 1e9 + 9; // 2 mods for the 2 hashes

    ll p1 = 1e6 + 3, p2 = 1e6 + 159; // 2 primes
    ll rh1 = 0, rh2 = 0; // rolling hash values
    
    // rolling hash form => (a[0]*p^len-1 + a[1]*p^len - 2.... + a[len])%m
    // roll -> (((current_hash - a[i - len]*(p^(m - 1))*p)%m + a[i])%m + m)%m

    ll h1 = 1, h2 = 1; // precompute p^(m - 1)

    for(int i = 0; i < len - 1; i++){
        h1 = (__int128)h1*p1%mod1;
        h2 = (__int128)h2*p2%mod2;
    }

    // compute hash for first window

    for(int i = 0; i < len; i++){
        rh1 = ((__int128)rh1*p1%mod1 + arr[i])%mod1;
        rh2 = ((__int128)rh2*p2%mod2 + arr[i])%mod2;
    }

    vector<ll> hash1(n - len + 1), hash2(n - len + 1);

    hash1[0] = rh1, hash2[0] = rh2;
    // slide the window

    for(int i = len; i < n; i++){
        rh1 = (((__int128)((__int128)rh1 - (__int128)arr[i - len]*h1)*p1%mod1 + arr[i])%mod1 + mod1)%mod1;

        rh2 = (((__int128)((__int128)rh2 - (__int128)arr[i - len]*h2)*p2%mod2 + arr[i])%mod2 + mod2)%mod2;

        hash1[i - len + 1] = rh1;
        hash2[i - len + 1] = rh2;
    }

    return make_pair(hash1, hash2);

}

int main(){


    return 0;
}
