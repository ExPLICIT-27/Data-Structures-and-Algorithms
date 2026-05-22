#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    ll n, m, k; cin >> n >> m >> k;


    vector<ll> A(n);

    for(ll &i : A)
        cin >> i;
    

    /*
    given a rose of type i, 
    max ans i can have is m


    strategy is to avoid as many gaps as i can
    k is the only issue

    when i run out of roses of a particular type, I NEED to put a gap
    and I NEED to put a gap after k roses as well?

    no of gaps i need

    (k + 1)*x >= m
    x >= m/(k + 1)
    */

    ll gaps = m/(k + 1);

    // best case ans = m - gaps

    // gaps will come due to flower type
    
    /*
    what is the optimal placing for these flowers
    */

    // first calc how many flowers off the bat i can put

    ll ans = 0;
    // how many have i planted
    ll tmp = m;
    for(ll &i : A){
        ll secs = i/k;

        ll planted = k*secs;
        ll area = (k + 1)*secs;
        ans += planted;
        i -= planted;
        tmp -= area;
    }

    if(tmp <= 0){
        cout << min(ans, m - gaps) << nline;
        return;
    }
    // i have made it as perfect as it can be
    // now all are less than k
    
    sort(A.begin(), A.end(), greater<ll>());

    for(ll i : A){
        if(tmp < i){
            ans += tmp;
            break;
        }
        ans += i;
        tmp -= (i + 1);
        if(tmp <= 0)
            break;
    } 

    cout << min(ans, m - gaps) << nline;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}