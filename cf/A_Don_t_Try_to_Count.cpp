#include <bits/stdc++.h>
/*
4 7
3^n(a) - 2^n(b) >= 0
2^n(na - b) = 1
1 
*/
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;
        if(x.find(s) != string::npos){
            cout << 0 << endl;
            continue;
        }
        int result = 1;
        x += x;
        if(x.find(s) != string::npos){
            cout << 1 << endl;
            continue;
        }
        for(; x.length() <= s.length();){
            result++;
            x += x;
            if(x.find(s) != string::npos)
                break;
        }
        if(x.find(s) == string::npos){
            result++;
            x += x;
        }
        if(x.find(s) == string::npos)
            cout << -1 << endl;
        else
            cout << result << endl;

    }
    return 0;

}