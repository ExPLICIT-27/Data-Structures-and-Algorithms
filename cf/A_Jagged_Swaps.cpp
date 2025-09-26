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
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        if(arr[0] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;

}