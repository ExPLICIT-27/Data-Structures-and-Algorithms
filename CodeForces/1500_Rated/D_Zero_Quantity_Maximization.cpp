#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    /*
    modify the value to
    c = d*a + b
    d*a = b
    d = -b/a

    precision?
    store as num and denominator


    okay need to handle the following cases

    i will store it as
    [num/gcd(num, den), den/gcd(num, den)]

    handle sign

    both -ve, make both +ve
    one of them is -ve, make num -ve

    division by zero, wont encounter if i store as num, den
    */

    int n; cin >> n;

    vector<int> A(n), B(n);

    for(int &i : A)
        cin >> i;
    
    for(int &i : B)
        cin >> i;
    
    map<pair<int, int>, int> mp;

    auto getND = [&](int a, int b) -> pair<int, int> {
        int div = gcd(a, b);
        a /= div, b /= div;

        if(a >= 0 && b >= 0 || a < 0 && b >= 0)
            return make_pair(a, b);
        
        return make_pair(-a, -b);
    };


    for(int i = 0; i < n; i++){

        /*
        if both a and b are zero, i can have any value of x
        0*x = -b
        a*x = 0
        */ 
        if(A[i] == 0 && B[i] == 0){
            mp[{0, 0}]++;
            continue;
        }

        if(A[i] == 0)
            continue; // no sol

        
        mp[getND(-B[i], A[i])]++;
    }

    int adder = (mp.count({0, 0})? mp[{0, 0}] : 0);
    int ans = 0;
    for(auto &[x, y] : mp){
        if(x.first == 0 && x.second == 0)
            continue;
        ans = max(ans, y);
    }

    cout << ans + adder << nline;

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