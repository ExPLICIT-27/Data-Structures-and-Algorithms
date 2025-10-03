#include <bits/stdc++.h>
/*
4 7
3^n(a) - 2^n(b) >= 0
2^n(na - b) = 1

*/
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string str;
        cin >> str;
        int result = 0;
        int i = 0;
        while(i < n){
            if(str[i] == '.'){
                int st = i;
                while(i < n && str[i] == '.')
                    i++;
                result += min(2, i - st);
                if(i - st > 2){
                    result = 2;
                    break;
                }
            }
            else
                i++;
        }
        cout << result << endl;
    }
    return 0;

}