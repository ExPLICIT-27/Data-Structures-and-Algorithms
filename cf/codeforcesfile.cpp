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
        vector<long long> arr(n);
        long long prod = 1;
        int zcount = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] == 0){
                zcount++;
                continue;
            }
            prod *= arr[i];
        }
        if(zcount > 1){
            cout << 0 << endl;
            continue;
        }
        if(zcount == 1){
            cout << prod << endl;
            continue;
        }
        long long result = prod;
        for(int i : arr){
            result = max(result, (prod/i)*(i + 1));
        }
        cout << result << endl;

    }
    return 0;

}