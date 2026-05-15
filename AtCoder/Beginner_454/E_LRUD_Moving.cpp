#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int n, a, b; cin >> n >> a >> b;
    
    if(n%2 || (a + b)%2 == 0){
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    /*
    if you color the n*n grid in a checkboard fashion
    (i + j -> odd is white, i + j even is black)
    then for every adjacent move, you must move to a different color

    if N is odd
    0,0 => black
    N,N => black

    so moves must be starting at a black cell
    white, black, white, black, white .... black 
    indicating EVEN no of moves (white, black, white, black)
    but 
    N*N is odd, N*N - 2 is also ODD
    hence if N is odd, this is impossible

    if N is even
    0,0 = N,N = black
    sequence of moves must be
    white, black, white, black, white ... black
    is it always possible to skip 1 and reach N*N?

    if A + B is even => you are skipping a black cell
    else you are skipping white cell
    by obs it can be found that you cannot reach the end by skipping a black cell

    hence conditions :
    N should be even and A+B must be odd

    now constructing the path

    keep doing till we reach the case of a 2*2 grid
    2 cases for a 2*2 grid

    _X
    __
    in this case its DR

    __
    X_
    in this case its RD

    thats it

    from top keep moving right to the end then down, then left again till you reach the row of the target
    then move right, up, right, down till you reach the 2*2 case
    do the same thing from the bottom
    */

    a--, b--;

    int h = n, w = n;

    string top = "", bottom = "";
    while(1){
        if(a >= 2){
            top += string(w - 1, 'R'), top += "D";
            top += string(w - 1, 'L'), top += "D";
            h -= 2, a -= 2;
        }
        else if(h - a > 2){
            bottom += string(w - 1, 'R'), bottom += "D";
            bottom += string(w - 1, 'L'), bottom += "D";
            h -= 2;
        }
        else if(b >= 2){
            top += string(h - 1, 'D'), top += "R";
            top += string(h - 1, 'U'), top += "R";
            w -= 2, b -= 2;
        }
        else if(w - b > 2){
            bottom += string(h - 1, 'D'), bottom += "R";
            bottom += string(h - 1, 'U'), bottom += "R";
            w -= 2;
        }
        else{
            if(a == 0)
                top += "DR";
            else
                top += "RD";
            break;
        }
    }

    reverse(bottom.begin(), bottom.end());

    top += bottom;

    cout << top << nline;

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