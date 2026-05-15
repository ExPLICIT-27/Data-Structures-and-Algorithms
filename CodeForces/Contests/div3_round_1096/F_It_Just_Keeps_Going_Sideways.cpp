#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    /*
    I need to figure out two things
    1 -> how much will each block move
    2 -> how will deleting a block affect the total change


    At each height each, the cubes behave independently

    okay 
    so 1 array to cnt how many blocks are there with height h
    another array to sum up their index values
    then movement would be
    indexsum - cnt[h]*(cnt[h] + 1)/2
    */

    int n; cin >> n;
    
    vector<int> A(n);

    for(int &i : A)
        cin >> i;
    

    vector<ll> cnt(n + 2, 0), isum(n + 2, 0);

    for(int i = n - 1; i >= 0; i--){
        int pos = n - i - 1;

        cnt[1]++;
        cnt[A[i] + 1]--;
        isum[1] += pos;
        isum[A[i] + 1] -= pos;
    }

    for(int i = 1; i < n + 2; i++){
        cnt[i] += cnt[i - 1];
        isum[i] += isum[i - 1];
    }

    // okay movement and no of ppl moving is done
    ll og = 0;

    for(int i = 1; i < n + 2; i++){
        if(!cnt[i])
            continue;
        og += (isum[i] - cnt[i]*(cnt[i] - 1)/2);
    }
    

    // now how does the value of og change i remove a particular cube the top most basically of any column
    // the cnt[h] decreases by 1, isum[h] decreases by that index value
    // i recalculate the value for height h basically


    ll ans = og;
    for(int i = n - 1; i >= 0; i--){
        int pos = n - i - 1, h = A[i];

        if(cnt[h] - 1 <= 0)
            continue;
        ll tmp = og;
        tmp -= (isum[h] - cnt[h]*(cnt[h] - 1)/2);

        cnt[h]--;
        isum[h] -= pos;

        tmp += (isum[h] - cnt[h]*(cnt[h] - 1)/2);

        ans = max(ans, tmp);
    }

    cout << ans << nline;
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