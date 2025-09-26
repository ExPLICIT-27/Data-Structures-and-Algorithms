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
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int result = arr[0];
        for(int i = 1; i < n; i++)
            result = max(result, arr[i] - arr[i - 1]);
        result = max(result, 2*(x - arr.back()));

        cout << result << endl;
    }
    return 0;

}