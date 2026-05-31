#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int n, q; cin >> n >> q;


    vector<int> A(n, 0);

    /*
    inc size of block
    there will always be empty blocks every time

    when everybody has blocks, only max and min freq are disturbed

    basically once everyone has at least 1, freq of 1 => 0
    freq of max = 0

    im playing tetris

    A[x]++;
    if every A[x] is set, then glob freq - 1

    now just keep track of F >= 'x'
    */
    map<int, int> F;

    F[0] = n;

    // just F[x]

    int cmax = 0;
    while(q--){
        int qi, i; cin >> qi >> i;
        
        if(qi == 1){
            i--;
            A[i]++;
            F[A[i]]++;

            if(F[A[i]] >= n)
                cmax = max(cmax, A[i]);
        }
        else{
            // query ans is F[i + min_freq]

            cout << F[i + cmax] << nline;
        }
    }

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